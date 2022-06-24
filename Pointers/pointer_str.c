// C program to understand the concept of strings with pointers


#include "pointer_str.h"

// Function to copy strings
void copyString(char *to, char *from)
{
	while( *from)   // the null charater will be equal to value 0, so it will jump out then
	
	*to++ = *from++;
	
	*to = '\0';
	//*from = '\0';
	
}


