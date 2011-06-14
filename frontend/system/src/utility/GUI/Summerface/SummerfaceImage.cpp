#include <es_system.h>
#include "SummerfaceImage.h"

											SummerfaceImage::SummerfaceImage					(const Area& aRegion, const std::string& aAsset) : SummerfaceWindow(aRegion)
{
	Image = aAsset;
}

											SummerfaceImage::~SummerfaceImage					()
{

}

bool										SummerfaceImage::Draw								()
{
	if(ImageManager::GetImage(Image))
	{
		Texture* tex = ImageManager::GetImage(Image);

		uint32_t x = 1, y = 1, w = ESVideo::GetClip().Width - 2, h = ESVideo::GetClip().Height - 2;
		Utility::CenterAndScale(x, y, w, h, tex->GetWidth(), tex->GetHeight());

		ESVideo::PlaceTexture(tex, Area(x, y, w, h), Area(0, 0, tex->GetWidth(), tex->GetHeight()), 0xFFFFFFFF);
	}

	return false;
}

std::string									SummerfaceImage::GetImage							()
{
	return Image;
}

void										SummerfaceImage::SetImage							(const std::string& aAsset)
{
	Image = aAsset;
}


