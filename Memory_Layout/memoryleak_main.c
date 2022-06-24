// Concept of memory leak in C programming
// Use of Dynamic memory allocation for the allocation memory in the heap section !!!

#include<stdio.h>
#include "memeoryleak.h"

int main(int argc, int argv[])
{
	int i;
 	int *pointer;

	for(i = 1; i < 10; i++)
	{
		printf("%d\n", i);
		pointer = func(pointer);
	}
	
	printf("The size of memory allocated is = %d\n", sizeof(pointer));
	printf("The address of memory allocated is = %d\n", &pointer);
	return 0;
}		
