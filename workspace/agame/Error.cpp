#include "Error.h"

void throwError(const char* text)
{
	printf("Error: %s",text);
	char t;
	scanf_s("%c",&t);
	exit(-1);
}
void throwWarning(const char * text)
{
	printf("Warning: %s", text);
}
void throwError(char* text)
{
	printf("Error: %s", text);
	char t;
	scanf_s("%c", &t);
	exit(-1);
}

void throwWarning(char * text)
{
	printf("Warning: %s", text);
}