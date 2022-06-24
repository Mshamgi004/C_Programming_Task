// Function definations 

//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
#include "stringfun.h"


// Function to check the length of string
int stringLength(const char string[])
{
	int count = 0;
	
	while(string[count] != '\0')
		++count;
	
	return count;	
}	

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
			
	
