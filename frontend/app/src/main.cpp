#include <es_system.h>

void			Exit		()
{
	exit(0);
}

#ifdef __CELLOS_LV2__
# define	ROM_DIR		"/dev_hdd0/game/MAME90000/USRDIR/ROMS"
# define	GAME_LIST	"/dev_hdd0/game/MAME90000/USRDIR/games.txt"
#else
# define	ROM_DIR		"./ROMS"
# define	GAME_LIST	"./games.txt"
#endif

void			LoadGameList		(const std::string& aFile, std::map<std::string, std::string>& aGames)
{
	std::ifstream ist(aFile.c_str());

	while(ist.good() && !ist.eof())
	{
		std::string line;
		std::getline(ist, line);

		if(!line.empty())
		{
			std::string driver = line.substr(0, line.find_first_of(" "));
			std::string title = line.substr(line.find("\"") + 1);
			title.erase(title.end() - 1);

			aGames[driver] = title;
		}
	}

	//Better show it
	if(aGames.size() == 0)
	{
		ESSUB_Error("Could not read game list.");
		Exit();
	}
}

int				main		(int argc, char** argv)
{
	try
	{
		InitES(Exit);

		std::map<std::string, std::string> gameList;
		LoadGameList(GAME_LIST, gameList);

		std::vector<std::string> dirList;
		if(!Utility::ListDirectory(ROM_DIR, dirList) || dirList.size() == 0)
		{
			ESSUB_Error("Could not list ROM directory");
			Exit();
		}

		//Build the list
		SummerfaceList_Ptr linelist = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
		linelist->SetView(boost::make_shared<AnchoredListView>(linelist));

		for(std::vector<std::string>::iterator i = dirList.begin(); i != dirList.end(); i ++)
		{
			std::string item = Utility::GetFileName(*i);

			if(gameList.find(item) != gameList.end())
			{
				SummerfaceItem_Ptr listitem = boost::make_shared<SummerfaceItem>(gameList[item], "");
				listitem->Properties["DRIVER"] = item;
				linelist->AddItem(listitem);
			}
		}

		//Run the list
		Summerface_Ptr sface = Summerface::Create("games", linelist);
		sface->Do();

		//Handle result
		if(!linelist->WasCanceled())
		{
#ifndef __CELLOS_LV2__
//On non-ps3 just run mame
			char command[1024];
			snprintf(command, 1024, "mame -rompath \"%s\" %s", ROM_DIR, linelist->GetSelected()->Properties["DRIVER"].c_str());
			system(command);
#else
//On ps3 run mame this way
			cellFsChmod("/dev_hdd0/game/MAME90000/USRDIR/mame.self", 0777);

			char* args[] = {"-rompath", ROM_DIR, strdup(linelist->GetSelected()->Properties["DRIVER"].c_str()), 0};
			sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/mame.self", (const char**)args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#endif
		}

		Exit();
	}
	catch(...)
	{
		Exit();
	}
}
