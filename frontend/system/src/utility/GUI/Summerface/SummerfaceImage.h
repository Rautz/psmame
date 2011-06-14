#ifndef SYSTEM__SUMMERFACE_IMAGE_H
#define SYSTEM__SUMMERFACE_IMAGE_H

#include "SummerfaceWindow.h"

class													SummerfaceImage : public SummerfaceWindow
{
	public:
														SummerfaceImage					(const Area& aRegion, const std::string& aAsset);
		virtual											~SummerfaceImage				();

		virtual bool									Draw							();

		virtual std::string								GetImage						();
		virtual void									SetImage						(const std::string& aAsset);

	private:
		std::string										Image;
};

#endif

