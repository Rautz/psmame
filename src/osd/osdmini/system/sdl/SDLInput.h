#ifndef SDLINPUT_H
#define SDLINPUT_H

enum
{
	ES_BUTTON_UP = 0xFFFFFF00, ES_BUTTON_DOWN, ES_BUTTON_LEFT, ES_BUTTON_RIGHT, ES_BUTTON_ACCEPT, ES_BUTTON_CANCEL,
	ES_BUTTON_SHIFT, ES_BUTTON_TAB, ES_BUTTON_AUXLEFT1, ES_BUTTON_AUXRIGHT1, ES_BUTTON_AUXLEFT2, ES_BUTTON_AUXRIGHT2, 
	ES_BUTTON_AUXLEFT3, ES_BUTTON_AUXRIGHT3, 
};

class				ESInput
{
	friend class							ESVideo;

	public:
		static void							Initialize				();
		static void							Shutdown				();
					
		static uint32_t						PadCount				() {return Joysticks.size() ? Joysticks.size() : 1;};
		static inline void					Reset					(); //Below
		static void							Refresh					();
		
		static int32_t						GetAxis					(uint32_t aPad, uint32_t aAxis) {return 0;}

		static inline bool					ButtonPressed			(uint32_t aPad, uint32_t aButton); //Below
		static inline bool					ButtonDown				(uint32_t aPad, uint32_t aButton); //Below
		
		static inline uint32_t				GetAnyButton			(uint32_t aPad); //Below
		static inline std::string			GetButtonName			(uint32_t aButton); //Below
		static std::string					GetButtonImage			(uint32_t aButton) {return "NOIMAGE";}

		static void							RumbleOn				(uint32_t aBig, uint32_t aSmall) {};
	
	protected:
		static const uint32_t				MAXKEYS = 512;
		static const uint32_t				MAXPADS = 4;
		static const uint32_t				BUTTONS = 128;
		static const uint32_t				AXISCOUNT = 8;
	
		static bool							IsJoystickButton		(uint32_t aButton) {return (aButton >> 16) == 0;};
		
		static std::vector<SDL_Joystick*>	Joysticks;
		static uint32_t						ESInputs[14];

		static uint32_t						KeyState[MAXKEYS];
		static uint32_t						KeySingle[MAXKEYS];

		static uint32_t						HeldState[MAXPADS][BUTTONS];
		static uint32_t						SingleState[MAXPADS][BUTTONS];	
};

//Inlines
void										ESInput::Reset			()
{
	memset(HeldState, 0xFF, sizeof(HeldState));
	memset(SingleState, 0xFF, sizeof(SingleState));
	
	memset(KeyState, 0xFF, sizeof(KeyState));
	memset(KeySingle, 0xFF, sizeof(KeySingle));
}

bool										ESInput::ButtonPressed	(uint32_t aPad, uint32_t aButton)
{
	if((aButton & 0xFF000000) == 0xFF000000 && (aButton & 0xFF) < 14)
	{
		aButton = ESInputs[aButton & 0xFF];
	}

	if(!IsJoystickButton(aButton) && aPad == 0)
	{
		return KeyState[aButton & 0xFFFF] == 1;
	}
	else
	{
		return HeldState[aPad][aButton & 0xFFFF] == 1;
	}
}

bool										ESInput::ButtonDown		(uint32_t aPad, uint32_t aButton)
{
	if((aButton & 0xFF000000) == 0xFF000000 && (aButton & 0xFF) < 14)
	{
		aButton = ESInputs[aButton & 0xFF];
	}

	if(!IsJoystickButton(aButton) && aPad == 0)
	{
		return ESInputHelp::HandleSingleState(KeyState[aButton & 0xFFFF], KeySingle[aButton & 0xFFFF]);
	}
	else
	{
		return ESInputHelp::HandleSingleState(HeldState[aPad][aButton & 0xFFFF], SingleState[aPad][aButton & 0xFFFF]);	
	}
}

uint32_t									ESInput::GetAnyButton	(uint32_t aPad)
{
	if(aPad == 0)
	{
		for(int i = 0; i != MAXKEYS; i ++)
		{
			if(KeyState[i] == 1)
			{
				return (1 << 16) | i;
			}
		}
	}

	if(Joysticks.size() > aPad)
	{
		for(int i = 0; i != (SDL_JoystickNumAxes(Joysticks[aPad]) * 2 + SDL_JoystickNumHats(Joysticks[aPad]) * 4 + SDL_JoystickNumButtons(Joysticks[aPad])); i ++)
		{
			if(HeldState[aPad][i] == 1)
			{
				return i;
			}
		}
	}

	return 0xFFFFFFFF;
}

std::string									ESInput::GetButtonName	(uint32_t aButton)
{
	if(!IsJoystickButton(aButton))
	{
		return SDL_GetKeyName((SDLKey)(aButton & 0xFFFF));
	}
	else
	{
		//TODO: Return real string
		return std::string("JSBUTTON");
	}
}

#endif

