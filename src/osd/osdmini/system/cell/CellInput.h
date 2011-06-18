#pragma once

enum
{
	ES_BUTTON_UP = 6, ES_BUTTON_DOWN = 7, ES_BUTTON_LEFT = 8, ES_BUTTON_RIGHT = 9, ES_BUTTON_ACCEPT = 3, ES_BUTTON_CANCEL = 5,
	ES_BUTTON_SHIFT = 2, ES_BUTTON_TAB = 4, ES_BUTTON_AUXLEFT1 = 10, ES_BUTTON_AUXRIGHT1 = 13, ES_BUTTON_AUXLEFT2 = 11, ES_BUTTON_AUXRIGHT2 = 14, 
	ES_BUTTON_AUXLEFT3 = 12, ES_BUTTON_AUXRIGHT3 = 15 
};

class								ESInput
{
	public:
		static void					Initialize				(); //External
		static void					Shutdown				() {cellPadEnd();};
					
		static uint32_t				PadCount				() {return PadInfo.now_connect;};
		static inline void			Reset					(); //Below
		static void					Refresh					(); //External
		
		static inline int32_t		GetAxis					(uint32_t aPad, uint32_t aAxis); //Below

		static bool					ButtonPressed			(uint32_t aPad, uint32_t aButton) {return HeldState[aPad][aButton] == 1;}
		static bool					ButtonDown				(uint32_t aPad, uint32_t aButton) {return ESInputHelp::HandleSingleState(HeldState[aPad][aButton], SingleState[aPad][aButton]);}
	
		static inline uint32_t		GetAnyButton			(uint32_t aPad); //Below
		static std::string			GetButtonName			(uint32_t aButton) {return ButtonNames[aButton];};
		static std::string			GetButtonImage			(uint32_t aButton) {return ButtonNames[aButton] + "IMAGE";};

		static void					RumbleOn				(uint32_t aSmall, uint32_t aLarge) {Small = aSmall; Large = aLarge; Refresh();}
	
	protected:
		static const uint32_t		MAXPADS = 4;
		static const uint32_t		BUTTONS = 24;
		static const uint32_t		AXISCOUNT = 4;

		static uint32_t				ButtonIndex[][2];
		static std::string			ButtonNames[16];

		static CellPadInfo2			PadInfo;
		static CellPadData			CurrentState[MAXPADS];

		static uint32_t				HeldState[MAXPADS][BUTTONS];
		static uint32_t				SingleState[MAXPADS][BUTTONS];	

		static uint32_t				Small;
		static uint32_t				Large;
};

//Inlines
void								ESInput::Reset			()
{
	for(int i = 0; i != PadCount(); i ++)
	{
		cellPadClearBuf(i);
	}

	memset(HeldState, 0xFF, sizeof(HeldState));
	memset(SingleState, 0xFF, sizeof(SingleState));
}

int32_t								ESInput::GetAxis		(uint32_t aPad, uint32_t aAxis)
{
	if(aPad < PadCount())
	{
		int realaxis = AXISCOUNT + (AXISCOUNT - 1 - aAxis);
		return (int16_t)(CurrentState[aPad].button[realaxis]) - 0x80;
	}
	else
	{
		return 0;
	}
}

uint32_t							ESInput::GetAnyButton	(uint32_t aPad)
{
	for(int i = 0; i != BUTTONS; i ++)
	{
		if(HeldState[aPad][i] == 1)
		{
			return i;
		}
	}

	return 0xFFFFFFFF;
}

