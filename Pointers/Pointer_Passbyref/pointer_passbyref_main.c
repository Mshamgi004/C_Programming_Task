// C program to understand the pass by reference method
// Write a function to square the number by itself



#include "pointer_pass_ref.h"

int main()
{
	// Initializing the values
	//int num = 9;
	// Allocating the memory using malloc
	int *num = (int *)malloc(sizeof(int));
	
	// Defining the *num = 4
	*num = 4;
	
	// Calling the function 
	//square(&num);
	square(num);
	
	//printf("The square of given number is %d\n", num);
	printf("The square of given number is %d\n", *num);
	
	return 0;
}

	
	
	
