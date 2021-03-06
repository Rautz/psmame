/***************************************************************************

    mc10.c

    TRS-80 Radio Shack MicroColor Computer

    Nate Woods

***************************************************************************/

#define ADDRESS_MAP_MODERN

#include "emu.h"
#include "cpu/m6800/m6800.h"
#include "sound/dac.h"
#include "video/m6847.h"
#include "video/ef9345.h"
#include "imagedev/cassette.h"
#include "imagedev/printer.h"
#include "formats/coco_cas.h"
#include "machine/ram.h"


//printer state
enum
{
	PRINTER_WAIT,
	PRINTER_REC,
	PRINTER_DONE
};


/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************/

class mc10_state : public driver_device
{
public:
	mc10_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config),
		  m_maincpu(*this, "maincpu"),
		  m_mc6847(*this, "mc6847"),
		  m_ef9345(*this, "ef9345"),
		  m_dac(*this, "dac"),
		  m_ram(*this, RAM_TAG),
		  m_cassette(*this, "cassette"),
		  m_printer(*this, "printer")
		{ }

	required_device<cpu_device> m_maincpu;
	optional_device<device_t> m_mc6847;
	optional_device<ef9345_device> m_ef9345;
	required_device<device_t> m_dac;
	required_device<device_t> m_ram;
	required_device<device_t> m_cassette;
	required_device<device_t> m_printer;

	UINT8 *m_ram_base;
	UINT32 m_ram_size;
	UINT8 m_keyboard_strobe;
	UINT8 m_port2;

	// printer
	UINT8 m_pr_buffer;
	UINT8 m_pr_counter;
	UINT8 m_pr_state;

	virtual bool screen_update(screen_device &screen, bitmap_t &bitmap, const rectangle &cliprect);

	DECLARE_READ8_MEMBER( mc10_bfff_r );
	DECLARE_WRITE8_MEMBER( mc10_bfff_w );
	DECLARE_WRITE8_MEMBER( alice32_bfff_w );
	DECLARE_READ8_MEMBER( mc10_port1_r );
	DECLARE_WRITE8_MEMBER( mc10_port1_w );
	DECLARE_READ8_MEMBER( mc10_port2_r );
	DECLARE_WRITE8_MEMBER( mc10_port2_w );
	DECLARE_READ8_MEMBER( mc10_mc6847_videoram_r );
};


/***************************************************************************
    MEMORY MAPPED I/O
***************************************************************************/

READ8_MEMBER( mc10_state::mc10_bfff_r )
{
	UINT8 result = 0xff;

	if (!BIT(m_keyboard_strobe, 0)) result &= input_port_read(m_machine, "pb0");
	if (!BIT(m_keyboard_strobe, 1)) result &= input_port_read(m_machine, "pb1");
	if (!BIT(m_keyboard_strobe, 2)) result &= input_port_read(m_machine, "pb2");
	if (!BIT(m_keyboard_strobe, 3)) result &= input_port_read(m_machine, "pb3");
	if (!BIT(m_keyboard_strobe, 4)) result &= input_port_read(m_machine, "pb4");
	if (!BIT(m_keyboard_strobe, 5)) result &= input_port_read(m_machine, "pb5");
	if (!BIT(m_keyboard_strobe, 6)) result &= input_port_read(m_machine, "pb6");
	if (!BIT(m_keyboard_strobe, 7)) result &= input_port_read(m_machine, "pb7");

	return result;
}

WRITE8_MEMBER( mc10_state::mc10_bfff_w )
{
	/* bit 2 to 6, mc6847 mode lines */
	mc6847_gm2_w(m_mc6847, BIT(data, 2));
	mc6847_intext_w(m_mc6847, BIT(data, 2));
	mc6847_gm1_w(m_mc6847, BIT(data, 3));
	mc6847_gm0_w(m_mc6847, BIT(data, 4));
	mc6847_ag_w(m_mc6847, BIT(data, 5));
	mc6847_css_w(m_mc6847, BIT(data, 6));

	/* bit 7, dac output */
	dac_data_w(m_dac, BIT(data, 7));
}

WRITE8_MEMBER( mc10_state::alice32_bfff_w )
{
	/* bit 7, dac output */
	dac_data_w(m_dac, BIT(data, 7));
}


/***************************************************************************
    MC6803 I/O
***************************************************************************/

/* keyboard strobe */
READ8_MEMBER( mc10_state::mc10_port1_r )
{
	return m_keyboard_strobe;
}

/* keyboard strobe */
WRITE8_MEMBER( mc10_state::mc10_port1_w )
{
	m_keyboard_strobe = data;
}

READ8_MEMBER( mc10_state::mc10_port2_r )
{
	UINT8 result = 0xeb;

	/* bit 1, keyboard line pa6 */
	if (!BIT(m_keyboard_strobe, 0)) result &= input_port_read(m_machine, "pb0") >> 5;
	if (!BIT(m_keyboard_strobe, 2)) result &= input_port_read(m_machine, "pb2") >> 5;
	if (!BIT(m_keyboard_strobe, 7)) result &= input_port_read(m_machine, "pb7") >> 5;

	/* bit 2, printer ots input */
	result |= (printer_is_ready(m_printer) ? 0 : 4);

	/* bit 3, rs232 input */

	/* bit 4, cassette input */
	result |= (cassette_input(m_cassette) >= 0 ? 1 : 0) << 4;

	return result;
}

WRITE8_MEMBER( mc10_state::mc10_port2_w )
{
	/* bit 0, cassette & printer output */
	cassette_output(m_cassette, BIT(data, 0) ? +1.0 : -1.0);

	switch (m_pr_state)
	{
		case PRINTER_WAIT:
			if (BIT(m_port2, 0) && !BIT(data, 0))
			{
				m_pr_state = PRINTER_REC;
				m_pr_counter = 8;
				m_pr_buffer = 0;
			}
			break;
		case PRINTER_REC:
			if (m_pr_counter--)
				m_pr_buffer |= (BIT(data,0)<<(7-m_pr_counter));
			else
				m_pr_state = PRINTER_DONE;
			break;
		case PRINTER_DONE:
			if (BIT(data,0))
				printer_output(m_printer, m_pr_buffer);
			m_pr_state = PRINTER_WAIT;
			break;
	}

	m_port2 = data;
}


/***************************************************************************
    VIDEO EMULATION
***************************************************************************/

READ8_MEMBER( mc10_state::mc10_mc6847_videoram_r )
{
	mc6847_inv_w(m_mc6847, BIT(m_ram_base[offset], 6));
	mc6847_as_w(m_mc6847, BIT(m_ram_base[offset], 7));

	return m_ram_base[offset];
}

bool mc10_state::screen_update(screen_device &screen, bitmap_t &bitmap, const rectangle &cliprect)
{
	if (m_mc6847)		//mc10, alice
		return mc6847_update(m_mc6847, &bitmap, &cliprect);
	else if (m_ef9345)	//alice32
		m_ef9345->video_update(&bitmap, &cliprect);

	return 0;
}

static TIMER_DEVICE_CALLBACK( alice32_scanline )
{
	mc10_state *state = timer.machine().driver_data<mc10_state>();

	state->m_ef9345->update_scanline((UINT16)param);
}

/***************************************************************************
    DRIVER INIT
***************************************************************************/

static DRIVER_INIT( mc10 )
{
	mc10_state *mc10 = machine.driver_data<mc10_state>();
	address_space *prg = machine.device("maincpu")->memory().space(AS_PROGRAM);

	/* initialize keyboard strobe */
	mc10->m_keyboard_strobe = 0x00;

	/* initialize memory */
	mc10->m_ram_base = ram_get_ptr(mc10->m_ram);
	mc10->m_ram_size = ram_get_size(mc10->m_ram);
	mc10->m_pr_state = PRINTER_WAIT;

	memory_set_bankptr(machine, "bank1", mc10->m_ram_base);

	/* initialize memory expansion */
	if (mc10->m_ram_size == 20*1024)
		memory_set_bankptr(machine, "bank2", mc10->m_ram_base + 0x1000);
	else if (mc10->m_ram_size == 24*1024)
		memory_set_bankptr(machine, "bank2", mc10->m_ram_base + 0x2000);
	else  if (mc10->m_ram_size != 32*1024)		//ensure that is not alice90
		prg->nop_readwrite(0x5000, 0x8fff);

	/* register for state saving */
	state_save_register_global(machine, mc10->m_keyboard_strobe);

	//for alice32 force port4 DDR to 0xff at startup
	if (!strcmp(machine.system().name, "alice32") || !strcmp(machine.system().name, "alice90"))
		m6801_io_w(prg, 0x05, 0xff);
}


/***************************************************************************
    ADDRESS MAPS
***************************************************************************/

static ADDRESS_MAP_START( mc10_mem, AS_PROGRAM, 8 , mc10_state)
	AM_RANGE(0x0100, 0x3fff) AM_NOP /* unused */
	AM_RANGE(0x4000, 0x4fff) AM_RAMBANK("bank1") /* 4k internal ram */
	AM_RANGE(0x5000, 0x8fff) AM_RAMBANK("bank2") /* 16k memory expansion */
	AM_RANGE(0x9000, 0xbffe) AM_NOP /* unused */
	AM_RANGE(0xbfff, 0xbfff) AM_READWRITE(mc10_bfff_r, mc10_bfff_w)
	AM_RANGE(0xe000, 0xffff) AM_ROM AM_REGION("maincpu", 0x0000) /* ROM */
ADDRESS_MAP_END

static ADDRESS_MAP_START( mc10_io, AS_IO, 8 , mc10_state)
	AM_RANGE(M6801_PORT1, M6801_PORT1) AM_READWRITE(mc10_port1_r, mc10_port1_w)
	AM_RANGE(M6801_PORT2, M6801_PORT2) AM_READWRITE(mc10_port2_r, mc10_port2_w)
ADDRESS_MAP_END

static ADDRESS_MAP_START( alice32_mem, AS_PROGRAM, 8 , mc10_state)
	AM_RANGE(0x0100, 0x2fff) AM_NOP /* unused */
	AM_RANGE(0x3000, 0x4fff) AM_RAMBANK("bank1") /* 8k internal ram */
	AM_RANGE(0x5000, 0x8fff) AM_RAMBANK("bank2") /* 16k memory expansion */
	AM_RANGE(0x9000, 0xafff) AM_NOP /* unused */
	AM_RANGE(0xbf20, 0xbf29) AM_DEVREADWRITE("ef9345", ef9345_device, data_r, data_w)
	AM_RANGE(0xbfff, 0xbfff) AM_READWRITE(mc10_bfff_r, alice32_bfff_w)
	AM_RANGE(0xc000, 0xffff) AM_ROM AM_REGION("maincpu", 0x0000) /* ROM */
ADDRESS_MAP_END

static ADDRESS_MAP_START( alice90_mem, AS_PROGRAM, 8 , mc10_state)
	AM_RANGE(0x0100, 0x2fff) AM_NOP /* unused */
	AM_RANGE(0x3000, 0xafff) AM_RAMBANK("bank1")	/* 32k internal ram */
	AM_RANGE(0xbf20, 0xbf29) AM_DEVREADWRITE("ef9345", ef9345_device, data_r, data_w)
	AM_RANGE(0xbfff, 0xbfff) AM_READWRITE(mc10_bfff_r, alice32_bfff_w)
	AM_RANGE(0xc000, 0xffff) AM_ROM AM_REGION("maincpu", 0x0000) /* ROM */
ADDRESS_MAP_END

/***************************************************************************
    INPUT PORTS
***************************************************************************/

/* MC-10 keyboard

       PB0 PB1 PB2 PB3 PB4 PB5 PB6 PB7
  PA6: Ctl N/c Brk N/c N/c N/c N/c Shift
  PA5: 8   9   :   ;   ,   -   .   /
  PA4: 0   1   2   3   4   5   6   7
  PA3: X   Y   Z   N/c N/c N/c Ent Space
  PA2: P   Q   R   S   T   U   V   W
  PA1: H   I   J   K   L   M   N   O
  PA0: @   A   B   C   D   E   F   G
 */

/*  Port                                        Key description                 Emulated key                  Natural key     Shift 1         Shift 2 (Ctrl) */
static INPUT_PORTS_START( mc10 )
	PORT_START("pb0") /* KEY ROW 0 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("@     INPUT")        PORT_CODE(KEYCODE_OPENBRACE)  PORT_CHAR('@')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("H     THEN")         PORT_CODE(KEYCODE_H)          PORT_CHAR('H')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("P     INKEY$")       PORT_CODE(KEYCODE_P)          PORT_CHAR('P')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("X     SQN")          PORT_CODE(KEYCODE_X)          PORT_CHAR('X')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("0")                  PORT_CODE(KEYCODE_0)          PORT_CHAR('0')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("8  (  CLS")          PORT_CODE(KEYCODE_8)          PORT_CHAR('8')  PORT_CHAR('(')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("CONTROL")            PORT_CODE(KEYCODE_LSHIFT)     PORT_CHAR(UCHAR_SHIFT_2)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb1") /* KEY ROW 1 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("A     \xE2\x86\x90") PORT_CODE(KEYCODE_A)          PORT_CHAR('A')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("I     NEXT")         PORT_CODE(KEYCODE_I)          PORT_CHAR('I')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Q     L.DEL")        PORT_CODE(KEYCODE_Q)          PORT_CHAR('Q')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Y     RESTORE")      PORT_CODE(KEYCODE_Y)          PORT_CHAR('Y')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("1  !  RUN")          PORT_CODE(KEYCODE_1)          PORT_CHAR('1')  PORT_CHAR('!')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("9  )  PRINT")        PORT_CODE(KEYCODE_9)          PORT_CHAR('9')  PORT_CHAR(')')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb2") /* KEY ROW 2 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("B     ABS")          PORT_CODE(KEYCODE_B)          PORT_CHAR('B')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("J     GOTO")         PORT_CODE(KEYCODE_J)          PORT_CHAR('J')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("R     RESET")        PORT_CODE(KEYCODE_R)          PORT_CHAR('R')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Z     \xE2\x86\x93") PORT_CODE(KEYCODE_Z)          PORT_CHAR('Z')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(DOWN))
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("2  \"  CONT")        PORT_CODE(KEYCODE_2)          PORT_CHAR('2')  PORT_CHAR('\"')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(":  *  END")          PORT_CODE(KEYCODE_MINUS)      PORT_CHAR(':')  PORT_CHAR('*')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("BREAK")              PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR(UCHAR_MAMEKEY(CANCEL))
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb3") /* KEY ROW 3 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("C     INT")          PORT_CODE(KEYCODE_C)          PORT_CHAR('C')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("K     SOUND")        PORT_CODE(KEYCODE_K)          PORT_CHAR('K')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("S     \xE2\x86\x92") PORT_CODE(KEYCODE_S)          PORT_CHAR('S')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(RIGHT))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("3  #  CSAVE")        PORT_CODE(KEYCODE_3)          PORT_CHAR('3')  PORT_CHAR('#')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(";  +  POKE")         PORT_CODE(KEYCODE_COLON)      PORT_CHAR(';')  PORT_CHAR('+')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb4") /* KEY ROW 4 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("D     GOSUB")        PORT_CODE(KEYCODE_D)          PORT_CHAR('D')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("L     PEEK")         PORT_CODE(KEYCODE_L)          PORT_CHAR('L')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("T     READ")         PORT_CODE(KEYCODE_T)          PORT_CHAR('T')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("4  $  CLOAD")        PORT_CODE(KEYCODE_4)          PORT_CHAR('4')  PORT_CHAR('$')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(",  <  TAN")          PORT_CODE(KEYCODE_COMMA)      PORT_CHAR(',')  PORT_CHAR('<')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb5") /* KEY ROW 5 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("E     SET")          PORT_CODE(KEYCODE_E)          PORT_CHAR('E')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("M     COS")          PORT_CODE(KEYCODE_M)          PORT_CHAR('M')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("U     FOR")          PORT_CODE(KEYCODE_U)          PORT_CHAR('U')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("5  %  NEW")          PORT_CODE(KEYCODE_5)          PORT_CHAR('5')  PORT_CHAR('%')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("-  =  STOP")         PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('-')  PORT_CHAR('=')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb6") /* KEY ROW 6 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("F     RETURN")       PORT_CODE(KEYCODE_F)          PORT_CHAR('F')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("N     SIN")          PORT_CODE(KEYCODE_N)          PORT_CHAR('N')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("V     RND")          PORT_CODE(KEYCODE_V)          PORT_CHAR('V')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("ENTER")              PORT_CODE(KEYCODE_ENTER)      PORT_CHAR(13)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("6  &  LIST")         PORT_CODE(KEYCODE_6)          PORT_CHAR('6')  PORT_CHAR('&')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(".  >  LOG")          PORT_CODE(KEYCODE_STOP)       PORT_CHAR('.')  PORT_CHAR('>')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb7") /* KEY ROW 7 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("G     IF")           PORT_CODE(KEYCODE_G)          PORT_CHAR('G')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("O     STEP")         PORT_CODE(KEYCODE_O)          PORT_CHAR('O')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("W     \xE2\x86\x91") PORT_CODE(KEYCODE_W)          PORT_CHAR('W')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("SPACE")              PORT_CODE(KEYCODE_SPACE)      PORT_CHAR(' ')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("7  '  CLEAR")        PORT_CODE(KEYCODE_7)          PORT_CHAR('7')  PORT_CHAR('\'')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("/  ?  SQR")          PORT_CODE(KEYCODE_SLASH)      PORT_CHAR('/')  PORT_CHAR('?')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("SHIFT")              PORT_CODE(KEYCODE_RSHIFT)     PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_INCLUDE( m6847_artifacting )
INPUT_PORTS_END

/* Alice uses an AZERTY keyboard */
/*  Port                                        Key description                 Emulated key                  Natural key     Shift 1         Shift 2 (Ctrl) */
static INPUT_PORTS_START( alice )
	PORT_START("pb0") /* KEY ROW 0 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("@     INPUT")        PORT_CODE(KEYCODE_OPENBRACE)  PORT_CHAR('@')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("H     THEN")         PORT_CODE(KEYCODE_H)          PORT_CHAR('H')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("P     INKEY$")       PORT_CODE(KEYCODE_P)          PORT_CHAR('P')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("X     SQN")          PORT_CODE(KEYCODE_X)          PORT_CHAR('X')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("0")                  PORT_CODE(KEYCODE_0)          PORT_CHAR('0')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("8  (  CLS")          PORT_CODE(KEYCODE_8)          PORT_CHAR('8')  PORT_CHAR('(')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("CONTROL")            PORT_CODE(KEYCODE_LSHIFT)     PORT_CHAR(UCHAR_SHIFT_2)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb1") /* KEY ROW 1 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Q     L.DEL")        PORT_CODE(KEYCODE_Q)          PORT_CHAR('Q')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("I     NEXT")         PORT_CODE(KEYCODE_I)          PORT_CHAR('I')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("A     \xE2\x86\x90") PORT_CODE(KEYCODE_A)          PORT_CHAR('A')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Y     RESTORE")      PORT_CODE(KEYCODE_Y)          PORT_CHAR('Y')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("1  !  RUN")          PORT_CODE(KEYCODE_1)          PORT_CHAR('1')  PORT_CHAR('!')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("9  )  PRINT")        PORT_CODE(KEYCODE_9)          PORT_CHAR('9')  PORT_CHAR(')')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb2") /* KEY ROW 2 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("B     ABS")          PORT_CODE(KEYCODE_B)          PORT_CHAR('B')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("J     GOTO")         PORT_CODE(KEYCODE_J)          PORT_CHAR('J')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("R     RESET")        PORT_CODE(KEYCODE_R)          PORT_CHAR('R')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("W     \xE2\x86\x91") PORT_CODE(KEYCODE_W)          PORT_CHAR('W')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("2  \"  CONT")        PORT_CODE(KEYCODE_2)          PORT_CHAR('2')  PORT_CHAR('\"')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(":  *  END")          PORT_CODE(KEYCODE_MINUS)      PORT_CHAR(':')  PORT_CHAR('*')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("BREAK")              PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR(UCHAR_MAMEKEY(CANCEL))
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb3") /* KEY ROW 3 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("C     INT")          PORT_CODE(KEYCODE_C)          PORT_CHAR('C')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("K     SOUND")        PORT_CODE(KEYCODE_K)          PORT_CHAR('K')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("S     \xE2\x86\x92") PORT_CODE(KEYCODE_S)          PORT_CHAR('S')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(RIGHT))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("3  #  CSAVE")        PORT_CODE(KEYCODE_3)          PORT_CHAR('3')  PORT_CHAR('#')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("M     COS")          PORT_CODE(KEYCODE_M)          PORT_CHAR('M')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb4") /* KEY ROW 4 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("D     GOSUB")        PORT_CODE(KEYCODE_D)          PORT_CHAR('D')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("L     PEEK")         PORT_CODE(KEYCODE_L)          PORT_CHAR('L')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("T     READ")         PORT_CODE(KEYCODE_T)          PORT_CHAR('T')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("4  $  CLOAD")        PORT_CODE(KEYCODE_4)          PORT_CHAR('4')  PORT_CHAR('$')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(",  <  TAN")          PORT_CODE(KEYCODE_COMMA)      PORT_CHAR(',')  PORT_CHAR('<')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb5") /* KEY ROW 5 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("E     SET")          PORT_CODE(KEYCODE_E)          PORT_CHAR('E')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("/  ?  SQR")          PORT_CODE(KEYCODE_SLASH)      PORT_CHAR('/')  PORT_CHAR('?')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("U     FOR")          PORT_CODE(KEYCODE_U)          PORT_CHAR('U')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("5  %  NEW")          PORT_CODE(KEYCODE_5)          PORT_CHAR('5')  PORT_CHAR('%')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("-  =  STOP")         PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('-')  PORT_CHAR('=')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb6") /* KEY ROW 6 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("F     RETURN")       PORT_CODE(KEYCODE_F)          PORT_CHAR('F')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("N     SIN")          PORT_CODE(KEYCODE_N)          PORT_CHAR('N')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("V     RND")          PORT_CODE(KEYCODE_V)          PORT_CHAR('V')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("ENTER")              PORT_CODE(KEYCODE_ENTER)      PORT_CHAR(13)
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("6  &  LIST")         PORT_CODE(KEYCODE_6)          PORT_CHAR('6')  PORT_CHAR('&')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(".  >  LOG")          PORT_CODE(KEYCODE_STOP)       PORT_CHAR('.')  PORT_CHAR('>')
	PORT_BIT(0xc0, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_START("pb7") /* KEY ROW 7 */
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("G     IF")           PORT_CODE(KEYCODE_G)          PORT_CHAR('G')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("O     STEP")         PORT_CODE(KEYCODE_O)          PORT_CHAR('O')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("Z     \xE2\x86\x93") PORT_CODE(KEYCODE_Z)          PORT_CHAR('Z')  PORT_CHAR('~')  PORT_CHAR(UCHAR_MAMEKEY(DOWN))
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("SPACE")              PORT_CODE(KEYCODE_SPACE)      PORT_CHAR(' ')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("7  '  CLEAR")        PORT_CODE(KEYCODE_7)          PORT_CHAR('7')  PORT_CHAR('\'')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME(";  +  POKE")         PORT_CODE(KEYCODE_COLON)      PORT_CHAR(';')  PORT_CHAR('+')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_NAME("SHIFT")              PORT_CODE(KEYCODE_RSHIFT)     PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED)

	PORT_INCLUDE( m6847_artifacting )
INPUT_PORTS_END


/***************************************************************************
    MACHINE DRIVERS
***************************************************************************/

static const cassette_config mc10_cassette_config =
{
	coco_cassette_formats,
	NULL,
	(cassette_state)(CASSETTE_STOPPED | CASSETTE_SPEAKER_ENABLED | CASSETTE_MOTOR_ENABLED),
	NULL
};

static const cassette_config alice32_cassette_config =
{
	alice32_cassette_formats,
	NULL,
	(cassette_state)(CASSETTE_STOPPED | CASSETTE_SPEAKER_ENABLED | CASSETTE_MOTOR_ENABLED),
	"alice32_cass"
};

static const mc6847_interface mc10_mc6847_intf =
{
	DEVCB_DRIVER_MEMBER(mc10_state, mc10_mc6847_videoram_r),
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL,
	DEVCB_NULL
};

static MACHINE_CONFIG_START( mc10, mc10_state )

	/* basic machine hardware */
	MCFG_CPU_ADD("maincpu", M6803, XTAL_3_579545MHz)  /* 0,894886 MHz */
	MCFG_CPU_PROGRAM_MAP(mc10_mem)
	MCFG_CPU_IO_MAP(mc10_io)
	MCFG_SCREEN_ADD("screen", RASTER)
	MCFG_SCREEN_REFRESH_RATE(60)

	/* video hardware */
	MCFG_SCREEN_FORMAT(BITMAP_FORMAT_RGB32)
	MCFG_SCREEN_SIZE(320, 25+192+26)
	MCFG_SCREEN_VISIBLE_AREA(0, 319, 1, 239)

	MCFG_MC6847_ADD("mc6847", mc10_mc6847_intf)
	MCFG_MC6847_TYPE(M6847_VERSION_ORIGINAL_NTSC)

	/* sound hardware */
	MCFG_SPEAKER_STANDARD_MONO("mono")
	MCFG_SOUND_ADD("dac", DAC, 0)
	MCFG_SOUND_ROUTE(ALL_OUTPUTS, "mono", 1.00)

	MCFG_CASSETTE_ADD("cassette", mc10_cassette_config)

	/* printer */
	MCFG_PRINTER_ADD("printer")

	/* internal ram */
	MCFG_RAM_ADD(RAM_TAG)
	MCFG_RAM_DEFAULT_SIZE("20K")
	MCFG_RAM_EXTRA_OPTIONS("4K")
MACHINE_CONFIG_END

static const ef9345_interface alice32_ef9345_config =
{
	"screen"			/* screen we are acting on */
};

static MACHINE_CONFIG_START( alice32, mc10_state )

	/* basic machine hardware */
	MCFG_CPU_ADD("maincpu", M6803, XTAL_3_579545MHz)
	MCFG_CPU_PROGRAM_MAP(alice32_mem)
	MCFG_CPU_IO_MAP(mc10_io)

	/* video hardware */
	MCFG_SCREEN_ADD("screen", RASTER)
	MCFG_SCREEN_REFRESH_RATE(60)
	MCFG_SCREEN_FORMAT(BITMAP_FORMAT_INDEXED16)
	MCFG_SCREEN_SIZE(336, 270)
	MCFG_SCREEN_VISIBLE_AREA(00, 336-1, 00, 270-1)
	MCFG_PALETTE_LENGTH(8)

	MCFG_EF9345_ADD("ef9345", alice32_ef9345_config)
	MCFG_TIMER_ADD_SCANLINE("alice32_sl", alice32_scanline, "screen", 0, 10)

	/* sound hardware */
	MCFG_SPEAKER_STANDARD_MONO("mono")
	MCFG_SOUND_ADD("dac", DAC, 0)
	MCFG_SOUND_ROUTE(ALL_OUTPUTS, "mono", 1.00)

	MCFG_CASSETTE_ADD("cassette", alice32_cassette_config)

	/* printer */
	MCFG_PRINTER_ADD("printer")

	/* internal ram */
	MCFG_RAM_ADD(RAM_TAG)
	MCFG_RAM_DEFAULT_SIZE("24K")
	MCFG_RAM_EXTRA_OPTIONS("8K")

	/* Software lists */
	MCFG_SOFTWARE_LIST_ADD("cass_list", "alice32")
MACHINE_CONFIG_END

static MACHINE_CONFIG_DERIVED( alice90, alice32 )
	MCFG_CPU_MODIFY("maincpu")
	MCFG_CPU_PROGRAM_MAP(alice90_mem)

    MCFG_RAM_MODIFY(RAM_TAG)
	MCFG_RAM_DEFAULT_SIZE("32K")
MACHINE_CONFIG_END


/***************************************************************************
    ROM DEFINITIONS
***************************************************************************/

ROM_START( mc10 )
	ROM_REGION(0x2000, "maincpu", 0)
	ROM_LOAD("mc10.rom", 0x0000, 0x2000, CRC(11fda97e) SHA1(4afff2b4c120334481aab7b02c3552bf76f1bc43))
ROM_END

ROM_START( alice )
	ROM_REGION(0x2000, "maincpu", 0)
	ROM_LOAD("alice.rom", 0x0000, 0x2000, CRC(f876abe9) SHA1(c2166b91e6396a311f486832012aa43e0d2b19f8))
ROM_END

ROM_START( alice32 )
	ROM_REGION(0x4000, "maincpu", 0)
	ROM_LOAD("alice32.rom", 0x0000, 0x4000, CRC(c3854ddf) SHA1(f34e61c3cf711fb59ff4f1d4c0d2863dab0ab5d1))

	ROM_REGION( 0x2000, "ef9345", 0 )
	ROM_LOAD( "charset.rom", 0x0000, 0x2000, BAD_DUMP CRC(b2f49eb3) SHA1(d0ef530be33bfc296314e7152302d95fdf9520fc) )			// from dcvg5k
ROM_END

#define rom_alice90 rom_alice32

/***************************************************************************
    GAME DRIVERS
***************************************************************************/

/*    YEAR  NAME   PARENT  COMPAT  MACHINE  INPUT  INIT  COMPANY              FULLNAME  FLAGS */
COMP( 1983, mc10,  0,      0,      mc10,    mc10,  mc10, "Tandy Radio Shack", "MC-10",  GAME_SUPPORTS_SAVE )
COMP( 1983, alice, mc10,   0,      mc10,    alice, mc10, "Matra & Hachette",  "Alice",  GAME_SUPPORTS_SAVE )
COMP( 1984, alice32,       0, 0,   alice32, alice, mc10, "Matra & Hachette",  "Alice 32",  GAME_IMPERFECT_GRAPHICS | GAME_SUPPORTS_SAVE )
COMP( 1985, alice90, alice32, 0,   alice90, alice, mc10, "Matra & Hachette",  "Alice 90",  GAME_IMPERFECT_GRAPHICS | GAME_SUPPORTS_SAVE )
