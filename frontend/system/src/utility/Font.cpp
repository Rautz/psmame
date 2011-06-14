#include <es_system.h>

//TODO: This isn't thread safe
extern "C"
{
	#include "utf8_decode.h"
}

						Font::Font					(uint32_t aPixelSize, bool aFixed = false)
{
	if(0 != FT_New_Face(FontManager::FreeType, aFixed ? es_paths->Build("assets/font/fixed.ttf").c_str() : es_paths->Build("assets/font/prop.ttf").c_str(), 0, &FontFace))
	{
		Abort("Font::Font: FT_New_Face failed");
	}
	
	if(0 != FT_Set_Pixel_Sizes(FontFace, 0, aPixelSize))
	{
		Abort("Font::Font: FT_Set_Pixel_Sizes failed");
	}

	Width = FontFace->size->metrics.max_advance / 64;
	Height = FontFace->size->metrics.height / 64;
}

						Font::~Font					()
{
	for(std::map<uint32_t, FontCharacter*>::iterator i = Cache.begin(); i != Cache.end(); i ++)
	{
		delete i->second->CharTexture;
		delete i->second;
	}
		
	FT_Done_Face(FontFace);
}

void					Font::PutString					(const char* aString, uint32_t aX, uint32_t aY, uint32_t aColor, bool aDropShadow, uint32_t aShadowColor, int32_t aShadowXOffset, int32_t aShadowYOffset)
{
	if(aDropShadow)
	{
		PutString(aString, aX + aShadowXOffset, aY + aShadowYOffset, 0x00000080, false);
	}

	utf8_decode_init(aString, strlen(aString));

	for(int thischar = utf8_decode_next(); thischar != UTF8_END; thischar = utf8_decode_next())
	{
		if(thischar >= 32 || thischar == 9)
		{
			//TODO: Support real tab stops
			FontCharacter* chara = CacheCharacter(thischar == 9 ? 32 : thischar);
			
			if(chara && chara->CharTexture)
			{
				ESVideo::PlaceTexture(chara->CharTexture, Area(aX + chara->BaseX, aY + (Height + (FontFace->descender / 64)) - chara->BaseY, chara->Width, chara->Height), chara->TextureArea, aColor);
			}
			
			if(chara)
			{
				aX += chara->Advance;
			}
		}
	}
}

void					Font::PutStringCenter		(const char* aString, const Area& aRegion, uint32_t aColor, bool aDropShadow, uint32_t aShadowColor, int32_t aShadowXOffset, int32_t aShadowYOffset)
{
	int32_t x = (aRegion.Width - MeasureString(aString)) / 2;
	PutString(aString, aRegion.X + x, aRegion.Y, aColor, aDropShadow, aShadowColor, aShadowXOffset, aShadowYOffset);
}


uint32_t				Font::MeasureString			(const char* aString)
{
	uint32_t width = 0;
	utf8_decode_init(aString, strlen(aString));

	for(int thischar = utf8_decode_next(); thischar != UTF8_END; thischar = utf8_decode_next())
	{
		if(thischar >= 32 || thischar == 9)
		{
			//TODO: Support real tab stops
			FontCharacter* chara = CacheCharacter(thischar == 9 ? 32 : thischar);
			
			if(chara)
			{
				width += chara->Advance;
			}
		}
	}

	return width;
}

FontCharacter*			Font::CacheCharacter		(uint32_t aCharacter)
{
	if(Cache[aCharacter] == 0)
	{
		FontCharacter* character = new FontCharacter();

		FT_UInt glyph_index = FT_Get_Char_Index(FontFace, aCharacter);

		if(0 != FT_Load_Glyph(FontFace, glyph_index, FT_LOAD_RENDER))
		{
			Abort("Font::CacheCharacter: FT_Load_Glyph failed");
		}

		character->Advance = FontFace->glyph->advance.x >> 6;
		character->Width = FontFace->glyph->bitmap.width;
		character->Height = FontFace->glyph->bitmap.rows;
		character->BaseX = FontFace->glyph->bitmap_left;
		character->BaseY = FontFace->glyph->bitmap_top;
		
		if(character->Width != 0 && character->Height != 0)
		{
			character->CharTexture = ESVideo::CreateTexture(FontFace->glyph->bitmap.width, FontFace->glyph->bitmap.rows, true);
			character->TextureArea = Area(0, 0, character->CharTexture->GetWidth(), character->CharTexture->GetHeight());
			character->CharTexture->Clear(0);
		
			uint32_t* pixels = character->CharTexture->Map();
			uint32_t pitch = character->CharTexture->GetPitch();
	
			for(int y = 0; y != FontFace->glyph->bitmap.rows; y ++)
			{
				uint8_t* row = &FontFace->glyph->bitmap.buffer[y * FontFace->glyph->bitmap.pitch];
			
				for(int x = 0; x != FontFace->glyph->bitmap.width; x ++)
				{
					pixels[y * pitch + x] = character->CharTexture->ConvertPixel(0xFF, 0xFF, 0xFF, row[x]);
				}
			}

			character->CharTexture->Unmap();
		}
		else
		{
			character->CharTexture = 0;
		}

		Cache[aCharacter] = character;
	}
	
	return Cache[aCharacter];
}

Font*					FontManager::GetBigFont		()
{
	if(!FontsOpen)
	{
		Abort("FontManager: Attempt to use before initialization");
	}
	
	return BigFont;
}

Font*					FontManager::GetSmallFont	()
{
	if(!FontsOpen)
	{
		Abort("FontManager: Attempt to use before initialization");
	}

	return SmallFont;
}

Font*					FontManager::GetFixedFont	()
{
	if(!FontsOpen)
	{
		Abort("FontManager: Attempt to use before initialization");
	}

	return FixedFont;
}

void					FontManager::InitFonts		()
{
	if(!FontsOpen)
	{
		if(0 != FT_Init_FreeType(&FreeType))
		{
			Abort("FontManager::Init: Failed to initialize freetype");
		}
	
		BigFont = new Font(ESVideo::GetScreenHeight() / 25);
		SmallFont = new Font(ESVideo::GetScreenHeight() / 40);
		FixedFont = new Font(ESVideo::GetScreenHeight() / 36, true);
	}
	
	FontsOpen = true;
}

void					FontManager::QuitFonts		()
{
	if(FontsOpen)
	{
		delete BigFont;
		delete SmallFont;
		delete FixedFont;
		
		FT_Done_FreeType(FreeType);
	}
	
	FontsOpen = false;
}

FT_Library				FontManager::FreeType = 0;

bool					FontManager::FontsOpen = false;
Font*					FontManager::BigFont = 0;
Font*					FontManager::SmallFont = 0;
Font*					FontManager::FixedFont = 0;

