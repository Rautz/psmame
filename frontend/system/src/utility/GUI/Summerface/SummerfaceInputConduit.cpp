#include <es_system.h>
#include "SummerfaceInputConduit.h"


											SummerfaceStaticConduit::SummerfaceStaticConduit	(bool (*aCallback)(void*, Summerface_Ptr aInterface, const std::string&), void* aUserData)
{
	Callback = aCallback;
	UserData = aUserData;
}

bool										SummerfaceStaticConduit::HandleInput				(Summerface_Ptr aInterface, const std::string& aWindow)
{
	if(Callback)
	{
		return Callback(UserData, aInterface, aWindow);
	}

	return false;
}

