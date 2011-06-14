#ifndef SYSTEM__TEXTVIEWER_H
#define SYSTEM__TEXTVIEWER_H

class							TextViewer : public SummerfaceWindow
{
	public:
								TextViewer					(const Area& aRegion, const std::string& aFileName, bool aFile = true);
		virtual					~TextViewer					();
		
		virtual bool			Draw						();
		virtual bool			Input						();
		
	protected:
		void					LoadStream					(std::istream* aStream);
	
		std::vector<std::string>Lines;
	
		int32_t					Top;
		int32_t					Left;
		uint32_t				LongestLine;
		uint32_t				LinesDrawn;
};

#endif

