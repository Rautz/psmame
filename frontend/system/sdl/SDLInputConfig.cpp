#include <es_system.h>

namespace SDLInputConfig
{
	bool					Running = false;

	void					Load				(uint32_t* aData)
	{
		std::string output = es_paths->Build("inputconfig");
		FILE* configFile = fopen(output.c_str(), "r");

		if(!configFile)
		{
			memset(aData, 0, 14 * 4);
		}
		else
		{
			for(int i = 0; i != 14; i ++)
			{
				fscanf(configFile, "%08X\n", &aData[i]);
			}

			fclose(configFile);
		}
	}

	void					Dump				(uint32_t* aData)
	{
		std::string output = es_paths->Build("inputconfig");
		FILE* configFile = fopen(output.c_str(), "w");

		for(int i = 0; i != 14; i ++)
		{
			fprintf(configFile, "%08X\n", aData[i]);
		}

		fclose(configFile);
	}

	bool					GetButton			(void* aUserData, Summerface_Ptr aInterface, const std::string& aWindow)
	{
		static bool gotbutton = true;

		if(gotbutton && ESInput::GetAnyButton(0) != 0xFFFFFFFF)
		{
			return false;
		}

		gotbutton = false;

		uint32_t* button = (uint32_t*)aUserData;
		button[0] = ESInput::GetAnyButton(0);
		gotbutton = (button[0] != 0xFFFFFFFF) ? true : false;
		return gotbutton;
	}

	void					Get					(uint32_t* aData)
	{
		if(Running)
		{
			return;
		}

		Running = true;

		const char* buttons[] = {"Up", "Down", "Left", "Right", "Accept", "Cancel", "Shift", "Tab", "AuxLeft1", "AuxRight1", "AuxLeft2", "AuxRight2", "AuxLeft3", "AuxRight3"};

		uint32_t buttonID;
		SummerfaceLabel_Ptr button = boost::make_shared<SummerfaceLabel>(Area(10, 30, 80, 10), "");
		button->SetInputConduit(boost::make_shared<SummerfaceStaticConduit>(GetButton, &buttonID));

		Summerface_Ptr sface = Summerface::Create("InputWindow", button);

		for(int j = 0; j != 14; j ++)
		{
			button->SetMessage("Press button for [%s]", buttons[j]);
			sface->Do();

			aData[j] = buttonID;
		}

		Dump(aData);

		Running = false;
	}
};
