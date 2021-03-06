#pragma once

#ifndef __CRVISION__
#define __CRVISION__

#define ADDRESS_MAP_MODERN

#include "emu.h"
#include "cpu/m6502/m6502.h"
#include "imagedev/cartslot.h"
#include "imagedev/cassette.h"
#include "imagedev/flopdrv.h"
#include "formats/basicdsk.h"
#include "machine/ctronics.h"
#include "machine/6821pia.h"
#include "sound/sn76496.h"
#include "sound/wave.h"
#include "video/tms9928a.h"
#include "machine/ram.h"

#define SCREEN_TAG		"screen"
#define M6502_TAG		"u2"
#define TMS9929_TAG		"u3"
#define PIA6821_TAG		"u21"
#define SN76489_TAG		"u22"
#define CASSETTE_TAG	"cassette"
#define CENTRONICS_TAG	"centronics"

#define BANK_ROM1		"bank1"
#define BANK_ROM2		"bank2"

class crvision_state : public driver_device
{
public:
	crvision_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config),
		  m_maincpu(*this, M6502_TAG),
		  m_pia(*this, PIA6821_TAG),
		  m_psg(*this, SN76489_TAG),
		  m_cassette(*this, CASSETTE_TAG),
		  m_centronics(*this, CENTRONICS_TAG),
		  m_ram(*this, RAM_TAG)
	{ }

	required_device<cpu_device> m_maincpu;
	required_device<device_t> m_pia;
	required_device<device_t> m_psg;
	required_device<device_t> m_cassette;
	required_device<device_t> m_centronics;
	required_device<device_t> m_ram;

	virtual void machine_start();

	DECLARE_READ8_MEMBER( centronics_status_r );
	DECLARE_WRITE8_MEMBER( centronics_ctrl_w );
	DECLARE_WRITE8_MEMBER( pia_pa_w );
	DECLARE_READ8_MEMBER( pia_pa_r );
	DECLARE_READ8_MEMBER( pia_pb_r );

	UINT8 read_keyboard(int pa);

	/* keyboard state */
	UINT8 m_keylatch;

	/* joystick state */
	UINT8 m_joylatch;
};

class crvision_pal_state : public crvision_state
{
public:
	crvision_pal_state(running_machine &machine, const driver_device_config_base &config)
		: crvision_state(machine, config)
	{ }

	virtual void machine_start();
};

class laser2001_state : public crvision_state
{
public:
	laser2001_state(running_machine &machine, const driver_device_config_base &config)
		: crvision_state(machine, config)
	{ }

	virtual void machine_start();

	DECLARE_READ8_MEMBER( pia_pa_r );
	DECLARE_WRITE8_MEMBER( pia_pa_w );
	DECLARE_READ8_MEMBER( pia_pb_r );
	DECLARE_WRITE8_MEMBER( pia_pb_w );
	DECLARE_READ_LINE_MEMBER( pia_ca1_r );
	DECLARE_WRITE_LINE_MEMBER( pia_ca2_w );
	DECLARE_READ_LINE_MEMBER( pia_cb1_r );
	DECLARE_WRITE_LINE_MEMBER( pia_cb2_w );
};

#endif
