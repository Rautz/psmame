#pragma once

#ifdef __CELLOS_LV2__
#define BUFFER_TARGET_ES	GL_TEXTURE_REFERENCE_BUFFER_SCE
#define glTexImageES(w,h)	glTextureReferenceSCE(GL_TEXTURE_2D, 1, (w), (h), 1, GL_ARGB_SCE, (w) * 4, (GLintptr)0);
#else
#define BUFFER_TARGET_ES	GL_PIXEL_UNPACK_BUFFER_ARB
#define glTexImageES(w,h)	glTexImage2D(GL_TEXTURE_2D, 0, 4, (w), (h), 0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)0);
#endif

class								Texture
{
	public:
		inline						Texture					(uint32_t aWidth, uint32_t aHeight);
		inline						~Texture				();
		
		inline void					Clear					(uint32_t aColor);
		inline uint32_t*			Map						();
		inline void					Unmap					();
		
		uint32_t					GetWidth				() const {return Width;};
		uint32_t					GetHeight				() const {return Height;};
		uint32_t					GetPitch				() const {return Pitch;};

		void						SetFilter				(bool aOn) {Filter = aOn;}

		uint32_t					GetFlags				() const {return 0;};

		uint32_t					GetRedShift				() const {return 16;};
		uint32_t					GetGreenShift			() const {return 8;};
		uint32_t					GetBlueShift			() const {return 0;};
		uint32_t					GetAlphaShift			() const {return 24;};
		
		inline uint32_t				ConvertPixel			(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha) const; //Below

	public: //Helper, do not call directly
		inline void					Apply					();
		uint32_t					GetID					() const {return ID;}

	private:
		uint32_t					BufferID;
		uint32_t					ID;
		uint32_t					MapCount;
		uint32_t*					Pixels;

		uint32_t					Width;
		uint32_t					Height;
		uint32_t					Pitch;
		bool						Filter;
		bool						Valid;
};

//Inlines
									Texture::Texture		(uint32_t aWidth, uint32_t aHeight) :
	BufferID(0),
	ID(0),
	MapCount(0),
	Pixels(0),
	Width(aWidth),
	Height(aHeight),
	Pitch(aWidth),
	Filter(false),
	Valid(false)
{
	ErrorCheck(Width != 0 && Height != 0 && Width <= 2048 && Height <= 2048, "Texture::Texture: Texture size is invalid, only sizes up to 2048x2048 are supported, and dimensions may not be zero. [Width: %d, Height: %d]", Width, Height);

	glGenTextures(1, &ID);
	glGenBuffers(1, &BufferID);

	glBindBuffer(BUFFER_TARGET_ES, BufferID);
	glBufferData(BUFFER_TARGET_ES, aWidth * aHeight * 4, 0, GL_STATIC_DRAW);
}
						
									Texture::~Texture		()
{
	while(MapCount)
	{
		Unmap();
	}

	glDeleteTextures(1, &ID);
	glDeleteBuffers(1, &BufferID);
}

void								Texture::Clear			(uint32_t aColor)
{
	uint32_t* Pixels = Map();

	for(int i = 0; i != Width * Height; i ++)
	{
		Pixels[i] = aColor;
	}

	Unmap();
}	

uint32_t*							Texture::Map			()
{
	Valid = false;

	if(MapCount == 0)
	{
		glBindBuffer(BUFFER_TARGET_ES, BufferID);
		Pixels = (uint32_t*)glMapBuffer(BUFFER_TARGET_ES, GL_READ_WRITE);
		glBindBuffer(BUFFER_TARGET_ES, 0);
	}

	MapCount ++;
	return Pixels;
}

void								Texture::Unmap			()
{
	if(MapCount)
	{
		MapCount --;

		if(!MapCount)
		{
			glBindBuffer(BUFFER_TARGET_ES, BufferID);
			glUnmapBuffer(BUFFER_TARGET_ES);
			glBindBuffer(BUFFER_TARGET_ES, 0);
			Pixels = 0;
		}
	}
}

void								Texture::Apply			()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID);

	if(!Valid)
	{
		Valid = true;

		glBindBuffer(BUFFER_TARGET_ES, BufferID);
		glTexImageES(Width, Height);
		glBindBuffer(BUFFER_TARGET_ES, 0);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter ? GL_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter ? GL_LINEAR : GL_NEAREST);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
}


uint32_t							Texture::ConvertPixel	(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha) const
{
	return (aRed << GetRedShift()) | (aBlue << GetBlueShift()) | (aGreen << GetGreenShift()) | (aAlpha << GetAlphaShift());
}

