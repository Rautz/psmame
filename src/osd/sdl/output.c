//============================================================
//
//  output.c - Generic implementation of MAME output routines
//
//  Copyright Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//============================================================
#include <stdio.h>

// MAME headers
#include "emu.h"

// MAMEOS headers
#include "output.h"


//============================================================
//  CONSTANTS
//============================================================
#define SDLMAME_OUTPUT	"/dev_hdd0/game/MAME90000/USRDIR/mame.log"

//============================================================
//  PRIVATE VARIABLES
//============================================================
static FILE *output;

//============================================================
//  FUNCTION PROTOTYPES
//============================================================
static void sdloutput_exit(running_machine &machine);
static void notifier_callback(const char *outname, INT32 value, void *param);

//============================================================
//  sdloutput_init
//============================================================
void sdloutput_init(running_machine &machine)
{
	output = fopen(SDLMAME_OUTPUT, "w");
	machine.add_notifier(MACHINE_NOTIFY_EXIT, sdloutput_exit);
	output_set_notifier(NULL, notifier_callback, NULL);
}


//============================================================
//  winoutput_exit
//============================================================
static void sdloutput_exit(running_machine &machine)
{
	if(output)
	{
		fflush(output);
		fclose(output);
		output = NULL;
	}
}

//============================================================
//  notifier_callback
//============================================================
static void notifier_callback(const char *outname, INT32 value, void *param)
{
	if(output)
	{
		fprintf(output, "%s %d\n", outname, value);
	}
}

