#include <es_system.h>

namespace	GLShader
{
	void							ApplyVertexBuffer	(GLfloat* aBuffer)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 9 * sizeof(GLfloat), &aBuffer[0]);
		glTexCoordPointer(2, GL_FLOAT, 9 * sizeof(GLfloat), &aBuffer[3]);
		glColorPointer(4, GL_FLOAT, 9 * sizeof(GLfloat), &aBuffer[5]);
	}
}


void					ESVideo::Initialize				()
{
	const SDL_VideoInfo* dispinfo = SDL_GetVideoInfo();

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);

//	Screen = SDL_SetVideoMode(dispinfo->current_w, dispinfo->current_h, 32, SDL_OPENGL | SDL_FULLSCREEN);
	Screen = SDL_SetVideoMode(1280, 720, 32, SDL_OPENGL);
	if(!Screen)
	{
		printf("SDL Couldn't set video mode: %s\n", SDL_GetError());
		throw "SDL couldn't set video mode";
	}
	
	SDL_ShowCursor(SDL_DISABLE);
	SDL_WM_SetCaption("Mednafen PS3", "Mednafen PS3");
	
	ScreenWidth = dispinfo->current_w;
	ScreenHeight = dispinfo->current_h;
	WideScreen = false;

	//Some settings
	OpenGLHelp::InitializeState();

	// Setup vertex buffer
	VertexBuffer = (GLfloat*)malloc(VertexBufferCount * VertexSize * sizeof(GLfloat));
	GLShader::ApplyVertexBuffer(VertexBuffer);

	//Texture for FillRectangle
	FillerTexture = new Texture(2, 2);
	FillerTexture->Clear(0xFFFFFFFF);
}

void					ESVideo::Shutdown				()
{
	delete FillerTexture;
	free(VertexBuffer);
}

void					SetExit							();
void					ESVideo::Flip					()
{
	SDL_GL_SwapBuffers();

//TODO: Maybe a better place to handle the event loop	
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			SetExit();
		}
	}
	
	if(ESInput::ButtonDown(0, 0x80000000 | SDLK_F10))
	{
		SetExit();
	}
//TODO: Done with event loop

	SetClip(Area(0, 0, GetScreenWidth(), GetScreenHeight()));
	glClear(GL_COLOR_BUFFER_BIT);
}

void					ESVideo::PlaceTexture			(Texture* aTexture, const Area& aDestination, const Area& aSource, uint32_t aColor)
{
	float r = (float)((aColor >> 24) & 0xFF) / 256.0f;
	float g = (float)((aColor >> 16) & 0xFF) / 256.0f;	
	float b = (float)((aColor >> 8) & 0xFF) / 256.0f;
	float a = (float)((aColor >> 0) & 0xFF) / 256.0f;	

	float xl = 0, xr = 1, yl = 0, yr = 1;
	xl = (float)aSource.X / (float)aTexture->GetWidth();
	xr = (float)aSource.Right() / (float)aTexture->GetWidth();
	yl = (float)aSource.Y / (float)aTexture->GetHeight();
	yr = (float)aSource.Bottom() / (float)aTexture->GetHeight();

	aTexture->Apply();
	OpenGLHelp::SetVertex(&VertexBuffer[0 * VertexSize], Clip.X + aDestination.X, Clip.Y + aDestination.Y, r, g, b, a, xl, yl);
	OpenGLHelp::SetVertex(&VertexBuffer[1 * VertexSize], Clip.X + aDestination.Right(), Clip.Y + aDestination.Y, r, g, b, a, xr, yl);
	OpenGLHelp::SetVertex(&VertexBuffer[2 * VertexSize], Clip.X + aDestination.Right(), Clip.Y + aDestination.Bottom(), r, g, b, a, xr, yr);
	OpenGLHelp::SetVertex(&VertexBuffer[3 * VertexSize], Clip.X + aDestination.X, Clip.Y + aDestination.Bottom(), r, g, b, a, xl, yr);

	glDrawArrays(GL_QUADS, 0, 4);
}


SDL_Surface*			ESVideo::Screen;
Texture*				ESVideo::FillerTexture;

GLfloat*				ESVideo::VertexBuffer;

uint32_t				ESVideo::ScreenWidth;
uint32_t				ESVideo::ScreenHeight;
bool					ESVideo::WideScreen;
Area					ESVideo::Clip;

