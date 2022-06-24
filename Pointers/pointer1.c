// C program to study the use of accesing the pointers and also defrerencing the pointers

#include<stdio.h>

/*
int main()
{
	int number = 15;
	int *ptr = &number;
	
	int result = 0;
	result = *ptr + 5;
	
	printf("The output is  = %d", result);
	
	return 0;
}	
*/

/*
int main()
{
	int number = 10;
	int val;
	
	int *pointer = &number;
	val = *pointer;
	
	printf("The value of number = %p\n",number);
	printf("The value of val = %d\n",val);
	
	return 0;
}	
*/

int main()
{
	int number;
	int *ptr = NULL;
	
	number = 10;
	
	printf("The value of number = %d\n", number);
	printf("The value of address = %d\n", &number);
	
	ptr = &number;
	
	printf("-------------------------------------------\n");
	printf("ptr address = %d\n", &ptr);
	printf("ptr value = %d\n", ptr);
	printf("ptr size = %d bytes \n",(int)sizeof(ptr));
	printf("ptr value pointed to  = %d\n", *ptr);
	
	return 0;
}	
	 
	
	
	
