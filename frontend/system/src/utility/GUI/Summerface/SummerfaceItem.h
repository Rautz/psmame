#ifndef SYSTEM__SUMMERFACE_ITEM_H
#define SYSTEM__SUMMERFACE_ITEM_H

class													SummerfaceItem
{
	public:
														SummerfaceItem					(const std::string& aText, const std::string& aImage, uint32_t aNormalColor = Colors::Normal, uint32_t aHighLightColor = Colors::HighLight);
		virtual											~SummerfaceItem					();

		virtual void									SetText							(const std::string& aText);
		virtual void									SetImage						(const std::string& aImage);

		virtual std::string								GetText							();
		virtual std::string								GetImage						();

		virtual void									SetColors						(uint32_t aNormalColor, uint32_t aSpecialColor);
		virtual uint32_t								GetNormalColor					();
		virtual uint32_t								GetHighLightColor				();

	public:
		std::map<std::string, std::string>				Properties;
		std::map<std::string, uint64_t>					IntProperties;

	private:
		std::string										Text;
		std::string										Image;

		uint32_t										NormalColor;
		uint32_t										SpecialColor;
};


#endif

