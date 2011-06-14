#include <es_system.h>
#include "SummerfaceItem.h"


											SummerfaceItem::SummerfaceItem						(const std::string& aText, const std::string& aImage, uint32_t aNormalColor, uint32_t aHighLightColor)
{
	SetText(aText);
	SetImage(aImage);

	SetColors(aNormalColor, aHighLightColor);
}

											SummerfaceItem::~SummerfaceItem						()
{

}

void										SummerfaceItem::SetText								(const std::string& aText)
{
	Text = aText;
}

void										SummerfaceItem::SetImage							(const std::string& aImage)
{
	Image = aImage;
}

std::string									SummerfaceItem::GetText								()
{
	return Text;
}

std::string									SummerfaceItem::GetImage							()
{
	return Image;
}

void										SummerfaceItem::SetColors							(uint32_t aNormalColor, uint32_t aSpecialColor)
{
	NormalColor = aNormalColor;
	SpecialColor = aSpecialColor;
}

uint32_t									SummerfaceItem::GetNormalColor						()
{
	return NormalColor;
}

uint32_t									SummerfaceItem::GetHighLightColor					()
{
	return SpecialColor;
}

