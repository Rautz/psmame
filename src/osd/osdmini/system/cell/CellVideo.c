#include <es_system.h>

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

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), &VertexBuffer[0]);
	glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &VertexBuffer[3]);
}

void					ESVideo::Shutdown				()
{
	psglDestroyContext(Context);
	psglDestroyDevice(Device);
	
	psglExit();						

	free(VertexBuffer);
}

void					ESVideo::PlaceTexture			(Texture* aTexture, const Area& aDestination, const Area& aSource)
{
	float xl = 0, xr = 1, yl = 0, yr = 1;
	xl = (float)aSource.X / (float)aTexture->GetWidth();
	xr = (float)aSource.Right() / (float)aTexture->GetWidth();
	yl = (float)aSource.Y / (float)aTexture->GetHeight();
	yr = (float)aSource.Bottom() / (float)aTexture->GetHeight();

	aTexture->Apply();
	OpenGLHelp::SetVertex(&VertexBuffer[0 * VertexSize], aDestination.X, aDestination.Y, xl, yl);
	OpenGLHelp::SetVertex(&VertexBuffer[1 * VertexSize], aDestination.Right(), aDestination.Y, xr, yl);
	OpenGLHelp::SetVertex(&VertexBuffer[2 * VertexSize], aDestination.Right(), aDestination.Bottom(), xr, yr);
	OpenGLHelp::SetVertex(&VertexBuffer[3 * VertexSize], aDestination.X, aDestination.Bottom(), xl, yr);

	glDrawArrays(GL_QUADS, 0, 4);
}

PSGLdevice*				ESVideo::Device;
PSGLcontext*			ESVideo::Context;

GLfloat*				ESVideo::VertexBuffer;

uint32_t				ESVideo::ScreenWidth;
uint32_t				ESVideo::ScreenHeight;
bool					ESVideo::WideScreen;

