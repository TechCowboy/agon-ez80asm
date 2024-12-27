#ifndef MACRO_H
#define MACRO_H

#include "defines.h"

extern uint8_t macroCounter;
extern uint24_t macromemsize;
extern uint24_t macroExpandID;

void      initMacros(void);
bool defineMacro(char *invocation, struct contentitem *ci);
uint8_t   macroExpandArg(char *dst, const char *src, const macro_t *m);
bool      readMacroBody(struct contentitem *ci);
bool      parseMacroInvocation(char *str, char **name, uint8_t *argcount, char *arglist);

#endif // MACRO_H
