// Character array and pointer

#include "char1_pointer.h"

void print(char *Count)
{
	while(*Count != '\0')
	{
		printf("%c\n", *Count);
		Count++;
	}
}

		
