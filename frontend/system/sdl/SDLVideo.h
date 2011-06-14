#pragma once

class								ESVideo
{
	public:	
		static void					Initialize				(); //External
		static void					Shutdown				(); //External

		static inline void			EnableVsync				(bool aOn); //Below
	
		static Texture*				CreateTexture			(uint32_t aWidth, uint32_t aHeight, bool aStatic = false) {return new Texture(aWidth, aHeight);};
	
		static uint32_t				GetScreenWidth			() {return ScreenWidth;}
		static uint32_t				GetScreenHeight			() {return ScreenHeight;}
		static bool					IsWideScreen			() {return WideScreen;}

		static inline void			SetClip					(const Area& aClip); //Below
		static const Area&			GetClip					() {return Clip;}
	
		static void					Flip					(); //External
		
		static void					PlaceTexture			(Texture* aTexture, const Area& aDestination, const Area& aSource, uint32_t aColor); //External
		static void					FillRectangle			(const Area& aArea, uint32_t aColor) {PlaceTexture(FillerTexture, aArea, Area(0, 0, 2, 2), aColor);}
		
	protected:
		static SDL_Surface*			Screen;
		static Texture*				FillerTexture;

		static const uint32_t		VertexSize = 9;
		static const uint32_t		VertexBufferCount = 4;
		static GLfloat*				VertexBuffer;

		static uint32_t				ScreenWidth;
		static uint32_t				ScreenHeight;
		static bool					WideScreen;
		static Area					Clip;
};

//---Inlines
void					ESVideo::EnableVsync			(bool aOn)
{
	const SDL_VideoInfo* dispinfo = SDL_GetVideoInfo();
	SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, aOn ? 1 : 0);
//	Screen = SDL_SetVideoMode(dispinfo->current_w, dispinfo->current_h, 32, SDL_OPENGL | SDL_FULLSCREEN);
	Screen = SDL_SetVideoMode(1280, 720, 32, SDL_OPENGL);
}

void								ESVideo::SetClip					(const Area& aClip)
{
	Clip = aClip.Valid(GetScreenWidth(), GetScreenHeight()) ? aClip : Area(0, 0, GetScreenWidth(), GetScreenHeight());
	glScissor(Clip.X, GetScreenHeight() - Clip.Bottom(), Clip.Width, Clip.Height);
}

#include "../opengl_common/Helpers.h"

