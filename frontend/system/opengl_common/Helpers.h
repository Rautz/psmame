#pragma once

#ifdef	MDCELL
#define	glOrtho	glOrthof
#endif

struct							OpenGLHelp
{
	static void					SetVertex				(GLfloat* aBase, float aX, float aY, float aR, float aG, float aB, float aA, float aU, float aV)
	{
		*aBase++ = aX; *aBase++ = aY; *aBase++ = 0.0f;
		*aBase++ = aU; *aBase++ = aV;
		*aBase++ = aR; *aBase++ = aG; *aBase++ = aB; *aBase++ = aA;
	}

	static void					InitializeState			()
	{
		//Some settings
		glEnable(GL_SCISSOR_TEST);
		glClearColor(0, 0, 0, 0);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//Setup Projection
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight(), 0, -1, 1);
	}
};

