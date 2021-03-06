/*****************************************************************************
 *
 * includes/a7800.h
 *
 ****************************************************************************/

#ifndef A7800_H_
#define A7800_H_

#include "machine/6532riot.h"

class a7800_state : public driver_device
{
public:
	a7800_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config) { }

	int m_lines;
	int m_ispal;
	unsigned char *m_cart_bkup;
	unsigned char *m_bios_bkup;
	int m_ctrl_lock;
	int m_ctrl_reg;
	int m_maria_flag;
	unsigned char *m_cartridge_rom;
	UINT16 m_cart_type;
	UINT32 m_cart_size;
	unsigned char m_stick_type;
	UINT8 *m_ROM;
	int m_maria_palette[8][4];
	int m_maria_write_mode;
	int m_maria_scanline;
	unsigned int m_maria_dll;
	unsigned int m_maria_dl;
	int m_maria_holey;
	int m_maria_offset;
	int m_maria_vblank;
	int m_maria_dli;
	int m_maria_dmaon;
	int m_maria_dodma;
	int m_maria_wsync;
	int m_maria_backcolor;
	int m_maria_color_kill;
	int m_maria_cwidth;
	int m_maria_bcntl;
	int m_maria_kangaroo;
	int m_maria_rm;
	unsigned int m_maria_charbase;
};


/*----------- defined in video/a7800.c -----------*/

VIDEO_START( a7800 );
SCREEN_UPDATE( a7800 );
INTERRUPT_GEN( a7800_interrupt );
 READ8_HANDLER( a7800_MARIA_r );
WRITE8_HANDLER( a7800_MARIA_w );


/*----------- defined in machine/a7800.c -----------*/

extern const riot6532_interface a7800_r6532_interface;


MACHINE_RESET( a7800 );

void a7800_partialhash(hash_collection &dest, const unsigned char *data, unsigned long length, const char *functions);

DEVICE_START( a7800_cart );
DEVICE_IMAGE_LOAD( a7800_cart );

 READ8_HANDLER( a7800_TIA_r );
WRITE8_HANDLER( a7800_TIA_w );
WRITE8_HANDLER( a7800_RAM0_w );
WRITE8_HANDLER( a7800_cart_w );

DRIVER_INIT( a7800_ntsc );
DRIVER_INIT( a7800_pal );


#endif /* A7800_H_ */
