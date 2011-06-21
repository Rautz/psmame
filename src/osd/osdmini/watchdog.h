#ifndef _watchdog_h_
#define _watchdog_h_
//============================================================
//
//  watchdog.h - watchdog handling
//
//  Copyright (c) 1996-2011, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

#include <es_system.h>
#include <sys/event.h>

class watchdog
{
	public:
		static void init(void)
		{
			sys_event_queue_attribute_t attr;
			sys_event_queue_attribute_initialize(attr);
			sys_event_queue_create(&m_queue, &attr, SYS_EVENT_QUEUE_LOCAL, 1);

			sys_event_port_create(&m_port, SYS_EVENT_PORT_LOCAL, 1);
			sys_event_port_connect_local(m_port, m_queue);

			m_thread = es_threads->MakeThread(threadfunc, 0);
		}

		static void quit(void)
		{
			m_done = true;
			m_thread->Wait();

			sys_event_port_disconnect(m_port);
			sys_event_port_destroy(m_port);

			sys_event_queue_destroy(m_queue, SYS_EVENT_QUEUE_DESTROY_FORCE);
		}

		static void tick(){ sys_event_port_send(m_port, 0, 0, 0); }

		static int threadfunc(void* aBcD)
		{
			sys_event_t event;

			while(!m_done)
			{
				if(ETIMEDOUT == sys_event_queue_receive(m_queue, &event, 5000000))
				{
					if(m_done)
					{
						return 0;
					}

					const char* args[2] = {"-showlog", 0};
					CELL_Log("Watchdog activated: No updates for 5 seconds. Crashed?");
#ifdef MESS
					sys_game_process_exitspawn2("/dev_hdd0/game/MESS90000/USRDIR/frontend.self", args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#else
					sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#endif
				}
			}

			return 0;
		}

	private:
		static sys_event_queue_t m_queue;
		static sys_event_port_t m_port;
		static bool m_done;
		static ESThread* m_thread;
};

#endif

