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
	{"autoskip", "Enable Auto Frame Skip", &Settings::AutoFrameSkip},
};

void					Settings::Do						()
{
	SummerfaceList_Ptr list = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
	list->SetView(boost::make_shared<SettingView>(list));

	for(int i = 0; i != 3; i ++)
	{
		BoolSettings[i].Item = boost::make_shared<BooleanItem>(BoolSettings[i].Description, *(BoolSettings[i].Value));
		list->AddItem(BoolSettings[i].Item);
	}

	Summerface::Create("settings", list)->Do();
	bool wantRestart = false;

	for(int i = 0; i != 3; i ++)
	{
		*BoolSettings[i].Value = BoolSettings[i].Item->IntProperties["VALUE"];
	}

	Dump();
}

void					Settings::Read						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);

	for(int i = 0; i != 3; i ++)
	{
		*BoolSettings[i].Value = ini.GetBoolValue("psmess", BoolSettings[i].ConfigName, false);
	}
}

void					Settings::Dump						()
{
	CSimpleIniA ini;
	ini.LoadFile(CONFIG_FILE);

	for(int i = 0; i != 3; i ++)
	{
		ini.SetBoolValue("psmess", BoolSettings[i].ConfigName, *BoolSettings[i].Value);
	}

	ini.SaveFile(CONFIG_FILE);	
}

void					Settings::RestartApp				()
{
	Dump();

#ifdef __CELLOS_LV2__
	sys_game_process_exitspawn2("/dev_hdd0/game/MESS90000/USRDIR/frontend.self", 0, 0, 0, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#else
	ESSUB_Error("Restart manually!");
	Exit();
#endif
}

bool					Settings::Cheats;
bool					Settings::SkipGameInfo;
bool					Settings::AutoFrameSkip;

