// C program to show the functioning of memory layout using the functions.
// This code is written with the help of C libraries.

#include<stdio.h>
#include<stdlib.h>
#include "memory.h"


// main() function to print the size and memory of the pointer
int main(int argc, int argv[])
{
	int loc_var_main;
	
	int *pointer = malloc(sizeof(int));
	printf("the size of memory allocated = %d\n", pointer);
	
	printf("the address = %d\n", &pointer);
	
	func();
	
	return 0;
}	
		
	
	
