#if 0

class								Texture
{
	public:
		enum Flags {SLOW_READ = 1, SLOW_WRITE = 2, USE_IS_DISCARD = 4};

	public:
									Texture					() : esWidth(0), esHeight(0), esPitch(0), esFilter(0), esValid(0) {}
									Texture					(uint32_t aWidth, uint32_t aHeight, uint32_t aPitch) : esWidth(aWidth), esHeight(aHeight), esPitch(aPitch), esFilter(0), esValid(0) {}

		virtual						~Texture				() {};

		virtual void				Clear					(uint32_t aColor) = 0; //Pure Virtual
		virtual uint32_t*			Map						() = 0; //Pure Virtual
		virtual void				Unmap					() = 0;

		virtual void				Invalidate				() {esValid = false;}

		virtual uint32_t			GetWidth				() const {return esWidth;};
		virtual uint32_t			GetHeight				() const {return esHeight;};
		virtual uint32_t			GetPitch				() const {return esPitch;};

		virtual void				SetFilter				(bool aOn) {esFilter = aOn;}

		virtual uint32_t			GetFlags				() const = 0; //Pure Virtual

		virtual uint32_t			GetRedShift				() const = 0; //Pure Virtual
		virtual uint32_t			GetGreenShift			() const = 0; //Pure Virtual
		virtual uint32_t			GetBlueShift			() const = 0; //Pure Virtual
		virtual uint32_t			GetAlphaShift			() const = 0; //Pure Virtual

		inline uint32_t				ConvertPixel			(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha) const; //Not Virtual, defined below

	protected: //Default values for descendants
		uint32_t					esWidth;
		uint32_t					esHeight;
		uint32_t					esPitch;
		bool						esFilter;
		bool						esValid;
};

uint32_t							Texture::ConvertPixel	(uint8_t aRed, uint8_t aGreen, uint8_t aBlue, uint8_t aAlpha) const
{
	return (aRed << GetRedShift()) | (aBlue << GetBlueShift()) | (aGreen << GetGreenShift()) | (aAlpha << GetAlphaShift());
}
#endif
