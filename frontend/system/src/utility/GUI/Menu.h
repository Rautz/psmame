#pragma once

class								MenuHook
{
	public:
		virtual bool				Input						() = 0;
};

class								Menu
{
	public:
									Menu						(MenuHook* aHook = 0);
		virtual						~Menu						();

		void						SetInputDelay				(uint32_t aDelay);
		
		void						Do							();

		void						SetHook						(MenuHook* aHook);

		virtual bool				Draw						() = 0;
		virtual bool				Input						() = 0;
		
	protected:
		uint32_t					InputDelay;
		MenuHook*					Hook;
};

