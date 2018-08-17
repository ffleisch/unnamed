#pragma once


#include "common.h"

#ifndef ERROR_INC
#define ERROR_INC


void throwError(std::string text);
class Error
{
public:
	Error();
	~Error();
};
#endif // !ERROR_INC
