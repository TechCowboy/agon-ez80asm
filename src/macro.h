#ifndef MACRO_H
#define MACRO_H

#include "defines.h"

extern uint8_t macroCounter;
extern uint24_t macromemsize;
extern uint24_t macroExpandID;

void      initMacros(void);
char *    readMacroBody(struct contentitem *ci);
macro_t * storeMacro(const char *name, char *buffer, uint8_t argcount, const char *arguments, uint16_t startlinenumber);
uint8_t   macroExpandArg(char *dst, const char *src, const macro_t *m);
bool      parseMacroDefinition(char *str, char **name, uint8_t *argcount, char *arglist);
bool      parseMacroArguments(macro_t *macro, char *invocation, char (*substitutionlist)[MACROARGSUBSTITUTIONLENGTH + 1]);
#endif // MACRO_H
