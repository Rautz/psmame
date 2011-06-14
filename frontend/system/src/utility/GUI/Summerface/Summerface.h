#pragma once

#include "SummerfaceWindow.h"

class													Summerface : public Menu, public boost::enable_shared_from_this<Summerface>
{
	public: //Do not call!
														Summerface						() {};

	public:
		static Summerface_Ptr							Create							(); //External
		static Summerface_Ptr							Create							(const std::string& aName, SummerfaceWindow_Ptr aWindow); //External

		virtual											~Summerface						() {};

		virtual bool									Draw							();
		virtual bool									Input							();

		void											AddWindow						(const std::string& aName, SummerfaceWindow_Ptr aWindow);
		void											RemoveWindow					(const std::string& aName);
		SummerfaceWindow_Ptr							GetWindow						(const std::string& aName);
		void											SetActiveWindow					(const std::string& aName);

		static void										SetDrawBackground				(bool (*aCallback)()) {BackgroundCallback = aCallback;};
		
	private:
		std::map<std::string, SummerfaceWindow_Ptr>		Windows;
		std::string										ActiveWindow;

		static bool										(*BackgroundCallback)			();
};

