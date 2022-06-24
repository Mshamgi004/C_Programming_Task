//#include<stdio.h>
#include<string.h>
#include "stringfun.h"




// Function to concatenate two strings
void stringConc(char result[], const char str1[], const char str2[])
{
	int val1,val2;
	
	
	for(val1 = 0; str1[val1] != '\0'; ++val1)
	{
		result[val1] = str1[val1];
	}
	
	for(val2 = 0; str2[val2] != '\0'; ++val2)
	{
		result[val1 + val2] = str2[val2];
	}
	
	result[val1 + val2] = '\0';
	
}	
