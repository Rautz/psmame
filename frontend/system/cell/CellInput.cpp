#include <es_system.h>

namespace
{
	enum{PS3_AXIS_LEFT_Y, PS3_AXIS_LEFT_X, PS3_AXIS_RIGHT_Y, PS3_AXIS_RIGHT_X, PS3_AXIS_COUNT};
}

void				ESInput::Initialize						()
{
	cellPadInit(MAXPADS);

	cellPadGetInfo2(&PadInfo);
	
	Reset();

	Small = 0;
	Large = 0;
}

void				ESInput::Refresh						()
{
	cellPadGetInfo2(&PadInfo);

	if(!(PadInfo.system_info & CELL_PAD_INFO_INTERCEPTED))
	{
		for(int p = 0; p != PadCount(); p ++)
		{
			CellPadData newstate;
			cellPadGetData(p, &newstate);

			if(newstate.len != 0)
			{
				CurrentState[p] = newstate;

				for(int i = 0; i != BUTTONS - 8; i ++)
				{
					ESInputHelp::RefreshButton(CurrentState[p].button[ButtonIndex[i][0]] & ButtonIndex[i][1], HeldState[p][i], SingleState[p][i]);
				}

				for(int i = 0; i != 4; i ++)
				{
					ESInputHelp::RefreshButton(GetAxis(0, i) < -0x40, HeldState[p][16 + i * 2 + 0], SingleState[p][16 + i * 2 + 0]);
					ESInputHelp::RefreshButton(GetAxis(0, i) >  0x40, HeldState[p][16 + i * 2 + 1], SingleState[p][16 + i * 2 + 1]);
				}
			}
		}

		//TODO: Support rumble for more than 1 controller
		CellPadActParam param = {Small & 1, Large & 0xFF};
		cellPadSetActDirect(0, &param);
	}
}

CellPadInfo2		ESInput::PadInfo;
CellPadData			ESInput::CurrentState[MAXPADS];

uint32_t			ESInput::HeldState[MAXPADS][BUTTONS];
uint32_t			ESInput::SingleState[MAXPADS][BUTTONS];	

uint32_t			ESInput::Small;
uint32_t			ESInput::Large;

uint32_t			ESInput::ButtonIndex[][2] = {{2,8}, {2, 1}, {3, 0x80}, {3, 0x40}, {3, 0x10}, {3, 0x20}, {2, 0x10}, {2, 0x40}, {2, 0x80}, {2, 0x20}, {3, 4}, {3, 1}, {2, 2}, {3, 8}, {3, 2}, {2, 4}};
std::string			ESInput::ButtonNames[16] = {"Start", "Select", "Square", "Cross", "Triangle", "Circle", "Up", "Down", "Left", "Right", "L1", "L2", "L3", "R1", "R2", "R3"};	

