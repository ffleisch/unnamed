#include "Error.h"

void throwError(const char* text)
{
	printf("Error: %s",text);
	char t;
	scanf_s("%c",&t);
	exit(-1);
}
void throwError(char* text)
{
	printf("Error: %s", text);
	char t;
	scanf_s("%c", &t);
	exit(-1);
}