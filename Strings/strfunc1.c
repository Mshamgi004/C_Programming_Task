//#include<stdio.h>
//#include<string.h>
#include "stringfun.h"


// Function to check the length of string
int stringLength(const char string[])
{
	int count = 0;
	
	while(string[count] != '\0')
		++count;
	
	return count;	
}	
