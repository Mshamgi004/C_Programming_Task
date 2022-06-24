#include<stdio.h>
#include<string.h>
#include "pointerarith.h"


// Function defination of calculating the length of the string
int stringLength(const char *string)
{
	// Initialaizing a global pointer variable to store the address before the null terminator
	const char *lastAddress = string;
	
	// While loop to exit as it reaches a null pointer
	while(*lastAddress)
	{
		++lastAddress;
	}
	
	// Returning the length of the string by subtracting the last address with the first address
	return lastAddress - string;
	
}	
