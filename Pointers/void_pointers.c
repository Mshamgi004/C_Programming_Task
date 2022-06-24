// C program to understand the use of void pointers

#include<stdio.h>

int main()
{
	// declaring the variables of type int, float, char
	int value1 = 10;
	float value2 = 10.00;
	char value3 = 'V';
	
	// Initaializing a void pointer
	void *pValue;
	
	// Storing the value of integer type in void pointer and printing it
	pValue = &value1;
	printf("The value of integer = %d\n",  *(int *)pValue);
	
	// Storing the value of float type in void pointer and printing it
	pValue = &value2;
	printf("The value of float = %0.2f\n",  *(float *)pValue);
	
	// Storing the value of char type in void pointer and printing it
	pValue = &value3;
	printf("The value of char = %c\n",  *(char *)pValue);
	
	return 0;
}	
	 
