#include <es_system.h>

#ifndef __CELLOS_LV2__
# define	FRAG_PROFILE				cgGLGetLatestProfile(CG_GL_FRAGMENT)
# define	VERT_PROFILE				cgGLGetLatestProfile(CG_GL_VERTEX)
# define	glGenFramebuffersES			glGenFramebuffersEXT
# define	glDeleteFramebuffersES		glDeleteFramebuffersEXT
# define	glBindFramebufferES			glBindFramebufferEXT
# define	glFramebufferTexture2DES	glFramebufferTexture2DEXT
# define	GL_FRAMEBUFFER_ES			GL_FRAMEBUFFER_EXT
#else
# define	FRAG_PROFILE				CG_PROFILE_SCE_FP_RSX
# define	VERT_PROFILE				CG_PROFILE_SCE_VP_RSX
# define	glGenFramebuffersES			glGenFramebuffersOES
# define	glDeleteFramebuffersES		glDeleteFramebuffersOES
# define	glBindFramebufferES			glBindFramebufferOES
# define	glFramebufferTexture2DES	glFramebufferTexture2DOES
# define	GL_FRAMEBUFFER_ES			GL_FRAMEBUFFER_OES
# define	glOrtho						glOrthof
#endif

namespace
{
	const char*						StockShaderSource = 
		"void main_vertex"
		"("
		"	float4 position	: POSITION,"
		"	float4 color	: COLOR,"
		"	float2 texCoord : TEXCOORD0,"

		"    uniform float4x4 modelViewProj,"

		"	out float4 oPosition : POSITION,"
		"	out float4 oColor    : COLOR,"
		"	out float2 otexCoord : TEXCOORD"
		")"
		"{"
		"	oPosition = mul(modelViewProj, position);"
		"	oColor = color;"
		"	otexCoord = texCoord;"
		"}"
		"struct output"
		"{"
		"  float4 color    : COLOR;"
		"};"
		"struct input"
		"{"
		"  float2 video_size;"
		"  float2 texture_size;"
		"  float2 output_size;"
		"};"
		"output main_fragment(float2 texCoord : TEXCOORD0, uniform sampler2D decal : TEXUNIT0, uniform input IN)"
		"{"
		"   output OUT;"
		"   OUT.color = tex2D(decal, texCoord);"
		"   return OUT;"
		"}"
	;

	inline void						SetVertex							(GLfloat* aBase, float aX, float aY, float aU, float aV)
	{
		*aBase++ = aX; *aBase++ = aY; *aBase++ = 0.0f; *aBase++ = aU; *aBase++ = aV;
	}

	void							MakeVertexRectangle					(GLfloat* aBuffer, uint32_t aVerticalFlip, float aLeft, float aRight, float aTop, float aBottom)
	{
		SetVertex(aBuffer + 0,  0.0f,	0.0f,	aLeft, aVerticalFlip ? aBottom : aTop);
		SetVertex(aBuffer + 5,  1.0f,	0.0f,	aRight, aVerticalFlip ? aBottom : aTop);
		SetVertex(aBuffer + 10, 1.0f,	1.0f,	aRight, aVerticalFlip ? aTop : aBottom);
		SetVertex(aBuffer + 15, 0.0f,	1.0f,	aLeft, aVerticalFlip ? aTop : aBottom);
	}
}

ShaderMap GLShaderProgram::Shaders;

									GLShaderProgram::GLShaderProgram	(CGcontext& aContext, const std::string& aFileName) :
	Context(aContext),
	VertexProgram(0),
	FragmentProgram(0),
	Projection(0),
	FragmentVideoSize(0),
	FragmentTextureSize(0),
	FragmentOutputSize(0),
	VertexVideoSize(0),
	VertexTextureSize(0),
	VertexOutputSize(0)	
{
	if(!aFileName.empty() && Utility::FileExists(aFileName))
	{
#ifndef __CELLOS_LV2__
		cgGLSetOptimalOptions(cgGLGetLatestProfile(CG_GL_VERTEX));
		cgGLSetOptimalOptions(cgGLGetLatestProfile(CG_GL_FRAGMENT));
		VertexProgram = cgCreateProgramFromFile(Context, CG_SOURCE, aFileName.c_str(), VERT_PROFILE, "main_vertex", 0);
		FragmentProgram = cgCreateProgramFromFile(Context, CG_SOURCE, aFileName.c_str(), FRAG_PROFILE, "main_fragment", 0);
#else
		static const char* args[] = { "-fastmath", "-unroll=all", "-ifcvt=all", 0 };
		VertexProgram = cgCreateProgramFromFile(Context, CG_SOURCE, aFileName.c_str(), VERT_PROFILE, "main_vertex", args);
		FragmentProgram = cgCreateProgramFromFile(Context, CG_SOURCE, aFileName.c_str(), FRAG_PROFILE, "main_fragment", args);
#endif
	}
	else
	{
#ifndef __CELLOS_LV2__
		cgGLSetOptimalOptions(cgGLGetLatestProfile(CG_GL_VERTEX));
		cgGLSetOptimalOptions(cgGLGetLatestProfile(CG_GL_FRAGMENT));
		VertexProgram = cgCreateProgram(Context, CG_SOURCE, StockShaderSource, VERT_PROFILE, "main_vertex", 0);
		FragmentProgram = cgCreateProgram(Context, CG_SOURCE, StockShaderSource, FRAG_PROFILE, "main_fragment", 0);
#else
		static const char* args[] = { "-fastmath", "-unroll=all", "-ifcvt=all", 0 };
		VertexProgram = cgCreateProgram(Context, CG_SOURCE, StockShaderSource, VERT_PROFILE, "main_vertex", args);
		FragmentProgram = cgCreateProgram(Context, CG_SOURCE, StockShaderSource, FRAG_PROFILE, "main_fragment", args);
#endif
	}

	if(FragmentProgram && VertexProgram)
	{
		cgGLLoadProgram(VertexProgram);
		cgGLLoadProgram(FragmentProgram);

		cgGLEnableProfile(VERT_PROFILE);
		cgGLEnableProfile(FRAG_PROFILE);

		cgGLBindProgram(VertexProgram);
		cgGLBindProgram(FragmentProgram);

		Projection = cgGetNamedParameter(VertexProgram, "modelViewProj");
		FragmentVideoSize = cgGetNamedParameter(FragmentProgram, "IN.video_size");
		FragmentTextureSize = cgGetNamedParameter(FragmentProgram, "IN.texture_size");
		FragmentOutputSize = cgGetNamedParameter(FragmentProgram, "IN.output_size");
		FragmentFrameCount = cgGetNamedParameter(FragmentProgram, "IN.frame_count");
		VertexVideoSize = cgGetNamedParameter(VertexProgram, "IN.video_size");
		VertexTextureSize = cgGetNamedParameter(VertexProgram, "IN.texture_size");
		VertexOutputSize = cgGetNamedParameter(VertexProgram, "IN.output_size");
		VertexFrameCount = cgGetNamedParameter(VertexProgram, "IN.frame_count");

		cgGLDisableProfile(VERT_PROFILE);
		cgGLDisableProfile(FRAG_PROFILE);
	}
}

void								GLShaderProgram::Apply				(uint32_t aInWidth, uint32_t aInHeight, uint32_t aTextureWidth, uint32_t aTextureHeight, uint32_t aOutWidth, uint32_t aOutHeight, uint32_t aFrameCount)
{
	if(FragmentProgram && VertexProgram)
	{
		cgGLEnableProfile(VERT_PROFILE);
		cgGLEnableProfile(FRAG_PROFILE);

		cgGLBindProgram(VertexProgram);
		cgGLBindProgram(FragmentProgram);

		/* Update shader params */
		if(Projection)			cgGLSetStateMatrixParameter(Projection, CG_GL_MODELVIEW_PROJECTION_MATRIX, CG_GL_MATRIX_IDENTITY);
		if(FragmentVideoSize)	cgGLSetParameter2f(FragmentVideoSize, aInWidth, aInHeight);
		if(FragmentTextureSize)	cgGLSetParameter2f(FragmentTextureSize, aTextureWidth, aTextureHeight);
		if(FragmentOutputSize)	cgGLSetParameter2f(FragmentOutputSize, aOutWidth, aOutHeight);
		if(FragmentFrameCount)	cgGLSetParameter1f(FragmentFrameCount, aFrameCount);
		if(VertexVideoSize)		cgGLSetParameter2f(VertexVideoSize, aInWidth, aInHeight);
		if(VertexTextureSize)	cgGLSetParameter2f(VertexTextureSize, aTextureWidth, aTextureHeight);
		if(VertexOutputSize)	cgGLSetParameter2f(VertexOutputSize, aOutWidth, aOutHeight);
		if(VertexFrameCount)	cgGLSetParameter1f(VertexFrameCount, aFrameCount);
	}
	else
	{
		cgGLDisableProfile(VERT_PROFILE);
		cgGLDisableProfile(FRAG_PROFILE);
	}
}

GLShaderProgram*					GLShaderProgram::Get				(CGcontext& aContext, const std::string& aFileName)
{
	if(Shaders.find(aFileName) == Shaders.end())
	{
		Shaders[aFileName] = new GLShaderProgram(aContext, aFileName);
	}

	return Shaders[aFileName];
}


									GLShader::GLShader					(CGcontext& aContext, const std::string& aFileName, bool aSmooth, uint32_t aScaleFactor) :
	Context(aContext),
	Next(0),
	Program(GLShaderProgram::Get(aContext, aFileName)),
	Output(0, 0, 0, 0),
	InWidth(0),
	InHeight(0),
	TextureID(0),
	FrameBufferID(0),
	ScaleFactor(aScaleFactor),
	Smooth(aSmooth)
{
	Viewport[0] = 0.0f;
	Viewport[1] = 1.0f;
	Viewport[2] = 0.0f;
	Viewport[3] = 1.0f;

	glGenTextures(1, &TextureID);
	glGenFramebuffersES(1, &FrameBufferID);
}

									GLShader::~GLShader					()
{
	//Eat children (ungrateful bastards)
	if(Next)
	{
		delete Next;
	}

	glDeleteTextures(1, &TextureID);
	glDeleteFramebuffersES(1, &FrameBufferID);
}

void								GLShader::Present					(GLuint aSourceTexture, GLuint aBorderTexture)
{
	if(Next)
	{
		glBindFramebufferES(GL_FRAMEBUFFER_ES, FrameBufferID);
		glFramebufferTexture2DES(GL_FRAMEBUFFER_ES, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, TextureID, 0);
	}
	else
	{
		if(aBorderTexture)
		{
			glActiveTexture(GL_TEXTURE1);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, aBorderTexture);
			glActiveTexture(GL_TEXTURE0);
		}
	}

	//Update projection
	glViewport(Output.X, Output.Y, Output.Width, Output.Height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 1, 1, 0, -1, 1);

	//Apply state buffer
	GLShader::ApplyVertexBuffer(VertexBuffer, false, ((Next == 0) && aBorderTexture) ? 1 : 0);
	Apply();

	//Prep texture
	glBindTexture(GL_TEXTURE_2D, aSourceTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Smooth ? GL_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Smooth ? GL_LINEAR : GL_NEAREST);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	//Draw
	glDrawArrays(GL_QUADS, 0, 4);

	//Update count
	FrameCount ++;

	//Clean up projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	if(Next)
	{
		//Call next shader
		glBindFramebufferES(GL_FRAMEBUFFER_ES, 0);
		Next->Present(TextureID, aBorderTexture);
	}
	else
	{
		cgGLDisableProfile(VERT_PROFILE);
		cgGLDisableProfile(FRAG_PROFILE);

		if(aBorderTexture)
		{
			glActiveTexture(GL_TEXTURE1);	
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_TEXTURE_2D);
			glActiveTexture(GL_TEXTURE0);
		}

		//Restore viewport
		glViewport(0, 0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight());
	}
}

void								GLShader::Apply						()
{
	Program->Apply(InWidth, InHeight, TextureWidth, TextureHeight, Output.Width, Output.Height, FrameCount);
}

void								GLShader::SetViewport				(float aLeft, float aRight, float aTop, float aBottom)
{
	Viewport[0] = aLeft;
	Viewport[1] = aRight;
	Viewport[2] = aTop;
	Viewport[3] = aBottom;
	MakeVertexRectangle(VertexBuffer, Next ? 1 : 0, Viewport[0], Viewport[1], Viewport[2], Viewport[3]);
}

void								GLShader::Set						(const Area& aOutput, uint32_t aInWidth, uint32_t aInHeight, uint32_t aTextureWidth, uint32_t aTextureHeight)
{
	/* Copy settings */
	if(Output != aOutput || InWidth != aInWidth || InHeight != aInHeight || TextureWidth != aTextureWidth || TextureHeight != aTextureHeight)
	{
		Output = aOutput;
		InWidth = aInWidth;
		InHeight = aInHeight;
		TextureWidth = aTextureWidth;
		TextureHeight = aTextureHeight;

		/* Update smoothing */
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		/* Update texture */
		if(Next)
		{
//TODO: Round size up to next power of two
			Output = Area(0, 0, aInWidth * ScaleFactor, aInHeight * ScaleFactor);
#ifndef __CELLOS_LV2__
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, Output.Width, Output.Height, 0, GL_RGB, GL_INT, 0);
#else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_ARGB_SCE, Output.Width, Output.Height, 0, GL_ARGB_SCE, GL_UNSIGNED_INT_8_8_8_8_REV, 0);
#endif
		}
		else
		{
			/* Delete the texture ? */
#ifndef __CELLOS_LV2__
			glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, 1, 1, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8, 0);
#else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_ARGB_SCE, 1, 1, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, 0);
#endif
		}

		/* Update vertex buffer */
		MakeVertexRectangle(VertexBuffer, Next ? 1 : 0, Viewport[0], Viewport[1], Viewport[2], Viewport[3]);
	}

	if(Next)
	{
		Next->Set(aOutput, aInWidth * ScaleFactor, aInHeight * ScaleFactor, Output.Width, Output.Height);
	}
}

//
#include "SimpleIni.h"

GLShader*							GLShader::MakeChainFromPreset		(CGcontext& aContext, const std::string& aFile, uint32_t aPrescale)
{
	if(!aFile.empty() && Utility::FileExists(aFile))
	{
		CSimpleIniA ini;
		ini.LoadFile(aFile.c_str());

		std::string shader1 = (std::string("assets/shaders/") + ini.GetValue("PS3General", "PS3CurrentShader", ""));
		std::string shader2 = (std::string("assets/shaders/") + ini.GetValue("PS3General", "PS3CurrentShader2", ""));

		if(aPrescale > 1)
		{
			GLShader* output = new GLShader(aContext, "", 0, aPrescale);
			output->AttachNext(new GLShader(aContext, shader1, ini.GetLongValue("PS3General", "Smooth", 0), ini.GetLongValue("PS3General", "ScaleFactor", 1)));
			output->AttachNext(new GLShader(aContext, shader2, ini.GetLongValue("PS3General", "Smooth2", 0), 1));
			return output;
		}
		else
		{
			GLShader* output = new GLShader(aContext, shader1, ini.GetLongValue("PS3General", "Smooth", 0), ini.GetLongValue("PS3General", "ScaleFactor", 1));
			output->AttachNext(new GLShader(aContext, shader2, ini.GetLongValue("PS3General", "Smooth2", 0), 1));
			return output;
		}
	}
	else
	{
		return new GLShader(aContext, "", 0, 1);
	}
}

