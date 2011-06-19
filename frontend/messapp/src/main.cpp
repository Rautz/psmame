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

struct					MESSDevice
{
						MESSDevice						(TiXmlNode* aNode)
	{
		Name = TryXmlGetStringAttribute(aNode->ToElement(), "type");
		Tag = TryXmlGetStringAttribute(aNode->ToElement(), "tag");
		Mandatory = TryXmlGetIntAttribute(aNode->ToElement(), "mandatory", 0);
	}

	std::string			Name;
	std::string			Tag;
	int					Mandatory;
};

struct					MESSSystem : public SummerfaceItem
{
						MESSSystem						(TiXmlNode* aNode) : SummerfaceItem("", "")
	{
		Name = TryXmlGetStringAttribute(aNode->ToElement(), "name");
		SetText(Name);

		//Grab the devices
		if(aNode->FirstChild("device"))
		{
			for(TiXmlNode* devices = aNode->FirstChild("device"); devices; devices = devices->NextSibling())
			{
				if(strcmp(devices->Value(), "device") == 0)
				{
					Devices.push_back(MESSDevice(devices));
				}
			}
		}
	}

	std::string				Name;
	std::list<MESSDevice>	Devices;
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

			//HACK Get the file
			std::vector<std::string> nbm;
			FileSelect FileChooser("Select File", nbm, "", false);
			std::string filename = FileChooser.GetFile();

			//Don't continue if file chooser was canceled
			if(!filename.empty())
			{
#ifndef __CELLOS_LV2__
				char buffer[1024];
				snprintf(buffer, 1024, "xmess %s -cart \"%s\"", systemSelect->Name.c_str(), filename.c_str());
				system(buffer);
#else
				cellFsChmod("/dev_hdd0/game/MESS90000/USRDIR/mess.self", 0777);

				uint32_t onArg = 2;
				const char* args[32];
				memset(args, 0, sizeof(args));

				if(Settings::Cheats) 		args[onArg++] = "-cheat";
				if(Settings::SkipGameInfo)	args[onArg++] = "-skip_gameinfo";
				if(Settings::AutoSave)		args[onArg++] = "-autosave";
				if(Settings::AutoFrameSkip)	args[onArg++] = "-autoframeskip";

				sys_game_process_exitspawn2("/dev_hdd0/game/MESS90000/USRDIR/mess.self", (const char**)args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
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

