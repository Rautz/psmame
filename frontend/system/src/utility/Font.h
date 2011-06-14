#ifndef FONT_H_
#define FONT_H_

class										FontCharacter
{
	public:
		Texture*							CharTexture;
		Area								TextureArea;
		uint32_t							Width;
		uint32_t							Height;
		uint32_t							Advance;
		uint32_t							BaseX;
		uint32_t							BaseY;
};

class										Font
{
	public:
											Font						(uint32_t aPixelSize, bool aFixed);
											~Font						();
								
		void								PutString					(const char* aString, uint32_t aX, uint32_t aY, uint32_t aColor, bool aDropShadow = false, uint32_t aShadowColor = 0x00000080, int32_t aShadowXOffset = 1, int32_t aShadowYOffset = 1);
		void								PutStringCenter				(const char* aString, const Area& aRegion, uint32_t aColor, bool aDropShadow = false, uint32_t aShadowColor = 0x00000080, int32_t aShadowXOffset = 1, int32_t aShadowYOffset = 1);
		uint32_t							MeasureString				(const char* aString);

		uint32_t							GetWidth					() const {return Width;};
		uint32_t							GetHeight					() const {return Height;};
		
	protected:
		FontCharacter*						CacheCharacter				(uint32_t aCharacter);
	
		FT_Face								FontFace;
		uint32_t							Width;
		uint32_t							Height;
		
		std::map<uint32_t, FontCharacter*>	Cache;
};

class										FontManager
{
	friend class							Font;

	public:
		static void							InitFonts					();
		static void							QuitFonts					();
	
		static Font*						GetBigFont					();
		static Font*						GetSmallFont				();
		static Font*						GetFixedFont				();
	
		static FT_Library					FreeType;	
	
		static bool							FontsOpen;
		static Font*						SmallFont;
		static Font*						FixedFont;
		static Font*						BigFont;
};

#endif
