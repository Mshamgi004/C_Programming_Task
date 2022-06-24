// C program to understand the concept of strings with pointers

#include "pointer_str.h"


int main(void)
{
	char string1[50] = "A string is to be copied";
	char string2[50];
	
	copyString(string2, string1);
	printf("%s\n", string2);
	
}	
