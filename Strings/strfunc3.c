//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
#include "stringfun.h"




// Function to compare two strings
bool stringComp(const char strA[], const char strB[])
{
	int val = 0;
	bool isEquals = false;
	
	while(strA[val] == strB[val] && 
		strA[val] != '\0' && 
		strB[val] != '\0' )
	
	++val;
	
	if(strA[val] == '\0' && strB[val] == '\0')
	{
		isEquals = true;
	}
	else
	{
		isEquals = false;
	}
	
	return isEquals;
}			
			
