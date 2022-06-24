// C program to 

#include<stdio.h>

int main()
{	
	int number = 15;
	int *pNumber = NULL;
	
	pNumber = &number;
	
	printf("The value of pNumber: %d\n", pNumber);
	printf("The address of pNumber: %d\n", &pNumber);
	printf("The value of number: %d\n", number);
	printf("The address of number: %d\n", &number);
	printf("The value pNumber pointing to: %d\n", *pNumber);
	
	return 0;
}	
	
	
	
