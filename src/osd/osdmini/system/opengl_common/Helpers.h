#pragma once

#ifdef	MDCELL
#define	glOrtho	glOrthof
#endif

struct							OpenGLHelp
{
	static void					SetVertex				(GLfloat* aBase, float aX, float aY, float aU, float aV)
	{
		*aBase++ = aX; *aBase++ = aY; *aBase++ = 0.0f;
		*aBase++ = aU; *aBase++ = aV;
	}

	static void					InitializeState			()
	{
		//Some settings
		glClearColor(0, 0, 0, 0);

		//Setup Projection
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight(), 0, -1, 1);
	}
};

