// Pointer arithmetic operation to understand the concepts

#include<stdio.h>

int main()
{
	// Declaring the variables num1
	int num1 = 0;
	// Declaring the variables num2
	int num2 = 0;
	// Declaring the pointer variable pNum
	int *pNum = NULL;
	
	// Storing the address of num1 in pNum
	pNum = &num1;
	// Assigning value of num1 = 2 by using *pNum
	*pNum = 2;
	// Increamenting the value of num2 by 1
	++num2;
	
	// Increameneting the value of num2 with num1
	num2 += *pNum;
	// Storing the address of num2 in pNum 
	pNum = &num2;
	// Increameneting the value of pNum by 1 
	++*pNum;
	
	// Prining the output values 
	printf(" num1 = %d\n num2 = %d\n pNum = %d\n *pNum = %d\n num1 + num2 = %d\n pNum + *pNum = %d\n *pNum + num1 = %d\n *pNum + num2 = %d\n ", num1, num2, pNum, *pNum, num1 + num2, pNum + *pNum, *pNum + num1, *pNum + num2);
	
	printf("-----------------------------------------------------------\n");
	
	// Printing the address values 
	printf(" The address of num1 = %d\n The address of num2 = %d\n The address of pNum = %d\n The address of *pNum = %d\n ",  &num1, &num2, &pNum, &*pNum);
	
	return 0;
}	
