#include <es_system.h>
#include "defines.h"
#include "settings.h"


void			Exit		()
{
	QuitES();

	exit(0);
}

class													MAMEListView : public AnchoredListView
{
	public:
														MAMEListView					(SummerfaceList_WeakPtr aList) : AnchoredListView(aList){};
														~MAMEListView					() {};
														
		virtual bool									Input							()
		{
			bool result = AnchoredListView::Input();

			//Settings
			if(ESInput::ButtonDown(0, ES_BUTTON_AUXRIGHT3))
			{
				Settings::Do();
			}

			return result;
		}
};

int				main		(int argc, char** argv)
{
	try
	{
		InitES(Exit);

		if(argc > 1 && strcmp(argv[1], "-showlog") == 0)
		{
			boost::shared_ptr<TextViewer> tview = boost::make_shared<TextViewer>(Area(10, 10, 80, 80), LOG_FILE);
			tview->SetHeader("MESS Log");
			Summerface::Create("Viewer", tview)->Do();
		}

		Settings::Read();

		//Build the list
		SummerfaceList_Ptr linelist = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
		linelist->SetView(boost::make_shared<MAMEListView>(linelist));

		//TODO: Add list items

		linelist->Sort();

		//Run the list
		Summerface_Ptr sface = Summerface::Create("games", linelist);
		sface->Do();

		//Handle result
		if(!linelist->WasCanceled())
		{
#ifndef __CELLOS_LV2__
//On non-ps3 just run mame
#else
//On ps3 run mame this way
			cellFsChmod("/dev_hdd0/game/MESS90000/USRDIR/mess.self", 0777);

			uint32_t onArg = 2;
			const char* args[32] = {"-rompath", Settings::ROMPath.c_str()};
			if(Settings::Cheats) 		args[onArg++] = "-cheat";
			if(Settings::SkipGameInfo)	args[onArg++] = "-skip_gameinfo";
			if(Settings::AutoSave)		args[onArg++] = "-autosave";
			if(Settings::AutoFrameSkip)	args[onArg++] = "-autoframeskip";

			sys_game_process_exitspawn2("/dev_hdd0/game/MESS90000/USRDIR/mess.self", (const char**)args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#endif
		}

		Exit();
	}
	catch(...)
	{
		Exit();
	}
}

