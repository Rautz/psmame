/*

Luxor ABC77

*/

#define ADDRESS_MAP_MODERN

#include "emu.h"
#include "abc77.h"
#include "cpu/mcs48/mcs48.h"
#include "machine/devhelpr.h"
#include "sound/discrete.h"
#include "sound/speaker.h"



//**************************************************************************
//  MACROS / CONSTANTS
//**************************************************************************

#define I8035_TAG		"z16"
#define DISCRETE_TAG	"discrete"



//**************************************************************************
//  DEVICE DEFINITIONS
//**************************************************************************

const device_type ABC77 = abc77_device_config::static_alloc_device_config;



//**************************************************************************
//  DEVICE CONFIGURATION
//**************************************************************************

GENERIC_DEVICE_CONFIG_SETUP(abc77, "Luxor ABC 77")


//-------------------------------------------------
//  device_config_complete - perform any
//  operations now that the configuration is
//  complete
//-------------------------------------------------

void abc77_device_config::device_config_complete()
{
	// inherit a copy of the static data
	const abc77_interface *intf = reinterpret_cast<const abc77_interface *>(static_config());
	if (intf != NULL)
		*static_cast<abc77_interface *>(this) = *intf;

	// or initialize to defaults if none provided
	else
	{
		memset(&m_out_txd_func, 0, sizeof(m_out_txd_func));
		memset(&m_out_clock_func, 0, sizeof(m_out_clock_func));
		memset(&m_out_keydown_func, 0, sizeof(m_out_keydown_func));
	}

	m_shortname = "abc77";
}


//-------------------------------------------------
//  ROM( abc77 )
//-------------------------------------------------

ROM_START( abc77 )
	ROM_LOAD( "65-02486.z10", 0x0000, 0x0800, NO_DUMP ) // Swedish
	ROM_LOAD( "keyboard.z14", 0x0800, 0x0800, NO_DUMP ) // non-Swedish
ROM_END


//-------------------------------------------------
//  rom_region - device-specific ROM region
//-------------------------------------------------

const rom_entry *abc77_device_config::device_rom_region() const
{
	return ROM_NAME( abc77 );
}


//-------------------------------------------------
//  ADDRESS_MAP( abc77_mem )
//-------------------------------------------------

static ADDRESS_MAP_START( abc77_map, AS_PROGRAM, 8, abc77_device )
	AM_RANGE(0x000, 0xfff) AM_ROM AM_REGION("abc77:z16", 0)
ADDRESS_MAP_END


//-------------------------------------------------
//  ADDRESS_MAP( abc77_io )
//-------------------------------------------------

static ADDRESS_MAP_START( abc77_io, AS_IO, 8, abc77_device )
	AM_RANGE(MCS48_PORT_P1, MCS48_PORT_P1) AM_DEVREAD(DEVICE_SELF_OWNER, abc77_device, p1_r)
	AM_RANGE(MCS48_PORT_P2, MCS48_PORT_P2) AM_DEVWRITE(DEVICE_SELF_OWNER, abc77_device, p2_w)
	AM_RANGE(MCS48_PORT_T1, MCS48_PORT_T1) AM_DEVREAD(DEVICE_SELF_OWNER, abc77_device, t1_r)
	AM_RANGE(MCS48_PORT_BUS, MCS48_PORT_BUS) AM_READ_PORT("DSW")
ADDRESS_MAP_END


//-------------------------------------------------
//  DISCRETE_SOUND( abc77 )
//-------------------------------------------------

static const discrete_555_desc abc77_ne556_a =
{
	DISC_555_OUT_SQW | DISC_555_OUT_DC,
	5,		// B+ voltage of 555
	DEFAULT_555_VALUES
};

static DISCRETE_SOUND_START( abc77 )
	DISCRETE_INPUT_LOGIC(NODE_01)
	DISCRETE_555_ASTABLE(NODE_02, NODE_01, RES_K(2.7), RES_K(15), CAP_N(22), &abc77_ne556_a)
	DISCRETE_OUTPUT(NODE_02, 5000)
DISCRETE_SOUND_END


//-------------------------------------------------
//  MACHINE_DRIVER( abc77 )
//-------------------------------------------------

static MACHINE_CONFIG_FRAGMENT( abc77 )
	// keyboard cpu
	MCFG_CPU_ADD(I8035_TAG, I8035, XTAL_4_608MHz)
	MCFG_CPU_PROGRAM_MAP(abc77_map)
	MCFG_CPU_IO_MAP(abc77_io)

	// watchdog
	MCFG_WATCHDOG_TIME_INIT(MCS48_ALE_CLOCK(XTAL_4_608MHz))

	// discrete sound
	MCFG_SPEAKER_STANDARD_MONO("mono")
	MCFG_SOUND_ADD(DISCRETE_TAG, DISCRETE, 0)
	MCFG_SOUND_CONFIG_DISCRETE(abc77)
	MCFG_SOUND_ROUTE(ALL_OUTPUTS, "abc77:mono", 0.80)
MACHINE_CONFIG_END


//-------------------------------------------------
//  machine_config_additions - device-specific
//  machine configurations
//-------------------------------------------------

machine_config_constructor abc77_device_config::device_mconfig_additions() const
{
	return MACHINE_CONFIG_NAME( abc77 );
}


//-------------------------------------------------
//  INPUT_PORTS( abc77 )
//-------------------------------------------------

INPUT_PORTS_START( abc77 )
	PORT_START("X0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("CAPS LOCK") PORT_CODE(KEYCODE_CAPSLOCK) PORT_CHAR(UCHAR_MAMEKEY(CAPSLOCK))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("CTRL") PORT_CODE(KEYCODE_LCONTROL) PORT_CHAR(UCHAR_MAMEKEY(LCONTROL))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("RIGHT SHIFT") PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("LEFT SHIFT") PORT_CODE(KEYCODE_LSHIFT) PORT_CHAR(UCHAR_SHIFT_1)

	PORT_START("X1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("X2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH) PORT_CHAR('<') PORT_CHAR('>')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("RETURN") PORT_CODE(KEYCODE_ENTER) PORT_CHAR('\r')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90") PORT_CODE(KEYCODE_BACKSPACE) PORT_CHAR(8)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x92") PORT_CODE(KEYCODE_RIGHT) PORT_CHAR(UCHAR_MAMEKEY(RIGHT))

	PORT_START("X3")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS) PORT_CHAR(0x00E9) PORT_CHAR(0x00C9)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS) PORT_CHAR('+') PORT_CHAR('?')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_OPENBRACE) PORT_CHAR(0x00E5) PORT_CHAR(0x00C5)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR(0x00FC) PORT_CHAR(0x00DC)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_QUOTE) PORT_CHAR(0x00E4) PORT_CHAR(0x00C4)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH) PORT_CHAR('\'') PORT_CHAR('*')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("SPACE") PORT_CODE(KEYCODE_SPACE) PORT_CHAR(' ')

	PORT_START("X4")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0) PORT_CHAR('0') PORT_CHAR('=')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9) PORT_CHAR('9') PORT_CHAR(')')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O) PORT_CHAR('o') PORT_CHAR('O')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P) PORT_CHAR('p') PORT_CHAR('P')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L) PORT_CHAR('l') PORT_CHAR('L')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON) PORT_CHAR(0x00F6) PORT_CHAR(0x00D6)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP) PORT_CHAR('.') PORT_CHAR(':')
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH) PORT_CHAR('-') PORT_CHAR('_')

	PORT_START("X5")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8) PORT_CHAR('8') PORT_CHAR('(')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7) PORT_CHAR('7') PORT_CHAR('/')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U) PORT_CHAR('u') PORT_CHAR('U')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I) PORT_CHAR('i') PORT_CHAR('I')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J) PORT_CHAR('j') PORT_CHAR('J')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K) PORT_CHAR('k') PORT_CHAR('K')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M) PORT_CHAR('m') PORT_CHAR('M')
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA) PORT_CHAR(',') PORT_CHAR(';')

	PORT_START("X6")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6) PORT_CHAR('6') PORT_CHAR('&')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5) PORT_CHAR('5') PORT_CHAR('%')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T) PORT_CHAR('t') PORT_CHAR('T')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y) PORT_CHAR('y') PORT_CHAR('Y')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G) PORT_CHAR('g') PORT_CHAR('G')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H) PORT_CHAR('h') PORT_CHAR('H')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B) PORT_CHAR('b') PORT_CHAR('B')
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N) PORT_CHAR('n') PORT_CHAR('N')

	PORT_START("X7")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("4 \xC2\xA4") PORT_CODE(KEYCODE_4) PORT_CHAR('4') PORT_CHAR(0x00A4)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3) PORT_CHAR('3') PORT_CHAR('#')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E) PORT_CHAR('e') PORT_CHAR('E')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R) PORT_CHAR('r') PORT_CHAR('R')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D) PORT_CHAR('d') PORT_CHAR('D')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F) PORT_CHAR('f') PORT_CHAR('F')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C) PORT_CHAR('c') PORT_CHAR('C')
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V) PORT_CHAR('v') PORT_CHAR('V')

	PORT_START("X8")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2) PORT_CHAR('2') PORT_CHAR('"')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1) PORT_CHAR('1') PORT_CHAR('!')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q) PORT_CHAR('q') PORT_CHAR('Q')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W) PORT_CHAR('w') PORT_CHAR('W')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A) PORT_CHAR('a') PORT_CHAR('A')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S) PORT_CHAR('s') PORT_CHAR('S')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z) PORT_CHAR('z') PORT_CHAR('Z')
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X) PORT_CHAR('x') PORT_CHAR('X')

	PORT_START("X9")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 9") PORT_CODE(KEYCODE_9_PAD) PORT_CHAR(UCHAR_MAMEKEY(9_PAD))
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad +") PORT_CODE(KEYCODE_PLUS_PAD) PORT_CHAR(UCHAR_MAMEKEY(PLUS_PAD))
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 6") PORT_CODE(KEYCODE_6_PAD) PORT_CHAR(UCHAR_MAMEKEY(6_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad -") PORT_CODE(KEYCODE_MINUS_PAD) PORT_CHAR(UCHAR_MAMEKEY(MINUS_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 3") PORT_CODE(KEYCODE_3_PAD) PORT_CHAR(UCHAR_MAMEKEY(3_PAD))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad RETURN") PORT_CODE(KEYCODE_ENTER_PAD) PORT_CHAR(UCHAR_MAMEKEY(ENTER_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad .") PORT_CODE(KEYCODE_DEL_PAD) PORT_CHAR(UCHAR_MAMEKEY(DEL_PAD))

	PORT_START("X10")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 7") PORT_CODE(KEYCODE_7_PAD) PORT_CHAR(UCHAR_MAMEKEY(7_PAD))
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 8") PORT_CODE(KEYCODE_8_PAD) PORT_CHAR(UCHAR_MAMEKEY(8_PAD))
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 4") PORT_CODE(KEYCODE_4_PAD) PORT_CHAR(UCHAR_MAMEKEY(4_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 5") PORT_CODE(KEYCODE_5_PAD) PORT_CHAR(UCHAR_MAMEKEY(5_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 1") PORT_CODE(KEYCODE_1_PAD) PORT_CHAR(UCHAR_MAMEKEY(1_PAD))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 2") PORT_CODE(KEYCODE_2_PAD) PORT_CHAR(UCHAR_MAMEKEY(2_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad 0") PORT_CODE(KEYCODE_0_PAD) PORT_CHAR(UCHAR_MAMEKEY(0_PAD))
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("X11")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF1") PORT_CODE(KEYCODE_F1) PORT_CHAR(UCHAR_MAMEKEY(F1))
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF2") PORT_CODE(KEYCODE_F2) PORT_CHAR(UCHAR_MAMEKEY(F2))
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF3") PORT_CODE(KEYCODE_F3) PORT_CHAR(UCHAR_MAMEKEY(F3))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF4") PORT_CODE(KEYCODE_F4) PORT_CHAR(UCHAR_MAMEKEY(F4))
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF5") PORT_CODE(KEYCODE_F5) PORT_CHAR(UCHAR_MAMEKEY(F5))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF6") PORT_CODE(KEYCODE_F6) PORT_CHAR(UCHAR_MAMEKEY(F6))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF7") PORT_CODE(KEYCODE_F7) PORT_CHAR(UCHAR_MAMEKEY(F7))
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("PF8") PORT_CODE(KEYCODE_F8) PORT_CHAR(UCHAR_MAMEKEY(F8))

	PORT_START("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Keyboard Program" )
	PORT_DIPSETTING(    0x00, "Internal (8048)" )
	PORT_DIPSETTING(    0x01, "External PROM" )
	PORT_DIPNAME( 0x02, 0x00, "Character Set" )
	PORT_DIPSETTING(    0x00, "Swedish" )
	PORT_DIPSETTING(    0x02, "US ASCII" )
	PORT_DIPNAME( 0x04, 0x04, "External PROM" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x18, 0x18, "Keyboard Language" )
	PORT_DIPSETTING(    0x00, "Danish" )
	PORT_DIPSETTING(    0x10, DEF_STR( French ) )
	PORT_DIPSETTING(    0x08, DEF_STR( German ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Spanish ) )
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED)
INPUT_PORTS_END


//-------------------------------------------------
//  input_ports - device-specific input ports
//-------------------------------------------------

const input_port_token *abc77_device_config::device_input_ports() const
{
	return INPUT_PORTS_NAME( abc77 );
}
		


//**************************************************************************
//  INLINE HELPERS
//**************************************************************************

//-------------------------------------------------
//  serial_output -
//-------------------------------------------------

inline void abc77_device::serial_output(int state)
{
	if (m_txd != state)
	{
		m_txd = state;

		devcb_call_write_line(&m_out_txd_func, m_txd);
	}
}


//-------------------------------------------------
//  serial_clock -
//-------------------------------------------------

inline void abc77_device::serial_clock()
{
	m_clock = !m_clock;

	devcb_call_write_line(&m_out_clock_func, m_clock);
}


//-------------------------------------------------
//  keydown -
//-------------------------------------------------

inline void abc77_device::key_down(int state)
{
	if (m_keydown != state)
	{
		devcb_call_write_line(&m_out_keydown_func, state);
		m_keydown = state;
	}
}



//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  abc77_device - constructor
//-------------------------------------------------

abc77_device::abc77_device(running_machine &_machine, const abc77_device_config &config)
    : device_t(_machine, config),
	  m_maincpu(*this, I8035_TAG),
	  m_discrete(*this, DISCRETE_TAG),
      m_config(config)
{
}


//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void abc77_device::device_start()
{
	// allocate timers
	m_serial_timer = timer_alloc(TIMER_SERIAL);
	m_serial_timer->adjust(MCS48_ALE_CLOCK(XTAL_4_608MHz*2), 0, MCS48_ALE_CLOCK(XTAL_4_608MHz*2));

	m_reset_timer = timer_alloc(TIMER_RESET);

	// resolve callbacks
    devcb_resolve_write_line(&m_out_txd_func, &m_config.m_out_txd_func, this);
    devcb_resolve_write_line(&m_out_clock_func, &m_config.m_out_clock_func, this);
    devcb_resolve_write_line(&m_out_keydown_func, &m_config.m_out_keydown_func, this);
}


//-------------------------------------------------
//  device_reset - device-specific reset
//-------------------------------------------------

void abc77_device::device_reset()
{
	int t = 1.1 * RES_K(100) * CAP_N(100) * 1000; // t = 1.1 * R1 * C1
	int ea = BIT(input_port_read(this, "DSW"), 7);

	// trigger reset
	device_set_input_line(m_maincpu, INPUT_LINE_RESET, ASSERT_LINE);
	m_reset_timer->adjust(attotime::from_msec(t));

	device_set_input_line(m_maincpu, MCS48_INPUT_EA, ea ? CLEAR_LINE : ASSERT_LINE);
}


//-------------------------------------------------
//  device_timer - handler timer events
//-------------------------------------------------

void abc77_device::device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr)
{
	switch (id)
	{
	case TIMER_SERIAL:
		serial_clock();
		break;
		
	case TIMER_RESET:
		device_set_input_line(m_maincpu, INPUT_LINE_RESET, CLEAR_LINE);
		break;
	}
}


//-------------------------------------------------
//  p1_r -
//-------------------------------------------------

READ8_MEMBER( abc77_device::p1_r )
{
	/*
	
		bit		description
		
		P10		Z17 Y0
		P11		Z17 Y1
		P12		Z17 Y2
		P13		Z17 Y3
		P14		Z17 Y4
		P15		Z17 Y5
		P16		Z17 Y6
		P17		Z17 Y7
		
	*/

	static const char *const keynames[] = { "X0", "X1", "X2", "X3", "X4", "X5", "X6", "X7", "X8", "X9", "X10", "X11" };

	return input_port_read(this, keynames[m_keylatch]);
}


//-------------------------------------------------
//  p2_w -
//-------------------------------------------------

WRITE8_MEMBER( abc77_device::p2_w )
{
	/*
	
		bit		description
		
		P20		Z2 A0
		P21		Z2 A1
		P22		Z2 A2
		P23		Z2 A3
		P24		NE556 2,6
		P25		TxD
		P26		_KEYDOWN
		P27		Z17 HYS
		
	*/

	m_keylatch = data & 0x0f;

	if (m_keylatch == 1)
	{
		watchdog_reset(m_machine);
	}

	// beep
	discrete_sound_w(m_discrete, NODE_01, BIT(data, 4));

	// transmit data
	serial_output(BIT(data, 5));

	// key down
	key_down(BIT(data, 6));

	// hysteresis
	m_hys = BIT(data, 7);
}


//-------------------------------------------------
//  t1_r -
//-------------------------------------------------

READ8_MEMBER( abc77_device::t1_r )
{
	return m_clock;
}


//-------------------------------------------------
//  rxd_w -
//-------------------------------------------------

WRITE_LINE_MEMBER( abc77_device::rxd_w )
{
	device_set_input_line(m_maincpu, MCS48_INPUT_IRQ, state ? CLEAR_LINE : ASSERT_LINE);
}


//-------------------------------------------------
//  txd_r -
//-------------------------------------------------

READ_LINE_MEMBER( abc77_device::txd_r )
{
	return m_txd;
}


//-------------------------------------------------
//  reset_w -
//-------------------------------------------------

WRITE_LINE_MEMBER( abc77_device::reset_w )
{
	if (m_reset && !state)
	{
		device_reset();
	}

	m_reset = state;
}