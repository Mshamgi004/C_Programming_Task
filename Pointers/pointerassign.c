// C program to understand the working of pointer assigning 

#include<stdio.h>

int main()
{
	int number = 0;     // number variable of type int initialized top o
	int *ptrNum = NULL;  // ptrNum pointer that can point to type int
	
	number = 10;
	ptrNum = &number;      // Store the address of number in ptrNum
	
	*ptrNum += 25;        // Increameneting the value of ptrNum to 25
	
	
	// Printing the values
	printf("The value of ptrNum = %d\n", ptrNum);
	printf("The value of ptrNum = %d\n", &ptrNum);
	printf("The value of ptrNum = %d\n", *ptrNum);
	
	return 0;
}	
	
