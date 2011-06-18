#pragma once

//ES Interfaces with happy macro
#define DEC_AND_DEF(a,b)	class a; extern a* b;

DEC_AND_DEF(ESThreads, es_threads);

#undef DEC_AND_DEF

//Happy functions
void					InitES					(void (*aExitFunction)() = 0);
void					QuitES					();
volatile bool			WantToDie				();
volatile bool			WantToSleep				();

