#include <es_system.h>
#include "SummerfaceLabel.h"

											SummerfaceLabel::SummerfaceLabel					(const Area& aRegion, const std::string& aMessage) : SummerfaceWindow(aRegion)
{
	SetMessage(aMessage);
}

											SummerfaceLabel::SummerfaceLabel					(const Area& aRegion, const char* aFormat, ...) : SummerfaceWindow(aRegion)
{
	char array[2048];

	va_list args;
	va_start (args, aFormat);
	vsnprintf(array, 2048, aFormat, args);
	va_end(args);

	SetMessage(array);
}

											SummerfaceLabel::~SummerfaceLabel					()
{

}

bool										SummerfaceLabel::Draw								()
{
	FontManager::GetBigFont()->PutString(GetMessage().c_str(), 2, 2, Colors::Normal, true);	
	return false;
}

std::string									SummerfaceLabel::GetMessage							()
{
	return Message;
}

void										SummerfaceLabel::SetMessage							(const char* aFormat, ...)
{
	char array[2048];

	va_list args;
	va_start (args, aFormat);
	vsnprintf(array, 2048, aFormat, args);
	va_end(args);

	Message = array;
}


void										SummerfaceLabel::SetMessage							(const std::string& aMessage)
{
	Message = aMessage;
}

void										SummerfaceLabel::AppendMessage						(const std::string& aMessage)
{
	SetMessage("%s%s", GetMessage().c_str(), aMessage.c_str());
}

