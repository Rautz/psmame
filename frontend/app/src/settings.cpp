#include <es_system.h>
#include "SimpleIni.h"

void Exit();

#include "settings.h"
#include "defines.h"


void					Settings::ChooseROMDirectory		()
{
	BookmarkList noMarks;
	FileSelect fs("Choose ROM Directory [Square to select]", noMarks, "/", true);
	std::string path = fs.GetFile();

	if(!path.empty() && Utility::DirectoryExists(path))
	{
		ROMPath = path;
		Dump();
		DeleteGameDatabase();
		RestartApp();
	}
}

void					Settings::DeleteGameDatabase		()
{
	if(Utility::FileExists(GAME_DB))
	{
		remove(GAME_DB);
	}
}

void					Settings::Do						()
{
	SummerfaceList_Ptr list = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
	list->SetView(boost::make_shared<AnchoredListView>(list));

	list->AddItem(boost::make_shared<SummerfaceItem>("Change ROM Directory", ""));
	list->AddItem(boost::make_shared<SummerfaceItem>("Rescan ROM Directory", ""));

	Summerface::Create("settings", list)->Do();
	bool wantRestart = false;

	if(!list->WasCanceled())
	{
		if(list->GetSelected()->GetText() == "Change ROM Directory")
		{
			ChooseROMDirectory();
		}

		if(wantRestart || list->GetSelected()->GetText() == "Rescan ROM Directory")
		{
			DeleteGameDatabase();
			RestartApp();
		}
	}
}

void					Settings::Read						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);

	ROMPath = std::string(ini.GetValue("psmame", "rompath", ROM_DIR));
	printf("%s\n", ROMPath.c_str());
}

void					Settings::Dump						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);
	ini.SetValue("psmame", "rompath", ROMPath.c_str());
	ini.SaveFile(CONFIG_FILE);	
}

void					Settings::RestartApp				()
{
#ifdef __CELLOS_LV2__
	sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", 0, 0, 0, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#else
	ESSUB_Error("Restart manually!");
	Exit();
#endif
}

std::string				Settings::ROMPath;
