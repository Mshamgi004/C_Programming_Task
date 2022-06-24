// C program for performing the Pointer arithmetic 
// To show how we can use the poinetrs with array as function arguments

#include<stdio.h>

// Function to get sum in an array
int sumarray(int *arr, const int n)
{
	int sum = 0;
	int *const ArrayEnd = arr + n;
	
	for(; arr < ArrayEnd; arr++)
	{
		sum += *arr;
	}
	
	return sum;
}


void main(void)
{
	int sumarray(int *arr, const int n);	
	int values[10] = {-3, -2, -1, 0, 1, 2, 3};
	
	printf("The sum is %d\n", sumarray(values,10));
	
	
}
 

					 
