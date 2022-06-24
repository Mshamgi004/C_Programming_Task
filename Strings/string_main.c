// Challenge to create different functions for the operations on strings//

//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
#include "stringfun.h"

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
	
