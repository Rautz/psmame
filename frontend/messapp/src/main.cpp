#include <es_system.h>
#include "defines.h"
#include "settings.h"

#include "tinyxml/tinyxml.h"

inline int32_t			TryXmlGetIntAttribute		(const TiXmlElement* aAttribute, const char* aName)
{
	int value;
//TODO: Make more descriptive
	ErrorCheck(aAttribute && TIXML_SUCCESS == aAttribute->QueryIntAttribute(aName, &value), "Generic XML Int Attribute Error [Data: %s]", aName);
	return value;
}

inline int32_t			TryXmlGetIntAttribute		(const TiXmlElement* aAttribute, const char* aName, uint32_t aDefault)
{
	int value;
	return (aAttribute && TIXML_SUCCESS == aAttribute->QueryIntAttribute(aName, &value)) ? value : aDefault;
}

inline const char*		TryXmlGetStringAttribute	(const TiXmlElement* aAttribute, const char* aName)
{
//TODO: Make more descriptive
	ErrorCheck(aAttribute && 0 != aAttribute->Attribute(aName), "Generic XML String Attribute Error [Data: %s]", aName);
	return aAttribute->Attribute(aName);
}

inline const char*		TryXmlGetStringAttribute	(const TiXmlElement* aAttribute, const char* aName, const char* aDefault)
{
	return (aAttribute && 0 != aAttribute->Attribute(aName)) ? aAttribute->Attribute(aName) : aDefault;
}

struct					MESSDevice : public SummerfaceItem
{
						MESSDevice						(TiXmlNode* aNode) : SummerfaceItem("", ""),
		Name(TryXmlGetStringAttribute(aNode->ToElement(), "type")),
		Tag(TryXmlGetStringAttribute(aNode->ToElement(), "tag")),
		File(""),
		Mandatory(TryXmlGetIntAttribute(aNode->ToElement(), "mandatory", 0))
	{
		SetText(Name);
		SetImage(Mandatory ? "mandatoryICON" : "optionalICON");
	}

	virtual std::string	GetText							()
	{
		return Name + "  [" + File + "]";
	}

	std::string			Name;
	std::string			Tag;
	std::string			File;
	int					Mandatory;
};

struct					MESSSystem : public SummerfaceItem
{
						MESSSystem						(TiXmlNode* aNode) : SummerfaceItem("", ""),
		Name(TryXmlGetStringAttribute(aNode->ToElement(), "name")),
		Devices(boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80)))
	{
		Devices->SetView(boost::make_shared<AnchoredListView>(Devices));
		SetText(aNode->FirstChild("description")->ToElement()->GetText());
//TODO: Set icon based on status
		//Grab the devices
		if(aNode->FirstChild("device"))
		{
			for(TiXmlNode* devices = aNode->FirstChild("device"); devices; devices = devices->NextSibling())
			{
				if(strcmp(devices->Value(), "device") == 0)
				{
					Devices->AddItem(boost::make_shared<MESSDevice>(devices));
				}
			}
		}

		Devices->AddItem(boost::make_shared<SummerfaceItem>("Boot MESS", ""));
	}

	bool				FillDevices						(std::vector<const char*>& aArguments)
	{
		std::vector<std::string> nbm;
		Summerface_Ptr sface = Summerface::Create("devices", Devices);
		FileSelect FileChooser("Select File", nbm, "", false);

		while(true)
		{
			sface->Do();

			if(Devices->WasCanceled())
			{
				return false;
			}

			if(Devices->GetSelected()->GetText() == "Boot MESS")
			{
				aArguments.push_back(strdup(Name.c_str()));

				for(int i = 0; i != Devices->GetItemCount(); i ++)
				{
					boost::shared_ptr<MESSDevice> Device = boost::static_pointer_cast<MESSDevice>(Devices->GetItem(i));

					if(Device->GetText() != "Boot MESS" && Device->File.size())
					{
						aArguments.push_back(strdup((std::string("-") + Device->Tag).c_str()));
						aArguments.push_back(strdup((std::string("\"") + Device->File + "\"").c_str()));
					}
				}

				return true;
			}

			boost::shared_ptr<MESSDevice> Device = boost::static_pointer_cast<MESSDevice>(Devices->GetSelected());
			Device->File = FileChooser.GetFile();
		}
	}

	std::string				Name;
	SummerfaceList_Ptr		Devices;
};

void			Exit		()
{
	QuitES();

	exit(0);
}

//Override list view to support settings menu
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

SummerfaceList_Ptr	SystemList;
boost::shared_ptr<MESSSystem>	DoSystemsList		()
{
	if(!SystemList)
	{
		//Load the systems file
		TiXmlDocument doc(SYSTEM_XML);
		if(!doc.LoadFile())
		{
			ESSUB_Error("Couldn't read systems.xml, reinstalling the package should fix this.");
			Exit();
		}

		if(!doc.FirstChild("mess") || !doc.FirstChild("mess")->FirstChild("machine"))
		{
			ESSUB_Error("Couldn't parse systems.xml, reinstalling the package should fix this.");
			Exit();
		}

		//Build the list
		SystemList = boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80));
		SystemList->SetView(boost::make_shared<MAMEListView>(SystemList));

		for(TiXmlNode* machines = doc.FirstChild("mess")->FirstChild("machine"); machines; machines = machines->NextSibling())
		{
			SystemList->AddItem(boost::make_shared<MESSSystem>(machines));
		}

		SystemList->Sort();
	}

	//Run the list and return the result
	Summerface::Create("games", SystemList)->Do();
	return SystemList->WasCanceled() ? boost::shared_ptr<MESSSystem>() : boost::static_pointer_cast<MESSSystem>(SystemList->GetSelected());
}

#ifndef __CELLOS_LV2__
static std::string				VectorToString				(std::vector<const char*>& aStrings, char aSeparate)
{
	std::string output;
	
	for(std::vector<const char*>::iterator i = aStrings.begin(); i != aStrings.end(); i ++)
	{
		output += (*i) + std::string(1, aSeparate);
	}
	
	return output.substr(0, output.length() - 1);
}
#endif

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

			remove(LOG_FILE);
		}

		Settings::Read();

		std::vector<const char*> arguments;
#ifdef __CELLOS_LV2__
		arguments.push_back("-rompath");
		arguments.push_back("/dev_hdd0/ROMS/mess_data/bios");
#else
		arguments.push_back("/chroot/ps3dev/home/jason/ps3dev/mame-pc/mess64");
		arguments.push_back("-rompath");
		arguments.push_back("\"/opt/media/Games/MESS ROMS\"");
#endif

		//Wait to start game
		while(true)
		{
			//Get a system
			boost::shared_ptr<MESSSystem> systemSelect = DoSystemsList();

			//Systems was canceled, bail
			if(!systemSelect)
			{
				Exit();
			}

			//Fill the devies
			if(systemSelect->FillDevices(arguments))
			{
				if(Settings::Cheats) 		arguments.push_back("-cheat");
				if(Settings::SkipGameInfo)	arguments.push_back("-skip_gameinfo");
				if(Settings::AutoFrameSkip)	arguments.push_back("-autoframeskip");

#ifndef __CELLOS_LV2__
				std::string argString = VectorToString(arguments, ' ');
				system(argString.c_str());
#else
				arguments.push_back(0);
				cellFsChmod("/dev_hdd0/game/MESS90000/USRDIR/mess.self", 0777);
				sys_game_process_exitspawn2("/dev_hdd0/game/MESS90000/USRDIR/mess.self", (const char**)&arguments[0], NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
#endif
			}
		}

		Exit();
	}
	catch(...)
	{
		Exit();
	}
}

