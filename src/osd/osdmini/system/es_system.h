#ifndef PS3_SYSTEM_H____
#define PS3_SYSTEM_H____

#include "src/stdheaders.h"
#include "src/ESException.h"
inline void				ErrorCheck					(bool aCondition, const char* aMessage, ...)
{
#ifdef USE_ERRORCHECK
	if(!aCondition)
	{
		char buffer[2048];

		va_list args;
		va_start (args, aMessage);
		vsnprintf(buffer, 2048, aMessage, args);
		va_end (args);

		throw ESException(buffer);
	}
#endif
}

#include "src/ESThreads.h"
#include "src/ESTexture.h"
#include "src/ESAudio.h"
#include "src/ESNetwork.h"
#include "src/main.h"

# include "cell/CellPlatform.h"
# include "cell/CellThreads.h"
# include "opengl_common/Texture.h"
# include "cell/CellAudio.h"
# include "cell/CellNetwork.h"

#include "src/Helpers.h"

#endif
