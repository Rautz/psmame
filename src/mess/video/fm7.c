/*
 *
 *  Fujitsu Micro 7 Video functions
 *
 */

#include "emu.h"
#include "cpu/m6809/m6809.h"
#include "includes/fm7.h"


/*
 * Main CPU: Sub-CPU interface (port 0xfd05)
 *
 * Read:
 *   bit 7: Sub-CPU busy (or halted)
 *   bit 0: EXTDET (?)
 * Write:
 *   bit 7: Sub-CPU halt
 *   bit 6: Sub-CPU cancel IRQ
 */

READ8_HANDLER( fm7_subintf_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8 ret = 0x00;

	if(state->m_video.sub_busy != 0 || state->m_video.sub_halt != 0)
		ret |= 0x80;

	ret |= 0x7e;
	//ret |= 0x01; // EXTDET (not implemented yet)

	return ret;
}

WRITE8_HANDLER( fm7_subintf_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.sub_halt = data & 0x80;
	if(data & 0x80)
		state->m_video.sub_busy = data & 0x80;

	cputag_set_input_line(space->machine(),"sub",INPUT_LINE_HALT,(data & 0x80) ? ASSERT_LINE : CLEAR_LINE);
	if(data & 0x40)
		cputag_set_input_line(space->machine(),"sub",M6809_IRQ_LINE,ASSERT_LINE);
	//popmessage("Sub CPU Interface write: %02x\n",data);
}

READ8_HANDLER( fm7_sub_busyflag_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(state->m_video.sub_halt == 0)
		state->m_video.sub_busy = 0x00;
	return 0x00;
}

WRITE8_HANDLER( fm7_sub_busyflag_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.sub_busy = 0x80;
}

/*
 * Sub-CPU port 0xd402
 *   Read-only: Acknowledge Cancel IRQ
 */
READ8_HANDLER( fm7_cancel_ack )
{
	cputag_set_input_line(space->machine(),"sub",M6809_IRQ_LINE,CLEAR_LINE);
	return 0x00;
}

/*
 * Reading from 0xd404 (sub-CPU) causes an "Attention" FIRQ on the main CPU
 */
READ8_HANDLER( fm7_attn_irq_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.attn_irq = 1;
	cputag_set_input_line(space->machine(),"maincpu",M6809_FIRQ_LINE,ASSERT_LINE);
	return 0xff;
}

/*
 *  Sub CPU: I/O port 0xd409
 *
 *  On read, enables VRAM access
 *  On write, disables VRAM access
 */
READ8_HANDLER( fm7_vram_access_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.vram_access = 1;
	return 0xff;
}

WRITE8_HANDLER( fm7_vram_access_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.vram_access = 0;
}

static TIMER_CALLBACK( fm77av_alu_task_end )
{
	fm7_state *state = machine.driver_data<fm7_state>();
	state->m_alu.busy = 0;
}

static void fm7_alu_mask_write(fm7_state *state, UINT32 offset, int bank, UINT8 dat)
{
	UINT8 temp;
	int page = 0;

	if(offset >= 0xc000)
		page = 1;

	if((state->m_alu.command & 0x40) == 0)
	{  // "always" write mode
		state->m_video_ram[(offset & 0x3fff) + (bank * 0x4000) + (page * 0xc000)] = dat;
		return;
	}

	temp = state->m_video_ram[(offset & 0x3fff) + (bank * 0x4000) + (page * 0xc000)];
	if(state->m_alu.command & 0x20)
	{  // "not equal" write mode
		temp &= state->m_alu.compare_data;
		dat &= ~state->m_alu.compare_data;
	}
	else
	{  // "equal" write mode
		temp &= ~state->m_alu.compare_data;
		dat &= state->m_alu.compare_data;
	}

	state->m_video_ram[(offset & 0x3fff) + (bank * 0x4000) + (page * 0xc000)] = temp | dat;
}

static void fm7_alu_function_compare(fm7_state *state, UINT32 offset)
{
	// COMPARE - compares which colors match those in the compare registers
	// can be used on its own, or when bit 6 of the command register is high.

	UINT8 red,green,blue;
	UINT8 dat = 0;
	UINT8 colour;
	UINT8 banks;
	int x,y;
	int match;
	int page = 0;
	UINT8 bit = 0x80;

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	blue = state->m_video_ram[(offset & 0x3fff) + (page * 0xc000)];
	red = state->m_video_ram[(offset & 0x3fff) + 0x4000 + (page * 0xc000)];
	green = state->m_video_ram[(offset & 0x3fff) + 0x8000 + (page * 0xc000)];

	banks = (~state->m_alu.bank_disable) & 0x07;

	for(x=0;x<8;x++) // loop through each pixel
	{
		colour = 0;
		if(blue & bit)
			colour |= 1;
		if(red & bit)
			colour |= 2;
		if(green & bit)
			colour |= 4;

		match = 0;
		for(y=0;y<8;y++)  // loop through each compare register
		{
			if(!(state->m_alu.compare[y] & 0x80)) // don't compare if register is masked
			{
				if((state->m_alu.compare[y] & banks) == (colour & banks))
					match = 1;
			}
		}
		if(match != 0)
			dat |= bit;

		bit >>= 1;
	}
	state->m_alu.compare_data = dat;
}

static void fm7_alu_function_pset(fm7_state *state, UINT32 offset)
{
	// PSET - simply sets the pixels to the selected logical colour
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			if(state->m_alu.lcolour & (1 << x))
				dat = 0xff;
			else
				dat = 0;

			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]) & state->m_alu.mask;
			dat &= ~state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_or(fm7_state *state, UINT32 offset)
{
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			if(state->m_alu.lcolour & (1 << x))
				dat = 0xff;
			else
				dat = 0;

			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]);
			dat |= mask;

			mask &= state->m_alu.mask;
			dat &= ~state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_and(fm7_state *state, UINT32 offset)
{
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			if(state->m_alu.lcolour & (1 << x))
				dat = 0xff;
			else
				dat = 0;

			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]);
			dat &= mask;

			mask &= state->m_alu.mask;
			dat &= ~state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_xor(fm7_state *state, UINT32 offset)
{
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			if(state->m_alu.lcolour & (1 << x))
				dat = 0xff;
			else
				dat = 0;

			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]);
			dat ^= mask;

			mask &= state->m_alu.mask;
			dat &= ~state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_not(fm7_state *state, UINT32 offset)
{
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			if(state->m_alu.lcolour & (1 << x))
				dat = 0xff;
			else
				dat = 0;

			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]);
			dat = ~mask;

			mask &= state->m_alu.mask;
			dat &= ~state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_invalid(fm7_state *state, UINT32 offset)
{
	// Invalid function, still does something though (used by Laydock)
	int x;
	UINT8 dat;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]);

			dat = mask & state->m_alu.mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function_tilepaint(fm7_state *state, UINT32 offset)
{
	// TILEPAINT - writes to VRAM based on the tilepaint colour registers
	int x;
	UINT8 dat = 0;
	int page = 0;
	UINT8 mask;

	if(state->m_alu.command & 0x40)
		fm7_alu_function_compare(state, offset);

	if(offset >= 0xc000)
	{
		page = 1;
		offset += state->m_video.vram_offset2;
	}
	else
		offset += state->m_video.vram_offset;

	for(x=0;x<3;x++) // cycle through banks
	{
		if(!(state->m_alu.bank_disable & (1 << x)))
		{
			switch(x)
			{
				case 0:
					dat = state->m_alu.tilepaint_b;
					break;
				case 1:
					dat = state->m_alu.tilepaint_r;
					break;
				case 2:
					dat = state->m_alu.tilepaint_g;
					break;
			}
			dat &= ~state->m_alu.mask;
			mask = (state->m_video_ram[(offset & 0x3fff) + (x * 0x4000) + (page * 0xc000)]) & state->m_alu.mask;
			dat |= mask;

			fm7_alu_mask_write(state, offset,x,dat);
		}
	}
}

static void fm7_alu_function(fm7_state *state, UINT32 offset)
{
	switch(state->m_alu.command & 0x07)
	{
		case 0x00: // PSET
			fm7_alu_function_pset(state, offset);
			break;
		case 0x02: // OR
			fm7_alu_function_or(state, offset);
			break;
		case 0x03: // AND
			fm7_alu_function_and(state, offset);
			break;
		case 0x04: // XOR
			fm7_alu_function_xor(state, offset);
			break;
		case 0x05: // NOT
			fm7_alu_function_not(state, offset);
			break;
		case 0x06: // TILEPAINT
			fm7_alu_function_tilepaint(state, offset);
			break;
		case 0x07: // COMPARE
			fm7_alu_function_compare(state, offset);
			break;
		case 0x01:
		default:
			fm7_alu_function_invalid(state, offset);
	}
}

static UINT32 fm7_line_set_pixel(fm7_state *state, int x, int y)
{
	UINT32 addr;
	static const UINT8 pixel_mask[8] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe };


	if(state->m_video.modestatus & 0x40) // 320 pixels wide
	{
		addr = (x >> 3) + (y * 40);
	}
	else  // 640 pixels wide
	{
		addr = (x >> 3) + (y * 80);
	}
	addr += (state->m_alu.addr_offset << 1);
	addr &= 0x3fff;
	if(state->m_video.active_video_page != 0)
		addr += 0xc000;

	if(state->m_alu.command & 0x80)  // ALU must be active
	{
		state->m_alu.mask = pixel_mask[x & 0x07];
		fm7_alu_function(state, addr);
	}

	return addr;
}

static void fm77av_line_draw(running_machine &machine)
{
	fm7_state *state = machine.driver_data<fm7_state>();
	int x1 = state->m_alu.x0;
	int x2 = state->m_alu.x1;
	int y1 = state->m_alu.y0;
	int y2 = state->m_alu.y1;
	int horiz,vert;
	int dirx,diry;
	int rep;
	int byte_count = 0;
	UINT16 old_addr = 0xffff;
	UINT16 addr;

	state->m_alu.busy = 1;

	horiz = x2 - x1;
	vert = y2 - y1;

	if(horiz < 0)
	{
		dirx = -1;
		horiz = -horiz;
	}
	else
		dirx = 1;
	if(vert < 0)
	{
		diry = -1;
		vert = -vert;
	}
	else
		diry = 1;

	if(horiz == 0 && vert == 0)
	{
		fm7_line_set_pixel(state, x1, y1);
		byte_count = 1;
	}
	else if(horiz == 0)
	{
		for(;;)
		{
			addr = fm7_line_set_pixel(state, x1, y1);
			if(addr != old_addr)
			{
				byte_count++;
				old_addr = addr;
			}
			if(y1 == y2)
				break;
			y1 += diry;
		}
	}
	else if(vert == 0)
	{
		for(;;)
		{
			addr = fm7_line_set_pixel(state, x1, y1);
			if(addr != old_addr)
			{
				byte_count++;
				old_addr = addr;
			}
			if(x1 == x2)
				break;
			x1 += dirx;
		}
	}
	else if(horiz >= vert)
	{
		rep = horiz >> 1;
		for(;;)
		{
			addr = fm7_line_set_pixel(state, x1, y1);
			if(addr != old_addr)
			{
				byte_count++;
				old_addr = addr;
			}
			if(x1 == x2)
				break;
			x1 += dirx;
			rep -= vert;
			if(rep < 0)
			{
				rep += horiz;
				y1 += diry;
			}
		}
	}
	else
	{
		rep = vert >> 1;
		for(;;)
		{
			addr = fm7_line_set_pixel(state, x1, y1);
			if(addr != old_addr)
			{
				byte_count++;
				old_addr = addr;
			}
			if(y1 == y2)
				break;
			y1 += diry;
			rep -= horiz;
			if(rep < 0)
			{
				rep += vert;
				x1 += dirx;
			}
		}
	}

	// set timer to disable busy flag
	// 1/16 us for each byte changed
	machine.scheduler().timer_set(attotime::from_usec(byte_count/16), FUNC(fm77av_alu_task_end));
}

READ8_HANDLER( fm7_vram_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	int offs;
	UINT16 page = 0x0000;

	if(state->m_video.active_video_page != 0)
		page = 0xc000;

	if(offset < 0x4000 && (state->m_video.multi_page & 0x01))
		return 0xff;
	if((offset < 0x8000 && offset >=0x4000) && (state->m_video.multi_page & 0x02))
		return 0xff;
	if((offset < 0xc000 && offset >=0x8000) && (state->m_video.multi_page & 0x04))
		return 0xff;

	if(state->m_alu.command & 0x80) // ALU active, writes to VRAM even when reading it (go figure)
	{
		fm7_alu_function(state, offset+page);
	}

	if(state->m_video.modestatus & 0x40)
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset2) & 0x1fff);
		else
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset) & 0x1fff);
	}
	else
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset2) & 0x3fff);
		else
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset) & 0x3fff);
	}
	return state->m_video_ram[offs + page];
}

WRITE8_HANDLER( fm7_vram_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	int offs;
	UINT16 page = 0x0000;

	if(state->m_video.active_video_page != 0)
		page = 0xc000;

	if(offset < 0x4000 && (state->m_video.multi_page & 0x01))
		return;
	if((offset < 0x8000 && offset >=0x4000) && (state->m_video.multi_page & 0x02))
		return;
	if((offset < 0xc000 && offset >=0x8000) && (state->m_video.multi_page & 0x04))
		return;

	if(state->m_alu.command & 0x80) // ALU active
	{
		fm7_alu_function(state, offset+page);
		return;
	}

	if(state->m_video.modestatus & 0x40)
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset2) & 0x1fff);
		else
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset) & 0x1fff);
	}
	else
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset2) & 0x3fff);
		else
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset) & 0x3fff);
	}
//  if(state->m_video.vram_access != 0)
		state->m_video_ram[offs+page] = data;
}

// not pretty, but it should work.
static WRITE8_HANDLER( fm7_vram_banked_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	int offs;
	UINT16 page = 0x0000;

	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return;

	if(state->m_video.active_video_page != 0)
		page = 0xc000;

	if(offset < 0x4000 && (state->m_video.multi_page & 0x01))
		return;
	if((offset < 0x8000 && offset >=0x4000) && (state->m_video.multi_page & 0x02))
		return;
	if((offset < 0xc000 && offset >=0x8000) && (state->m_video.multi_page & 0x04))
		return;

	if(state->m_alu.command & 0x80) // ALU active
	{
		fm7_alu_function(state, offset+page);
		return;
	}

	if(state->m_video.modestatus & 0x40)
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset2) & 0x1fff);
		else
			offs = (offset & 0xe000) | ((offset + state->m_video.vram_offset) & 0x1fff);
	}
	else
	{
		if(state->m_video.active_video_page != 0)
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset2) & 0x3fff);
		else
			offs = (offset & 0xc000) | ((offset + state->m_video.vram_offset) & 0x3fff);
	}
	state->m_video_ram[offs+page] = data;
}

READ8_HANDLER( fm7_vram0_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset);
}

READ8_HANDLER( fm7_vram1_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x1000);
}

READ8_HANDLER( fm7_vram2_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x2000);
}

READ8_HANDLER( fm7_vram3_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x3000);
}

READ8_HANDLER( fm7_vram4_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x4000);
}

READ8_HANDLER( fm7_vram5_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x5000);
}

READ8_HANDLER( fm7_vram6_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x6000);
}

READ8_HANDLER( fm7_vram7_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x7000);
}

READ8_HANDLER( fm7_vram8_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x8000);
}

READ8_HANDLER( fm7_vram9_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0x9000);
}

READ8_HANDLER( fm7_vramA_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0xa000);
}

READ8_HANDLER( fm7_vramB_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	if(!state->m_video.sub_halt)  // no access if sub CPU is not halted.
		return 0xff;
	return fm7_vram_r(space,offset+0xb000);
}

WRITE8_HANDLER( fm7_vram0_w )
{
	fm7_vram_banked_w(space,offset,data);
}

WRITE8_HANDLER( fm7_vram1_w )
{
	fm7_vram_banked_w(space,offset+0x1000,data);
}

WRITE8_HANDLER( fm7_vram2_w )
{
	fm7_vram_banked_w(space,offset+0x2000,data);
}

WRITE8_HANDLER( fm7_vram3_w )
{
	fm7_vram_banked_w(space,offset+0x3000,data);
}

WRITE8_HANDLER( fm7_vram4_w )
{
	fm7_vram_banked_w(space,offset+0x4000,data);
}

WRITE8_HANDLER( fm7_vram5_w )
{
	fm7_vram_banked_w(space,offset+0x5000,data);
}

WRITE8_HANDLER( fm7_vram6_w )
{
	fm7_vram_banked_w(space,offset+0x6000,data);
}

WRITE8_HANDLER( fm7_vram7_w )
{
	fm7_vram_banked_w(space,offset+0x7000,data);
}

WRITE8_HANDLER( fm7_vram8_w )
{
	fm7_vram_banked_w(space,offset+0x8000,data);
}

WRITE8_HANDLER( fm7_vram9_w )
{
	fm7_vram_banked_w(space,offset+0x9000,data);
}

WRITE8_HANDLER( fm7_vramA_w )
{
	fm7_vram_banked_w(space,offset+0xa000,data);
}

WRITE8_HANDLER( fm7_vramB_w )
{
	fm7_vram_banked_w(space,offset+0xb000,data);
}

/*
 *  Sub CPU: I/O port 0xd408
 *
 *  On read, enables the CRT display
 *  On write, disables the CRT display
 */
READ8_HANDLER( fm7_crt_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.crt_enable = 1;
	return 0xff;
}

WRITE8_HANDLER( fm7_crt_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.crt_enable = 0;
}

/*
 *  Sub CPU: I/O ports 0xd40e - 0xd40f
 *
 *  0xd40e: bits 0-6 - offset in bytes (high byte) (bit 6 is used for 400 line video only)
 *  0xd40f: bits 0-7 - offset in bytes (low byte)
 */
WRITE8_HANDLER( fm7_vram_offset_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT16 new_offset = 0;

	switch(offset)
	{
		case 0:
			if(state->m_video.active_video_page != 0)
				new_offset = ((data & 0x3f) << 8) | (state->m_video.vram_offset2 & 0x00ff);
			else
				new_offset = ((data & 0x3f) << 8) | (state->m_video.vram_offset & 0x00ff);
			break;
		case 1:  // low 5 bits are used on FM-77AV and later only
			if(state->m_type == SYS_FM7)
				new_offset = (state->m_video.vram_offset & 0xff00) | (data & 0xe0);
			else
			{
				if(state->m_video.active_video_page != 0)
				{
					if(state->m_video.fine_offset != 0)
						new_offset = (state->m_video.vram_offset2 & 0xff00) | (data & 0xff);
					else
						new_offset = (state->m_video.vram_offset2 & 0xff00) | (data & 0xe0);
				}
				else
				{
					if(state->m_video.fine_offset != 0)
						new_offset = (state->m_video.vram_offset & 0xff00) | (data & 0xff);
					else
						new_offset = (state->m_video.vram_offset & 0xff00) | (data & 0xe0);
				}
			}
			break;
	}
	if(state->m_video.active_video_page != 0)
		state->m_video.vram_offset2 = new_offset;
	else
		state->m_video.vram_offset = new_offset;
}

/*
 *  Main CPU: port 0xfd37
 *  Multipage
 *  Port is write-only
 *
 *  bits 6-4: VRAM planes to display (G,R,B) (1=disable)
 *  bits 2-0: VRAM CPU access (G,R,B) (1=disable)
 */
WRITE8_HANDLER( fm7_multipage_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	state->m_video.multi_page = data & 0x77;
}

/*
 *  Main CPU: I/O ports 0xfd38-0xfd3f
 *  Colour palette.
 *  Each port represents one of eight colours.  Palette is 3-bit.
 *  bit 2 = Green
 *  bit 1 = Red
 *  bit 0 = Blue
 */
READ8_HANDLER( fm7_palette_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	return state->m_video.fm7_pal[offset];
}

WRITE8_HANDLER( fm7_palette_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8 r = 0,g = 0,b = 0;

	if(data & 0x04)
		g = 0xff;
	if(data & 0x02)
		r = 0xff;
	if(data & 0x01)
		b = 0xff;

	palette_set_color(space->machine(),offset,MAKE_RGB(r,g,b));
	state->m_video.fm7_pal[offset] = data & 0x07;
}

/*
 *  Main CPU: 0xfd30 - 0xfd34
 *  Analog colour palette (FM-77AV and later only)
 *  All ports are write-only.
 *
 *  fd30: colour select(?) high 4 bits (LC11-LC8)
 *  fd31: colour select(?) low 8 bits (LC7-LC0)
 *  fd32: blue level (4 bits)
 *  fd33: red level (4 bits)
 *  fd34: green level (4 bits)
 */
WRITE8_HANDLER( fm77av_analog_palette_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	int val;

	switch(offset)
	{
		case 0:
			val = ((data & 0x0f) << 8) | (state->m_video.fm77av_pal_selected & 0x00ff);
			state->m_video.fm77av_pal_selected = val;
			break;
		case 1:
			val = data | (state->m_video.fm77av_pal_selected & 0x0f00);
			state->m_video.fm77av_pal_selected = val;
			break;
		case 2:
			state->m_video.fm77av_pal_b[state->m_video.fm77av_pal_selected] = (data & 0x0f) << 4;
			palette_set_color(space->machine(),state->m_video.fm77av_pal_selected+8,
				MAKE_RGB(state->m_video.fm77av_pal_r[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_g[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_b[state->m_video.fm77av_pal_selected]));
			break;
		case 3:
			state->m_video.fm77av_pal_r[state->m_video.fm77av_pal_selected] = (data & 0x0f) << 4;
			palette_set_color(space->machine(),state->m_video.fm77av_pal_selected+8,
				MAKE_RGB(state->m_video.fm77av_pal_r[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_g[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_b[state->m_video.fm77av_pal_selected]));
			break;
		case 4:
			state->m_video.fm77av_pal_g[state->m_video.fm77av_pal_selected] = (data & 0x0f) << 4;
			palette_set_color(space->machine(),state->m_video.fm77av_pal_selected+8,
				MAKE_RGB(state->m_video.fm77av_pal_r[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_g[state->m_video.fm77av_pal_selected],
				state->m_video.fm77av_pal_b[state->m_video.fm77av_pal_selected]));
			break;
	}
}


/*
 *   Sub CPU: 0xd430 - BUSY/NMI/Bank register (FM77AV series only)
 *
 *   On read:  bit 7 - 0 if in VBlank
 *             bit 4 - ALU busy(0)/ready(1)
 *             bit 2 - VSync status (1 if active?)
 *             bit 0 - RESET
 *
 *   On write: bits 1-0 - CGROM select (maps to 0xd800)
 *             bit 2 - fine offset enable (enables OA4-OA0 bits in VRAM offset)
 *             bit 5 - active VRAM page
 *             bit 6 - display VRAM page
 *             bit 7 - NMI mask register (1=mask)
 */
READ8_HANDLER( fm77av_video_flags_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8 ret = 0xff;

	if(space->machine().primary_screen->vblank())
		ret &= ~0x80;

	if(state->m_alu.busy != 0)
		ret &= ~0x10;

	if(state->m_video.vsync_flag == 0)
		ret &= ~0x04;

	if(!state->m_video.sub_reset)
		ret &= ~0x01;

	return ret;
}

WRITE8_HANDLER( fm77av_video_flags_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8* RAM = space->machine().region("subsyscg")->base();

	state->m_video.cgrom = data & 0x03;
	memory_set_bankptr(space->machine(),"bank20",RAM+(state->m_video.cgrom*0x800));
	state->m_video.fine_offset = data & 0x04;
	state->m_video.active_video_page = data & 0x20;
	state->m_video.display_video_page = data & 0x40;
	state->m_video.nmi_mask = data & 0x80;
}

/*
 *  Main CPU: port 0xfd12
 *  Sub mode status register  (FM-77AV or later)
 *  bit 6 (R/W) - Video mode width(?) 0=640 (default) 1=320.
 *  bit 1 (R/O) - DISPTMG status (0=blank)
 *  bit 0 (R/O) - VSync status (1=sync?)
 */
READ8_HANDLER( fm77av_sub_modestatus_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8 ret = 0x00;

	ret |= 0xbc;
	ret |= (state->m_video.modestatus & 0x40);

	if(!space->machine().primary_screen->vblank())
		ret |= 0x02;

	if(state->m_video.vsync_flag != 0)
		ret |= 0x01;

	return ret;
}

WRITE8_HANDLER( fm77av_sub_modestatus_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	rectangle rect;
	state->m_video.modestatus = data & 0x40;
	if(data & 0x40)
	{
		rect.min_x = rect.min_y = 0;
		rect.max_x = 320-1;
		rect.max_y = 200-1;
		space->machine().primary_screen->configure(320,200,rect,HZ_TO_ATTOSECONDS(60));
	}
	else
	{
		rect.min_x = rect.min_y = 0;
		rect.max_x = 640-1;
		rect.max_y = 200-1;
		space->machine().primary_screen->configure(640,200,rect,HZ_TO_ATTOSECONDS(60));
	}
}

/*
 *  Main CPU: port 0xfd13
 *  Sub Bank select register
 *
 *  bits 1 and 0 select which subsys ROM to be banked into sub CPU space
 *  on the FM-77AV40 and later, bit 2 can also selected to bank in sub monitor RAM.
 */
WRITE8_HANDLER( fm77av_sub_bank_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
//  UINT8* RAM = space->machine().region("sub")->base();
	UINT8* ROM;

	if((data & 0x03) == (state->m_sb_prev & 0x03))
		return;

	state->m_video.subrom = data & 0x03;
	switch (data & 0x03)
	{
		case 0x00:  // Type C, 640x200 (as used on the FM-7)
			ROM = space->machine().region("subsys_c")->base();
		//  memory_set_bankptr(space->machine(),20,ROM);
			memory_set_bankptr(space->machine(),"bank21",ROM+0x800);
			logerror("VID: Sub ROM Type C selected\n");
			break;
		case 0x01:  // Type A, 640x200
			ROM = space->machine().region("subsys_a")->base();
		//  memory_set_bankptr(space->machine(),20,RAM+0xd800);
			memory_set_bankptr(space->machine(),"bank21",ROM);
			logerror("VID: Sub ROM Type A selected\n");
			break;
		case 0x02:  // Type B, 320x200
			ROM = space->machine().region("subsys_b")->base();
		//  memory_set_bankptr(space->machine(),20,RAM+0xd800);
			memory_set_bankptr(space->machine(),"bank21",ROM);
			logerror("VID: Sub ROM Type B selected\n");
			break;
		case 0x03:  // CG Font?
			ROM = space->machine().region("subsyscg")->base();
		//  memory_set_bankptr(space->machine(),20,RAM+0xd800);
			memory_set_bankptr(space->machine(),"bank21",ROM);
			logerror("VID: Sub ROM CG selected\n");
			break;
	}
	// reset sub CPU, set busy flag, set reset flag
	cputag_set_input_line(space->machine(),"sub",INPUT_LINE_RESET,PULSE_LINE);
	state->m_video.sub_busy = 0x80;
	state->m_video.sub_halt = 0;
	state->m_video.sub_reset = 1;
	state->m_sb_prev = data;
}

/*
 *  Sub CPU: ports 0xd410-0xd42b (FM-77AV and later only)
 *  Video operations
 *
 *  0xd410 (R/W): Command register
 *                bit 7: 0=DIS 1=Start
 *                bits 6-5: MBIT1, MBIT2
 *                bits 2-0: Draw mode
 *                  0 0 0 - PSET
 *                  0 1 0 - OR
 *                  0 1 1 - AND
 *                  1 0 0 - XOR
 *                  1 0 1 - NOT
 *                  1 1 0 - TILEPAINT
 *                  1 1 1 - COMPARE
 *  0xd411 (R/W): Logical colour (bits 2-0, G-R-B)
 *  0xd412 (R/W): Mask register
 *  0xd413 (R)  : Compare data (?)
 *  0xd413-1a(W): Compare registers (bits 2-0, G-R-B, 1=mask (bit 7))
 *  0xd41b (R/W): Bank disable register (bits 2-0, G-R-B, 1=disable, bit 3 must always be 1)
 *  0xd41c-1e(W): Tilepaint registers (B-R-G)
 *  0xd420-21(W): Line Address offset register (High-Low, A13-A1)
 *  0xd422-23(W): Line style pattern register (High-Low, P15-P0)
 *  0xd424-25(W): Line X0 (High-Low, X9-X0)
 *  0xd426-27(W): Line Y0 (High-Low, Y8-Y0)
 *  0xd428-29(W): Line X1 (High-Low, X9-X0)
 *  0xd42a-2b(W): Line Y1 (High-Low, Y8-Y0)
 */
READ8_HANDLER( fm77av_alu_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	switch(offset)
	{
		case 0x00:
			logerror("ALU: read from command register (%02x)\n",state->m_alu.command);
			return state->m_alu.command;
		case 0x01:
			logerror("ALU: read from logical colour\n");
			return state->m_alu.lcolour;
		case 0x02:
			logerror("ALU: read from mask register\n");
			return state->m_alu.mask;
		case 0x03:
			logerror("ALU: read from compare data register (%02x)\n",state->m_alu.compare_data);
			return state->m_alu.compare_data;
		case 0x0b:
			logerror("ALU: read from bank disable register\n");
			return 0xf7 | state->m_alu.bank_disable;
		default:
			logerror("ALU: read from invalid register 0x%02x\n",offset);
			return 0xff;
	}
	return 0xff;
}

WRITE8_HANDLER( fm77av_alu_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT16 dat;

	switch(offset)
	{
		case 0x00:
			state->m_alu.command = data;
			logerror("ALU: write to command register - %02x\n",data);
			break;
		case 0x01:
			state->m_alu.lcolour = data & 0x07;
			logerror("ALU: write to logical colour - %02x\n",data);
			break;
		case 0x02:
			state->m_alu.mask = data;
			logerror("ALU: write to mask register - %02x\n",data);
			break;
		case 0x03:
		case 0x04:
		case 0x05:
		case 0x06:
		case 0x07:
		case 0x08:
		case 0x09:
		case 0x0a:
			state->m_alu.compare[offset-3] = data;
			logerror("ALU: write to compare register %i - %02x\n",offset-3,data);
			break;
		case 0x0b:
			state->m_alu.bank_disable = data & 0x03;
//          logerror("ALU: write to bank disable register - %02x\n",data);
			break;
		case 0x0c:
			state->m_alu.tilepaint_b = data;
//          logerror("ALU: write to tilepaint (blue) register - %02x\n",data);
			break;
		case 0x0d:
			state->m_alu.tilepaint_r = data;
//          logerror("ALU: write to tilepaint (red) register - %02x\n",data);
			break;
		case 0x0e:
			state->m_alu.tilepaint_g = data;
//          logerror("ALU: write to tilepaint (green) register - %02x\n",data);
			break;
		case 0x10:
			dat = ((data & 0x1f) << 8) | (state->m_alu.addr_offset & 0x00ff);
			state->m_alu.addr_offset = dat;
//          logerror("ALU: write to address offset (high) register - %02x (%04x)\n",data,state->m_alu.addr_offset);
			break;
		case 0x11:
			dat = (state->m_alu.addr_offset & 0xff00) | data;
			state->m_alu.addr_offset = dat;
//          logerror("ALU: write to address offset (low) register - %02x (%04x)\n",data,state->m_alu.addr_offset);
			break;
		case 0x12:
			dat = (data << 8) | (state->m_alu.line_style & 0x00ff);
			state->m_alu.line_style = dat;
//          logerror("ALU: write to line style (high) register - %02x (%04x)\n",data,state->m_alu.line_style);
			break;
		case 0x13:
			dat = (state->m_alu.line_style & 0xff00) | data;
			state->m_alu.line_style = dat;
//          logerror("ALU: write to line style (low) register - %02x (%04x)\n",data,state->m_alu.line_style);
			break;
		case 0x14:
			dat = ((data & 0x03) << 8) | (state->m_alu.x0 & 0x00ff);
			state->m_alu.x0 = dat;
//          logerror("ALU: write to X0 (high) register - %02x (%04x)\n",data,state->m_alu.x0);
			break;
		case 0x15:
			dat = (state->m_alu.x0 & 0xff00) | data;
			state->m_alu.x0 = dat;
//          logerror("ALU: write to X0 (low) register - %02x (%04x)\n",data,state->m_alu.x0);
			break;
		case 0x16:
			dat = ((data & 0x01) << 8) | (state->m_alu.y0 & 0x00ff);
			state->m_alu.y0 = dat;
//          logerror("ALU: write to Y0 (high) register - %02x (%04x)\n",data,state->m_alu.y0);
			break;
		case 0x17:
			dat = (state->m_alu.y0 & 0xff00) | data;
			state->m_alu.y0 = dat;
//          logerror("ALU: write to Y0 (low) register - %02x (%04x)\n",data,state->m_alu.y0);
			break;
		case 0x18:
			dat = ((data & 0x03) << 8) | (state->m_alu.x1 & 0x00ff);
			state->m_alu.x1 = dat;
//          logerror("ALU: write to X1 (high) register - %02x (%04x)\n",data,state->m_alu.x1);
			break;
		case 0x19:
			dat = (state->m_alu.x1 & 0xff00) | data;
			state->m_alu.x1 = dat;
//          logerror("ALU: write to X1 (low) register - %02x (%04x)\n",data,state->m_alu.x1);
			break;
		case 0x1a:
			dat = ((data & 0x01) << 8) | (state->m_alu.y1 & 0x00ff);
			state->m_alu.y1 = dat;
//          logerror("ALU: write to Y1 (high) register - %02x (%04x)\n",data,state->m_alu.y1);
			break;
		case 0x1b:
			dat = (state->m_alu.y1 & 0xff00) | data;
			state->m_alu.y1 = dat;
			// draw line
			fm77av_line_draw(space->machine());
//          logerror("ALU: write to Y1 (low) register - %02x (%04x)\n",data,state->m_alu.y1);
			break;
		default:
			logerror("ALU: write 0x%02x to invalid register 0x%02x\n",data,offset);
	}
}

TIMER_CALLBACK( fm77av_vsync )
{
	fm7_state *state = machine.driver_data<fm7_state>();
	if(param == 0)  // start of vsync
	{
		state->m_video.vsync_flag = 1;
		state->m_fm77av_vsync_timer->adjust(attotime::from_usec(510),1);  // VSync length for 200 line modes = 0.51ms
	}
	else
	{
		state->m_video.vsync_flag = 0;
		state->m_fm77av_vsync_timer->adjust(machine.primary_screen->time_until_vblank_end());
	}
}

// called when banked into main CPU space by the MMR, available only if sub CPU is halted
READ8_HANDLER( fm7_sub_ram_ports_banked_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8* RAM = space->machine().region("maincpu")->base();
	UINT8* ROM;

	if(!state->m_video.sub_halt)
		return 0xff;

	if(offset < 0x380)  // work RAM
		return RAM[0x1d000+offset];
	if(offset >= 0x380 && offset < 0x400) // shared RAM
		return state->m_shared_ram[offset-0x380];
	if(offset >= 0x500 && offset < 0x800) // work RAM
		return RAM[0x1d000+offset];
	if(offset > 0x800) // CGROM
	{
		ROM = space->machine().region("subsyscg")->base();
		return ROM[(state->m_video.cgrom*0x800)+(offset-0x800)];
	}

	if(offset >= 0x410 && offset <= 0x42b)
		return fm77av_alu_r(space,offset-0x410);

	switch(offset)
	{
		case 0x400:
		case 0x401:
			return fm7_sub_keyboard_r(space,offset-0x400);
		case 0x402:
			return fm7_cancel_ack(space,0);
		case 0x403:
			return fm7_sub_beeper_r(space,0);
		case 0x404:
			return fm7_attn_irq_r(space,0);
		case 0x408:
			return fm7_crt_r(space,0);
		case 0x409:
			return fm7_vram_access_r(space,0);
		case 0x40a:
			return fm7_sub_busyflag_r(space,0);
		case 0x430:
			return fm77av_video_flags_r(space,0);
		case 0x431:
		case 0x432:
			return fm77av_key_encoder_r(space,offset-0x431);
		default:
			logerror("Unmapped read from sub CPU port 0xd%03x via MMR banking\n",offset);
			return 0xff;
	}
	return 0xff;
}

WRITE8_HANDLER( fm7_sub_ram_ports_banked_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8* RAM = space->machine().region("maincpu")->base();

	if(!state->m_video.sub_halt)
		return;

	if(offset < 0x380)  // work RAM
	{
		RAM[0x1d000+offset] = data;
		return;
	}
	if(offset >= 0x380 && offset < 0x400) // shared RAM
	{
		state->m_shared_ram[offset-0x380] = data;
		return;
	}
	if(offset >= 0x500 && offset < 0x800) // work RAM
	{
		RAM[0x1d000+offset] = data;
		return;
	}

	if(offset >= 0x410 && offset <= 0x42b)
	{
		fm77av_alu_w(space,offset-0x410,data);
		return;
	}

	switch(offset)
	{
		case 0x408:
			fm7_crt_w(space,0,data);
			break;
		case 0x409:
			fm7_vram_access_w(space,0,data);
			break;
		case 0x40a:
			fm7_sub_busyflag_w(space,0,data);
			break;
		case 0x40e:
		case 0x40f:
			fm7_vram_offset_w(space,offset-0x40e,data);
			break;
		case 0x430:
			fm77av_video_flags_w(space,0,data);
			break;
		case 0x431:
		case 0x432:
			fm77av_key_encoder_w(space,offset-0x431,data);
			break;
		default:
			logerror("Unmapped write of 0x%02x to sub CPU port 0xd%03x via MMR banking\n",data,offset);
	}
}

READ8_HANDLER( fm7_console_ram_banked_r )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8* RAM = space->machine().region("maincpu")->base();

	if(!state->m_video.sub_halt)
		return 0xff;

	return RAM[0x1c000+offset];
}

WRITE8_HANDLER( fm7_console_ram_banked_w )
{
	fm7_state *state = space->machine().driver_data<fm7_state>();
	UINT8* RAM = space->machine().region("maincpu")->base();

	if(!state->m_video.sub_halt)
		return;

	RAM[0x1c000+offset] = data;
}

VIDEO_START( fm7 )
{
	fm7_state *state = machine.driver_data<fm7_state>();
	state->m_video.vram_access = 0;
	state->m_video.crt_enable = 0;
	state->m_video.vram_offset = 0x0000;
	state->m_video.vram_offset2 = 0x0000;
	state->m_video.sub_reset = 0;
	state->m_video.multi_page = 0;
	state->m_video.subrom = 0;
	state->m_video.cgrom = 0;
	state->m_video.fine_offset = 0;
	state->m_video.nmi_mask = 0;
	state->m_video.active_video_page = 0;
	state->m_video.display_video_page = 0;
	state->m_video.vsync_flag = 0;
}

SCREEN_UPDATE( fm7 )
{
	fm7_state *state = screen->machine().driver_data<fm7_state>();
    UINT8 code_r = 0,code_g = 0,code_b = 0;
	UINT8 code_r2 = 0,code_g2 = 0,code_b2 = 0;
	UINT8 code_r3 = 0,code_g3 = 0,code_b3 = 0;
	UINT8 code_r4 = 0,code_g4 = 0,code_b4 = 0;
    UINT16 col;
    int y, x, b;
    UINT16 page = 0x0000;

    if(state->m_video.display_video_page != 0)
    	page = 0xc000;

	if(state->m_video.crt_enable == 0)
		return 0;

	if(state->m_video.modestatus & 0x40)  // 320x200 mode
	{
	    for (y = 0; y < 200; y++)
	    {
		    for (x = 0; x < 40; x++)
		    {
		    	if(!(state->m_video.multi_page & 0x40))
		    	{
	            	code_r = state->m_video_ram[0x8000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
	            	code_r2 = state->m_video_ram[0xa000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
	            	code_r3 = state->m_video_ram[0x14000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
	            	code_r4 = state->m_video_ram[0x16000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
		    	}
		    	if(!(state->m_video.multi_page & 0x20))
		    	{
	    	        code_g = state->m_video_ram[0x4000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
	    	        code_g2 = state->m_video_ram[0x6000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
	            	code_g3 = state->m_video_ram[0x10000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
	            	code_g4 = state->m_video_ram[0x12000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
		    	}
		    	if(!(state->m_video.multi_page & 0x10))
		    	{
		            code_b = state->m_video_ram[0x0000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
		            code_b2 = state->m_video_ram[0x2000 + ((y*40 + x + state->m_video.vram_offset) & 0x1fff)];
	            	code_b3 = state->m_video_ram[0xc000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
	            	code_b4 = state->m_video_ram[0xe000 + ((y*40 + x + state->m_video.vram_offset2) & 0x1fff)];
		    	}
	            for (b = 0; b < 8; b++)
	            {
	            	col = (((code_b >> b) & 0x01) ? 8 : 0) | (((code_b2 >> b) & 0x01) ? 4 : 0) | (((code_b3 >> b) & 0x01) ? 2 : 0) | (((code_b4 >> b) & 0x01) ? 1 : 0);
	            	col |= (((code_g >> b) & 0x01) ? 128 : 0) | (((code_g2 >> b) & 0x01) ? 64 : 0) | (((code_g3 >> b) & 0x01) ? 32 : 0) | (((code_g4 >> b) & 0x01) ? 16 : 0);
	            	col |= (((code_r >> b) & 0x01) ? 2048 : 0) | (((code_r2 >> b) & 0x01) ? 1024 : 0) | (((code_r3 >> b) & 0x01) ? 512 : 0) | (((code_r4 >> b) & 0x01) ? 256 : 0);
					col += 8;  // use analog palette
	                *BITMAP_ADDR16(bitmap, y,  x*8+(7-b)) =  col;
	            }
	        }
	    }
	}
	else
	{
	    for (y = 0; y < 200; y++)
	    {
		    for (x = 0; x < 80; x++)
		    {
		    	if(!(state->m_video.multi_page & 0x40))
	            	code_r = state->m_video_ram[page + 0x8000 + ((y*80 + x + state->m_video.vram_offset) & 0x3fff)];
		    	if(!(state->m_video.multi_page & 0x20))
	    	        code_g = state->m_video_ram[page + 0x4000 + ((y*80 + x + state->m_video.vram_offset) & 0x3fff)];
		    	if(!(state->m_video.multi_page & 0x10))
		            code_b = state->m_video_ram[page + 0x0000 + ((y*80 + x + state->m_video.vram_offset) & 0x3fff)];
	            for (b = 0; b < 8; b++)
	            {
	                col = (((code_r >> b) & 0x01) ? 4 : 0) + (((code_g >> b) & 0x01) ? 2 : 0) + (((code_b >> b) & 0x01) ? 1 : 0);
	                *BITMAP_ADDR16(bitmap, y,  x*8+(7-b)) =  col;
	            }
	        }
	    }
	}
	return 0;
}

static const rgb_t fm7_initial_palette[8] = {
	MAKE_RGB(0x00, 0x00, 0x00), // 0
	MAKE_RGB(0x00, 0x00, 0xff), // 1
	MAKE_RGB(0xff, 0x00, 0x00), // 2
	MAKE_RGB(0xff, 0x00, 0xff), // 3
	MAKE_RGB(0x00, 0xff, 0x00), // 4
	MAKE_RGB(0x00, 0xff, 0xff), // 5
	MAKE_RGB(0xff, 0xff, 0x00), // 6
	MAKE_RGB(0xff, 0xff, 0xff), // 7
};

PALETTE_INIT( fm7 )
{
	fm7_state *state = machine.driver_data<fm7_state>();
	int x;

	palette_set_colors(machine, 0, fm7_initial_palette, ARRAY_LENGTH(fm7_initial_palette));
	for(x=0;x<8;x++)
		state->m_video.fm7_pal[x] = x;
}

