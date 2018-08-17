#include "Error.h"

Error::Error()
{
}


Error::~Error()
{
}

void throwError(std::string text)
{
	printf("Error: %s",text);
	exit(-1);
}
