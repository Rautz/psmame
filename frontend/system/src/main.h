#pragma once

//ES Interfaces with happy macro
#define DEC_AND_DEF(a,b)	class a; extern a* b;

DEC_AND_DEF(ESThreads, es_threads);
DEC_AND_DEF(PathBuild, es_paths);

#undef DEC_AND_DEF

class	Logger;
typedef boost::shared_ptr<Logger> Logger_Ptr;
extern Logger_Ptr es_log;

//Happy functions
void					InitES					(void (*aExitFunction)() = 0);
void					QuitES					();
volatile bool			WantToDie				();
volatile bool			WantToSleep				();
void					Abort					(const char* aMessage);
void					ESSUB_Error				(const char* aMessage);
std::string				ESSUB_GetString			(const std::string& aHeader, const std::string& aMessage);
