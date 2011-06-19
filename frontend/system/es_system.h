#ifndef PS3_SYSTEM_H____
#define PS3_SYSTEM_H____

#include "src/stdheaders.h"
#include "src/ESException.h"
inline void				ErrorCheck					(bool aCondition, const char* aMessage, ...)
{
	if(!aCondition)
	{
		char buffer[2048];

		va_list args;
		va_start (args, aMessage);
		vsnprintf(buffer, 2048, aMessage, args);
		va_end (args);

		throw ESException(buffer);
	}
}

#include "src/ESThreads.h"
#include "src/ESTexture.h"
#include "src/ESVideo.h"
#include "src/ESInput.h"
#include "src/main.h"

#if defined(MDCELL)
# include "cell/CellPlatform.h"
# include "cell/CellThreads.h"
# include "opengl_common/Texture.h"
# include "cell/CellVideo.h"
# include "cell/CellInput.h"
#else
# include "sdl/SDLPlatform.h"
# include "sdl/SDLThreads.h"
# include "opengl_common/Texture.h"
# include "sdl/SDLVideo.h"
# include "sdl/SDLInput.h"
#endif

#include "src/Helpers.h"
#include "src/utility/Font.h"
#include "src/utility/ImageManager.h"
#include "src/utility/GUI/Menu.h"
#include "src/utility/GUI/Summerface.h"
#include "src/utility/Files/FileSelect.h"
#include "src/utility/Keyboard.h"
#include "src/utility/TextViewer.h"
#include "src/utility/Logger.h"

#endif
