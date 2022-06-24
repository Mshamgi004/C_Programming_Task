#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

// source file (.c) file in which the function defination is declared

int func()
{
	int loc_var_func;
	
	int *pointer = malloc(sizeof(int));
	
	free(pointer);
}
