#include <es_system.h>

void				ESInput::Initialize						()
{
	for(int i = 0; i != SDL_NumJoysticks(); i ++)
	{
		Joysticks.push_back(SDL_JoystickOpen(i));
	}

	Reset();
}

void				ESInput::Shutdown						()
{
	for(int i = 0; i != Joysticks.size(); i ++)
	{
		SDL_JoystickClose(Joysticks[i]);
	}
}

void				ESInput::Refresh						()
{
	int numkeys;
	uint8_t* keys = SDL_GetKeyState(&numkeys);

	for(int j = 0; j != numkeys && j != MAXKEYS; j ++)
	{
		ESInputHelp::RefreshButton(keys[j], KeyState[j], KeySingle[j]);
	}

	for(int i = 0; i != Joysticks.size(); i ++)
	{
		uint32_t buttonIndex = 0;
	
		for(int j = 0; j != SDL_JoystickNumAxes(Joysticks[i]); j ++)
		{
			ESInputHelp::RefreshButton(SDL_JoystickGetAxis(Joysticks[i], j) < -0x4000, HeldState[i][buttonIndex + 0], SingleState[i][buttonIndex + 0]);
			ESInputHelp::RefreshButton(SDL_JoystickGetAxis(Joysticks[i], j) >  0x4000, HeldState[i][buttonIndex + 0], SingleState[i][buttonIndex + 1]);
			buttonIndex += 2;
		}

		for(int j = 0; j != SDL_JoystickNumHats(Joysticks[i]); j ++)
		{
			ESInputHelp::RefreshButton(SDL_JoystickGetHat(Joysticks[i], j) & SDL_HAT_UP, HeldState[i][buttonIndex + 0], SingleState[i][buttonIndex + 0]);
			ESInputHelp::RefreshButton(SDL_JoystickGetHat(Joysticks[i], j) & SDL_HAT_DOWN, HeldState[i][buttonIndex + 1], SingleState[i][buttonIndex + 1]);			
			ESInputHelp::RefreshButton(SDL_JoystickGetHat(Joysticks[i], j) & SDL_HAT_LEFT, HeldState[i][buttonIndex + 2], SingleState[i][buttonIndex + 2]);
			ESInputHelp::RefreshButton(SDL_JoystickGetHat(Joysticks[i], j) & SDL_HAT_RIGHT, HeldState[i][buttonIndex + 3], SingleState[i][buttonIndex + 3]);			
			buttonIndex += 4;
		}
	
		for(int j = 0; j != SDL_JoystickNumButtons(Joysticks[i]); j ++)
		{
			ESInputHelp::RefreshButton(SDL_JoystickGetButton(Joysticks[i], j), HeldState[i][j + buttonIndex], SingleState[i][j + buttonIndex]);
		}
	}
}
		
std::vector<SDL_Joystick*>	ESInput::Joysticks;
uint32_t			ESInput::ESInputs[14];

uint32_t			ESInput::KeyState[MAXKEYS];
uint32_t			ESInput::KeySingle[MAXKEYS];

uint32_t			ESInput::HeldState[MAXPADS][BUTTONS];
uint32_t			ESInput::SingleState[MAXPADS][BUTTONS];	


