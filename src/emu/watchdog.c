/***************************************************************************

    watchdog.c

    Watchdog handling

    Copyright Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

***************************************************************************/

#include "emu.h"



/***************************************************************************
    GLOBAL VARIABLES
***************************************************************************/

static UINT8 watchdog_enabled;
static INT32 watchdog_counter;
static emu_timer *watchdog_timer;



/***************************************************************************
    FUNCTION PROTOTYPES
***************************************************************************/

static void watchdog_internal_reset(running_machine &machine);
static TIMER_CALLBACK( watchdog_callback );



/*-------------------------------------------------
    watchdog_init - one time initialization
-------------------------------------------------*/

void watchdog_init(running_machine &machine)
{
	/* allocate a timer for the watchdog */
	watchdog_timer = machine.scheduler().timer_alloc(FUNC(watchdog_callback));

	machine.add_notifier(MACHINE_NOTIFY_RESET, watchdog_internal_reset);

	/* save some stuff in the default tag */
	machine.state().save_item(NAME(watchdog_enabled));
	machine.state().save_item(NAME(watchdog_counter));
}


/*-------------------------------------------------
    watchdog_internal_reset - reset the watchdog
    system
-------------------------------------------------*/

static void watchdog_internal_reset(running_machine &machine)
{
	/* set up the watchdog timer; only start off enabled if explicitly configured */
	watchdog_enabled = (machine.config().m_watchdog_vblank_count != 0 || machine.config().m_watchdog_time != attotime::zero);
	watchdog_reset(machine);
	watchdog_enabled = TRUE;
}


/*-------------------------------------------------
    watchdog_callback - watchdog timer callback
-------------------------------------------------*/

static TIMER_CALLBACK( watchdog_callback )
{
	logerror("Reset caused by the watchdog!!!\n");

#ifdef MAME_DEBUG
	popmessage("Reset caused by the watchdog!!!\n");
#endif

	machine.schedule_soft_reset();
}


/*-------------------------------------------------
    on_vblank - updates VBLANK based watchdog
    timers
-------------------------------------------------*/

static void on_vblank(screen_device &screen, void *param, bool vblank_state)
{
	/* VBLANK starting */
	if (vblank_state && watchdog_enabled)
	{
		/* check the watchdog */
		if (screen.machine().config().m_watchdog_vblank_count != 0)
		{
			watchdog_counter = watchdog_counter - 1;

			if (watchdog_counter == 0)
				watchdog_callback(screen.machine(), NULL, 0);
		}
	}
}


/*-------------------------------------------------
    watchdog_reset - reset the watchdog timer
-------------------------------------------------*/

void watchdog_reset(running_machine &machine)
{
	/* if we're not enabled, skip it */
	if (!watchdog_enabled)
		watchdog_timer->adjust(attotime::never);

	/* VBLANK-based watchdog? */
	else if (machine.config().m_watchdog_vblank_count != 0)
	{
		watchdog_counter = machine.config().m_watchdog_vblank_count;

		/* register a VBLANK callback for the primary screen */
		if (machine.primary_screen != NULL)
			machine.primary_screen->register_vblank_callback(on_vblank, NULL);
	}

	/* timer-based watchdog? */
	else if (machine.config().m_watchdog_time != attotime::zero)
		watchdog_timer->adjust(machine.config().m_watchdog_time);

	/* default to an obscene amount of time (3 seconds) */
	else
		watchdog_timer->adjust(attotime::from_seconds(3));
}


/*-------------------------------------------------
    watchdog_enable - reset the watchdog timer
-------------------------------------------------*/

void watchdog_enable(running_machine &machine, int enable)
{
	/* when re-enabled, we reset our state */
	if (watchdog_enabled != enable)
	{
		watchdog_enabled = enable;
		watchdog_reset(machine);
	}
}
