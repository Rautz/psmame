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
														MAMEListView					(SummerfaceList_WeakPtr aList) : AnchoredListView(aList), NeedSwitch(1), SwitchTime(0){};
														~MAMEListView					() {};
														
		virtual bool									Input							()
		{
			SummerfaceList_Ptr List = WeakList.lock();
			uint32_t currentItem = List->GetSelection();

			bool result = AnchoredListView::Input();

			//Scroll to next letter
			if(ESInput::ButtonPressed(0, ES_BUTTON_AUXRIGHT1) || ESInput::ButtonPressed(0, ES_BUTTON_AUXLEFT1))
			{
				bool goingUp = ESInput::ButtonPressed(0, ES_BUTTON_AUXLEFT1);
				char starter = List->GetSelected()->GetText()[0];

				while(List->GetSelection() != (goingUp ? 0 : (List->GetItemCount() - 1)))
				{
					if(List->GetSelected()->GetText()[0] != starter)
					{
						break;
					}

					List->SetSelection(List->GetSelection() + (goingUp ? -1 : 1));
				}
			}

			//Settings
			if(ESInput::ButtonDown(0, ES_BUTTON_AUXRIGHT3))
			{
				Settings::Do();
			}

			//Start image update
			if(currentItem != List->GetSelection())
			{
				SwitchTime = Utility::GetTicks();
				NeedSwitch = 1;

				SummerfaceImage_Ptr image = boost::static_pointer_cast<SummerfaceImage>(List->GetInterface()->GetWindow("snapshot"));
				image->SetImage("");
			}

			//Finish image image after 250 ms
			if(NeedSwitch && ((Utility::GetTicks() - SwitchTime) > 250))
			{
				char buff[1024];
				snprintf(buff, 1024, SNAP_DIR"/%s.png", List->GetSelected()->Properties["DRIVER"].c_str());

				SummerfaceImage_Ptr image = boost::static_pointer_cast<SummerfaceImage>(List->GetInterface()->GetWindow("snapshot"));
				ImageManager::LoadImage(List->GetSelected()->Properties["DRIVER"], buff);
				image->SetImage(List->GetSelected()->Properties["DRIVER"]);

				NeedSwitch = 0;
			}

			return result;
		}

		uint32_t										NeedSwitch;
		uint32_t										SwitchTime;
};


void						MakeGameDatabase			(std::list<std::string>& aFiles)
{
	std::ofstream ost(GAME_DB);
	std::ifstream ist(GAME_LIST);
	bool someFound = false;

	if(!ist.good())
	{
		ESSUB_Error("Could not read games.txt. Reinstalling the package should fix this.");
		Exit();
	}

	while(ist.good() && !ist.eof())
	{
		std::string line;
		std::getline(ist, line);

		if(!line.empty())
		{
			std::string setnumber = line.substr(0, 2);
			std::string driver = line.substr(3, line.find_first_of(" ", 3) - 3);
			std::string title = line.substr(line.find("\"") + 1);
			title.erase(title.end() - 1);

			std::list<std::string>::iterator file = std::find(aFiles.begin(), aFiles.end(), driver);
			if(file != aFiles.end())
			{
				ost << line << "\n";
				someFound = true;
				aFiles.erase(file);
			}
		}
	}

	//Better show it
	if(!someFound)
	{
		ESSUB_Error("No supported games found. Please select the path to your ROMs");
		Settings::ChooseROMDirectory();
		Exit();
	}
}

void			LoadGameDatabase	(SummerfaceList_Ptr aGames)
{
	std::ifstream ist(GAME_DB);

	if(!ist.good())
	{
		ESSUB_Error("Could not read gamedb.");
		Exit();
	}

	while(ist.good() && !ist.eof())
	{
		std::string line;
		std::getline(ist, line);

		if(!line.empty())
		{
			std::string setnumber = line.substr(0, 2);
			std::string driver = line.substr(3, line.find_first_of(" ", 3) - 3);
			std::string title = line.substr(line.find("\"") + 1);
			title.erase(title.end() - 1);

			SummerfaceItem_Ptr listitem = boost::make_shared<SummerfaceItem>(title, "");
			listitem->Properties["DRIVER"] = driver;
			listitem->IntProperties["SETNUM"] = atoi(setnumber.c_str());
			aGames->AddItem(listitem);
		}
	}

	//Better show it
	if(aGames->GetItemCount() == 0)
	{
		ESSUB_Error("No supported games found. Please select the path to your ROMs");
		Settings::ChooseROMDirectory();
		Exit();
	}
}


int				main		(int argc, char** argv)
{
	try
	{
		InitES(Exit);

		if(argc > 1 && strcmp(argv[1], "-showlog") == 0)
		{
			boost::shared_ptr<TextViewer> tview = boost::make_shared<TextViewer>(Area(10, 10, 80, 80), LOG_FILE);
			tview->SetHeader("MAME Log");
			Summerface::Create("Viewer", tview)->Do();

			remove(LOG_FILE);
		}

		Settings::Read();

		//Build the game database, if needed
		if(!Utility::FileExists(GAME_DB))
		{
			//List directory
			std::list<std::string> dirList;
			if(!Utility::ListDirectory(Settings::ROMPath, dirList) || dirList.size() == 0)
			{
				ESSUB_Error("Could not list ROM directory");
				Settings::ChooseROMDirectory();
				Exit();
			}

			for(std::list<std::string>::iterator i = dirList.begin(); i != dirList.end(); i ++)
			{
				*i = Utility::GetFileName(*i);
			}

			//Build the database
			MakeGameDatabase(dirList);
		}

		//Build the list
		SummerfaceList_Ptr linelist = boost::make_shared<SummerfaceList>(Area(10, 10, 50, 80));
		linelist->SetView(boost::make_shared<MAMEListView>(linelist));
		LoadGameDatabase(linelist);
		linelist->Sort();

		SummerfaceImage_Ptr snap = boost::make_shared<SummerfaceImage>(Area(60, 10, 30, 80), "");
		snap->SetHeader("Press [R3] for options");

		//Run the list
		Summerface_Ptr sface = Summerface::Create("games", linelist);
		sface->AddWindow("snapshot", snap);
		sface->SetActiveWindow("games");
		sface->Do();

		//Handle result
		if(!linelist->WasCanceled())
		{
#ifndef __CELLOS_LV2__
//On non-ps3 just run mame
			printf("%d\n", linelist->GetSelected()->IntProperties["SETNUM"]);

			char command[1024];
			snprintf(command, 1024, "mame -rompath \"%s\" %s", Settings::ROMPath.c_str(), linelist->GetSelected()->Properties["DRIVER"].c_str());
			system(command);
#else
//On ps3 run mame this way
			char bin[512];
			snprintf(bin, 512, "/dev_hdd0/game/MAME90000/USRDIR/mamebins/mame-%d.self", linelist->GetSelected()->IntProperties["SETNUM"]);

			cellFsChmod(bin, 0777);

			uint32_t onArg = 2;
			const char* args[32] = {"-rompath", Settings::ROMPath.c_str()};
			if(Settings::Cheats) 		args[onArg++] = "-cheat";
			if(Settings::SkipGameInfo)	args[onArg++] = "-skip_gameinfo";
			if(Settings::AutoFrameSkip)	args[onArg++] = "-autoframeskip";
			args[onArg++] = strdup(linelist->GetSelected()->Properties["DRIVER"].c_str());

			sys_game_process_exitspawn2(bin, (const char**)args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#endif
		}

		Exit();
	}
	catch(...)
	{
		Exit();
	}
}

