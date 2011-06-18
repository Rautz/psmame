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

	static void					EnterPresentState		()
	{
		glColor4f(1, 1, 1, 1);
		glDisable(GL_BLEND);
		glDisable(GL_SCISSOR_TEST);
	}

	static void					ExitPresentState		()
	{
		glEnable(GL_BLEND);
		glEnable(GL_SCISSOR_TEST);
		glColor4f(0, 0, 0, 0);
	}

	static const Area&			CalculatePresentArea	(int32_t aAspectOverride, int32_t aUnderscan, const Area& aUnderscanFine)
	{
		static Area PresentArea;
		static int32_t LastAspect;
		static int32_t LastUnderscan;
		static Area LastUnderscanFine;

		if(aAspectOverride != LastAspect || LastUnderscan != aUnderscan || aUnderscanFine != LastUnderscanFine)
		{
			LastAspect = aAspectOverride;
			LastUnderscan = aUnderscan;
			LastUnderscanFine = aUnderscanFine;

			int32_t xLeft = 0, xRight = ESVideo::GetScreenWidth(), yTop = 0, yBottom = ESVideo::GetScreenHeight();
			float fwidth = (float)ESVideo::GetScreenWidth();
			float fheight = (float)ESVideo::GetScreenHeight();

			if((LastAspect == 0 && ESVideo::IsWideScreen()) || (LastAspect < 0))
			{
				xLeft += (int32_t)(fwidth * .125f);
				xRight -= (int32_t)(fwidth * .125f);
				fwidth -= fwidth * .250f;
			}

			xLeft += (int32_t)(fwidth * ((float)(LastUnderscan + LastUnderscanFine.X) / 200.0f));
			xRight -= (int32_t)(fwidth * ((float)(LastUnderscan + LastUnderscanFine.Width) / 200.0f));
			yTop += (int32_t)(fheight * ((float)(LastUnderscan + LastUnderscanFine.Y) / 200.0f));
			yBottom -= (int32_t)(fheight * ((float)(LastUnderscan + LastUnderscanFine.Height) / 200.0f));

			PresentArea = Area(xLeft, yTop, xRight - xLeft, yBottom - yTop);
		}

		return PresentArea;
	}
};

