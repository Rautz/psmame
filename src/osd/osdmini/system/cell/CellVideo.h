#pragma once

class								ESVideo
{
	public:	
		static void					Initialize				();
		static void					Shutdown				();
	
		static inline void			EnableVsync				(bool aOn); //Below

		static Texture*				CreateTexture			(uint32_t aWidth, uint32_t aHeight, bool aStatic = false) {return new Texture(aWidth, aHeight);};
	
		static uint32_t				GetScreenWidth			() {return ScreenWidth;}
		static uint32_t				GetScreenHeight			() {return ScreenHeight;}
		static bool					IsWideScreen			() {return WideScreen;}

		static inline void			Flip					(); //Below
		
		static void					PlaceTexture			(Texture* aTexture, const Area& aDestination, const Area& aSource); //External
		
	protected:
		static const uint32_t		VertexSize = 5;
		static const uint32_t		VertexBufferCount = 4;

		static PSGLdevice*			Device;
		static PSGLcontext*			Context;

		static GLfloat*				VertexBuffer;

		static uint32_t				ScreenWidth;
		static uint32_t				ScreenHeight;
		static bool					WideScreen;
};

//---Inlines
void								ESVideo::EnableVsync				(bool aOn)
{
	if(aOn)
	{
		glEnable(GL_VSYNC_SCE);
	}
	else
	{
		glDisable(GL_VSYNC_SCE);
	}
}

void								ESVideo::Flip						()
{
	psglSwap();
	glClear(GL_COLOR_BUFFER_BIT);
}


#include "../opengl_common/Helpers.h"

