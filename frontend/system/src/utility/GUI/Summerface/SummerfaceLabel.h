#ifndef SYSTEM__SUMMERFACE_LABEL_H
#define SYSTEM__SUMMERFACE_LABEL_H

#include "SummerfaceWindow.h"

class													SummerfaceLabel : public SummerfaceWindow
{
	public:
														SummerfaceLabel					(const Area& aRegion, const std::string& aMessage);
														SummerfaceLabel					(const Area& aRegion, const char* aFormat, ...);
		virtual											~SummerfaceLabel				();

		virtual bool									Draw							();

		virtual std::string								GetMessage						();
		virtual void									SetMessage						(const char* aFormat, ...);
		virtual void									SetMessage						(const std::string& aMessage);

		virtual void									AppendMessage					(const std::string& aMessage);
		

	private:
		std::string										Message;
};

#endif

