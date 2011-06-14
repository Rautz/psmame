#include <es_system.h>

void			Exit		()
{
	QuitES();

	exit(0);
}

#ifdef __CELLOS_LV2__
# define	ROM_DIR		"/dev_hdd0/ROMS/mame"
# define	GAME_LIST	"/dev_hdd0/game/MAME90000/USRDIR/games.txt"
# define	LOG_FILE	"/dev_hdd0/game/MAME90000/USRDIR/mame.log"
#else
# define	ROM_DIR		"./ROMS"
# define	GAME_LIST	"./games.txt"
# define	LOG_FILE	"./mame.log"
#endif

void			LoadGameList		(const std::string& aFile, std::list<std::string>& aFiles, SummerfaceList_Ptr aGames)
{
	std::ifstream ist(aFile.c_str());
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
				SummerfaceItem_Ptr listitem = boost::make_shared<SummerfaceItem>(title, "");
				listitem->Properties["DRIVER"] = driver;
				listitem->IntProperties["SETNUM"] = atoi(setnumber.c_str());
				aGames->AddItem(listitem);

				aFiles.erase(file);
			}
		}
	}

	//Better show it
	if(aGames->GetItemCount() == 0)
	{
		ESSUB_Error("No supported games found.");
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
		}

		//List directory
		std::list<std::string> dirList;
		if(!Utility::ListDirectory(ROM_DIR, dirList) || dirList.size() == 0)
		{
			ESSUB_Error("Could not list ROM directory [" ROM_DIR "]");
			Exit();
		}
		for(std::list<std::string>::iterator i = dirList.begin(); i != dirList.end(); i ++)
		{
			*i = Utility::GetFileName(*i);
		}

		//Build the list
		SummerfaceList_Ptr linelist = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
		linelist->SetView(boost::make_shared<AnchoredListView>(linelist));
		LoadGameList(GAME_LIST, dirList, linelist);

		//Run the list
		Summerface_Ptr sface = Summerface::Create("games", linelist);
		sface->Do();

		//Handle result
		if(!linelist->WasCanceled())
		{
#ifndef __CELLOS_LV2__
//On non-ps3 just run mame
			printf("%d\n", linelist->GetSelected()->IntProperties["SETNUM"]);

			char command[1024];
			snprintf(command, 1024, "mame -rompath \"%s\" %s", ROM_DIR, linelist->GetSelected()->Properties["DRIVER"].c_str());
			system(command);
#else
//On ps3 run mame this way
			char bin[512];
			snprintf(bin, 512, "/dev_hdd0/game/MAME90000/USRDIR/mamebins/mame-%d.self", linelist->GetSelected()->IntProperties["SETNUM"]);

			cellFsChmod(bin, 0777);
			char* args[] = {"-rompath", ROM_DIR, strdup(linelist->GetSelected()->Properties["DRIVER"].c_str()), 0};
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

