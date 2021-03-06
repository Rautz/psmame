/***************************************************************************

CuboCD32 definitions

***************************************************************************/

#ifndef __CUBOCD32_H__
#define __CUBOCD32_H__

#include "includes/amiga.h"

class cd32_state : public amiga_state
{
public:
	cd32_state(running_machine &machine, const driver_device_config_base &config)
		: amiga_state(machine, config) { }

	UINT16 m_potgo_value;
	int m_cd32_shifter[2];
	void (*m_input_hack)(running_machine &machine);
	int m_oldstate[2];
};

/*----------- defined in machine/cd32.c -----------*/

READ32_DEVICE_HANDLER( amiga_akiko32_r );
WRITE32_DEVICE_HANDLER( amiga_akiko32_w );

DECLARE_LEGACY_DEVICE(AKIKO, akiko);

#endif /* __CUBOCD32_H__ */
