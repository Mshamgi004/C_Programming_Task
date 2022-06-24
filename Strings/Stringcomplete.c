#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// Function to calculate the string length
int stringLength(const char string[]);

// Function to concatenate two strings
void stringConc(char result[], const char str1[], const char str2[]);

// Function to compare two strings
bool stringComp(const char strA[], const char strB[]);

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
			
			
int main()
{	
	// Declaring two char strings
	const char word1[] = "Mahadev";
	const char word2[] = "GI";
	
	// storing the result in array
	char result[100];
	
	// Printing the length of the string(word1)
	printf("Length of the string = %d\n", stringLength(word1));
	
	// Calling the method for concatenation of two strings
	stringConc(result,word1,word2);
	
	// Printing the concatenated strings
	printf("Concatenated string :%s\n",result);
	
	// Printing the result in boolen values after comparing two strings
	printf("Result in bool value = %d\n", stringComp("Mahadev", "Mahadev"));
	printf("Result in bool value = %d\n", stringComp("Mahadev", "Mahadevs"));
	
	return 0;
	
}
