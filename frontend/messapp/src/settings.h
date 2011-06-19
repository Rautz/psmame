#pragma once

class							Settings
{
	public:
		static void				Do						();
		static void				Read					();
		static void				Dump					();
		static void				RestartApp				();

	public:
		static bool				Cheats;
		static bool				SkipGameInfo;
		static bool				AutoSave;
		static bool				AutoFrameSkip;
};

