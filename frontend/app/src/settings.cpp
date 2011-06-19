#include <es_system.h>
#include "SimpleIni.h"

void Exit();

#include "settings.h"
#include "defines.h"

class													BooleanItem : public SummerfaceItem
{
	public:
														BooleanItem						(const std::string& aText, int aValue) : SummerfaceItem(aText, "")
		{
			IntProperties["VALUE"] = aValue;
		}

		virtual											~BooleanItem					(){};

		virtual std::string								GetText							() {return SummerfaceItem::GetText() + " " + (IntProperties["VALUE"] ? "YES" : "NO");};

};

class													SettingView : public AnchoredListView
{
	public:
														SettingView						(SummerfaceList_WeakPtr aList) : AnchoredListView(aList) {}
		virtual											~SettingView					() {};
														
		virtual bool									Input							()
		{
			SummerfaceList_Ptr list = WeakList.lock();

			if(ESInput::ButtonDown(0, ES_BUTTON_LEFT) || ESInput::ButtonDown(0, ES_BUTTON_RIGHT))
			{
				list->GetSelected()->IntProperties["VALUE"] = !list->GetSelected()->IntProperties["VALUE"];
				return false;
			}

			if(ESInput::ButtonPressed(0, ES_BUTTON_LEFT) || ESInput::ButtonPressed(0, ES_BUTTON_RIGHT))
			{
				//Prevent paging.
				return false;
			}

			return AnchoredListView::Input();
		}
};


struct SettingDef
{
	const char*			ConfigName;
	const char*			Description;
	bool*				Value;
	SummerfaceItem_Ptr	Item;
};

SettingDef BoolSettings[] = 
{
	{"skipinfo", "Skip Game Info", &Settings::SkipGameInfo},
	{"cheats", "Enable Cheats", &Settings::Cheats},
	{"autosave", "Auto Save/Load State", &Settings::AutoSave},
	{"autoskip", "Enable Auto Frame Skip", &Settings::AutoFrameSkip},
};

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
	list->SetView(boost::make_shared<SettingView>(list));

	list->AddItem(boost::make_shared<SummerfaceItem>("Change ROM Directory", ""));
	list->AddItem(boost::make_shared<SummerfaceItem>("Rescan ROM Directory", ""));

	for(int i = 0; i != 4; i ++)
	{
		BoolSettings[i].Item = boost::make_shared<BooleanItem>(BoolSettings[i].Description, *(BoolSettings[i].Value));
		list->AddItem(BoolSettings[i].Item);
	}

	Summerface::Create("settings", list)->Do();
	bool wantRestart = false;

	for(int i = 0; i != 4; i ++)
	{
		*BoolSettings[i].Value = BoolSettings[i].Item->IntProperties["VALUE"];
	}

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

	Dump();
}

void					Settings::Read						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);

	ROMPath = std::string(ini.GetValue("psmame", "rompath", ROM_DIR));

	for(int i = 0; i != 4; i ++)
	{
		*BoolSettings[i].Value = ini.GetBoolValue("psmame", BoolSettings[i].ConfigName, false);
	}
}

void					Settings::Dump						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);
	ini.SetValue("psmame", "rompath", ROMPath.c_str());

	for(int i = 0; i != 4; i ++)
	{
		ini.SetBoolValue("psmame", BoolSettings[i].ConfigName, *BoolSettings[i].Value);
	}

	ini.SaveFile(CONFIG_FILE);	
}

void					Settings::RestartApp				()
{
	Dump();

#ifdef __CELLOS_LV2__
	sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", 0, 0, 0, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#else
	ESSUB_Error("Restart manually!");
	Exit();
#endif
}

std::string				Settings::ROMPath;
bool					Settings::Cheats;
bool					Settings::SkipGameInfo;
bool					Settings::AutoSave;
bool					Settings::AutoFrameSkip;

