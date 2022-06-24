#include<stdio.h>
#include<stdlib.h>
#include "memeoryleak.h"

// source file (.c) file in which the function defination is declared

int * func(int * pointer)
{
	pointer = malloc(sizeof(int));
	
	//free(pointer);
	
	return pointer;
}	
