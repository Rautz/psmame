#include <es_system.h>
#include "SummerfaceWindow.h"

uint32_t ptpp(uint32_t aIn, bool aX)
{
	uint32_t s = aX ? ESVideo::GetScreenWidth() : ESVideo::GetScreenHeight();
	return s * ((double)aIn / 100.0);
}


											SummerfaceWindow::SummerfaceWindow					(const Area& aRegion, bool aBorder) :
	Interface(Summerface_WeakPtr()),
	InputHandler(SummerfaceInputConduit_Ptr()),
	UseBorder(aBorder)
{
	Region = Area(ptpp(aRegion.X, 1), ptpp(aRegion.Y, 0), ptpp(aRegion.Width, 1), ptpp(aRegion.Height, 0));;
	Client = Area(Region.X + BorderWidth, Region.Y + BorderWidth, Region.Width - BorderWidth * 2, Region.Height - BorderWidth * 2);
}

//Draw the border and background, leave clip set to the windows client area
bool										SummerfaceWindow::PrepareDraw						()
{
	if(UseBorder)
	{
		ESVideo::SetClip(Area(0, 0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight()));

	//TODO: Make border color
		ESVideo::FillRectangle(Area(Region.X, Region.Y, Region.Width, BorderWidth), 0xFFFFFFFF);
		ESVideo::FillRectangle(Area(Region.X + BorderWidth, Region.Bottom(), Region.Width, BorderWidth), 0x00000080);
		ESVideo::FillRectangle(Area(Region.X, Region.Bottom() - BorderWidth, Region.Width, BorderWidth), 0xFFFFFFFF);

		ESVideo::FillRectangle(Area(Region.X, Region.Y + BorderWidth, BorderWidth, Region.Height - BorderWidth * 2), 0xFFFFFFFF);
		ESVideo::FillRectangle(Area(Region.Right(), Region.Y + BorderWidth, BorderWidth, Region.Height - BorderWidth), 0x00000080);
		ESVideo::FillRectangle(Area(Region.Right() - BorderWidth, Region.Y + BorderWidth, BorderWidth, Region.Height - BorderWidth * 2), 0xFFFFFFFF);

		ESVideo::FillRectangle(Client, Colors::BackGround);

		ESVideo::SetClip(Client);

		std::string header = GetHeader();
		if(!header.empty())
		{
			FontManager::GetBigFont()->PutString(header.c_str(), 1, 1, Colors::Normal, true);
			ESVideo::FillRectangle(Area(0, FontManager::GetBigFont()->GetHeight() + 1, Client.Width, 1), 0xFFFFFFFF);
			ESVideo::SetClip(Area(Client.X, Client.Y + FontManager::GetBigFont()->GetHeight() + 3, Client.Width, Client.Height - (FontManager::GetBigFont()->GetHeight() + 3)));
		}
	}
	else
	{
		ESVideo::SetClip(Region);
	}

	return Draw();
}


bool										SummerfaceWindow::Input								()
{
	if(InputHandler)
	{
		return InputHandler->HandleInput(GetInterface(), GetName());
	}
	else
	{
		return ESInput::ButtonDown(0, ES_BUTTON_CANCEL);
	}
}

void										SummerfaceWindow::SetInterface						(Summerface_Ptr aInterface, const std::string& aName)
{
	Interface = aInterface;
	Name = aName;
}

Summerface_Ptr								SummerfaceWindow::GetInterface						()
{
	if(!Interface.expired())
	{
		return Interface.lock();
	}

	return Summerface_Ptr();
}

void										SummerfaceWindow::SetHeader							(const std::string& aHeader, ...)
{
	char array[1024];
	va_list args;
	va_start (args, aHeader);
	vsnprintf(array, 1024, aHeader.c_str(), args);
	va_end(args);

	Header = array;
}

