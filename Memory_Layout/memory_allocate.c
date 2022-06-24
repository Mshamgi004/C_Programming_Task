// C program to learn the concept of memory allocation in C programming

#include<stdio.h>
#include<stdlib.h>

// Global variables initialized which are stored in Data Segment
int gdata = 10;
static int sdata;

// Function to calculate the sum of two values
void sum(int var_1, int var_2)
{
	int sum_result = 0;
	sum_result = var_1 + var_2;
	//sum_result++;
	display(sum_result);
}

// Function to display the sum of two numbers
void display(int result)
{
	printf(" sum = %d\n", result);
}

int main()
{
	// Local variables initialized which are stored in Stack
	int num1 = 10;
	int num2 = 15;
	
	//static int sumdata;
	
	// Dynamic memeory allocated in Heap for a size of integer value = 4 bytes
	int *ptr = (int *)malloc(sizeof(int));
	// Assigning value to the pointer = 10
	*ptr = 10;
	
	// Calling the function sum
	sum(num1,num2);
	
	printf("----------\n");
	
	// Printing the size of different values of pointer
	printf("The size of the ptr = %d\n", ptr);
	printf("The address of the ptr = %d\n",&ptr);
	printf("The value of the ptr pointing to = %d\n",*ptr);
	printf("The value  = %d\n",sumdata);
	
	free(ptr);
	return 0;
}		
			
