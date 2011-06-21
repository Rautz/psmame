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

void return_to_loader(bool aError);

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
			sys_event_port_send(m_port, 1, 0, 0);
			m_thread->Wait();

			sys_event_port_disconnect(m_port);
			sys_event_port_destroy(m_port);

			sys_event_queue_destroy(m_queue, SYS_EVENT_QUEUE_DESTROY_FORCE);
		}

		static void tick(){ sys_event_port_send(m_port, 0, 0, 0); }

		static int threadfunc(void* aBcD)
		{
			sys_event_t event;

			while(true)
			{
				if(ETIMEDOUT == sys_event_queue_receive(m_queue, &event, 5000000))
				{
					if(m_done)
					{
						return 0;
					}

					CELL_Log("Watchdog activated: No updates for 5 seconds. Crashed?");
					return_to_loader(true);
				}

				if(event.data1)
				{
					return 0;
				}
			}
		}

	private:
		static sys_event_queue_t m_queue;
		static sys_event_port_t m_port;
		static bool m_done;
		static ESThread* m_thread;
};

#endif

