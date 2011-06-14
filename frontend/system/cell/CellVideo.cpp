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
	//Init PSGL
	PSGLinitOptions initOpts = {PSGL_INIT_MAX_SPUS | PSGL_INIT_HOST_MEMORY_SIZE, 1, false, 0, 0, 0, 0, 32 * 1024 * 1024};
	psglInit(&initOpts);
	
	Device = psglCreateDeviceAuto(GL_ARGB_SCE, GL_NONE, GL_MULTISAMPLING_NONE_SCE);
	Context = psglCreateContext();
	psglMakeCurrent(Context, Device);
	psglResetCurrentContext();

	//Get Screen Info
	psglGetRenderBufferDimensions(Device, &ScreenWidth, &ScreenHeight);
	WideScreen = psglGetDeviceAspectRatio(Device) > 1.5f;
	glViewport(0, 0, GetScreenWidth(), GetScreenHeight());

	//Some settings
	OpenGLHelp::InitializeState();
	glEnable(GL_VSYNC_SCE);

	// Setup vertex buffer
	VertexBuffer = (GLfloat*)memalign(128, VertexBufferCount * VertexSize * sizeof(GLfloat));
	GLShader::ApplyVertexBuffer(VertexBuffer);

	//Texture for FillRectangle
	FillerTexture = new Texture(2, 2);
	FillerTexture->Clear(0xFFFFFFFF);
}

void					ESVideo::Shutdown				()
{
	delete FillerTexture;

	//Destory ShaderContext

	psglDestroyContext(Context);
	psglDestroyDevice(Device);
	
	psglExit();						

	free(VertexBuffer);
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

PSGLdevice*				ESVideo::Device;
PSGLcontext*			ESVideo::Context;

GLfloat*				ESVideo::VertexBuffer;

Texture*				ESVideo::FillerTexture;

uint32_t				ESVideo::ScreenWidth;
uint32_t				ESVideo::ScreenHeight;
bool					ESVideo::WideScreen;
Area					ESVideo::Clip;

