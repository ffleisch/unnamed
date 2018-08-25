#pragma once


#include "common.h"

#ifndef ERROR_INC
#define ERROR_INC


void throwError(const char* text);
void throwWarning(const char* text);
void throwError(char* text);
void throwWarning(char* text);

#endif // !ERROR_INC
