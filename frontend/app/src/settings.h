#pragma once

class							Settings
{
	public:
		static void				ChooseROMDirectory		();
		static void				DeleteGameDatabase		();
		static void				Do						();
		static void				Read					();
		static void				Dump					();
		static void				RestartApp				();

	public:
		static std::string		ROMPath;
		static bool				Cheats;
		static bool				SkipGameInfo;
		static bool				AutoFrameSkip;
};

