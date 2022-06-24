// C program to understand the complete structure of code that is stored in Memory layout //

#include<stdio.h>
#include<stdlib.h>

// Global Constant variables are stored in .rodata(Code segment) section of code segment......
const int var_1 = 4;

// Global uninitialized static variable are stored in .bss(Uninitialized data segment) section of the memory layout.........
static int var_2;

// Global initialized static variable are stored in .data(Initialized data segment) section of the memory layout.........
static int var_3 = 5;

// Global ininitialized variable stored in .data section of data segment...
int var_4 = -10;

// Global uniniitialized variable stored in .bss section of data segment...
int var_5;

int main(int argc, char argv[])
{	
	// Local variables are stored in stack
	int var_6;
	
	// Unitnitialized local static variables are stored in .bss segment(Data segment)
	static int var_7;
	
	// Initiialized local static variables are stored in .data segment(Data segment)
	static int var_8 = 8;
	
	char *var_0 = "This is stored in .rodata";
	char var_10[100] = "This is stored in stack";
	
	// Local constant variables are stored in stack
	const int var_11 = 5; 
	
	// Printing all the values to check the output.....
	printf("%d\n", var_1);
	printf("%d\n", var_2);
	printf("%d\n", var_3);
	printf("%d\n", var_4);
	printf("%d\n", var_5);
	printf("%d\n", var_6);
	printf("%d\n", var_7);
	printf("%d\n", var_8);
	printf("%x\n", *var_0);
	printf("%s\n", var_10);
	printf("%d\n", var_11);
	
	return 0;
}	
	


