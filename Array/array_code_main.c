#include<stdio.h>
#include<stdlib.h>
#include "array.h"



int main()
{
	int *ptr = malloc(5);

	ptr[2] = 5;
	data[2] = 5;

	for(int i = 0; i < 5; i++)
	{
		printf("Address = %x\n",&ptr[i]);
		printf("Addressdata = %x\n",&data[i]);
	}

	*ptr = (int *)realloc(ptr, 5);

	ptr[7] = 10;

	for(int i = 0; i < 10; i++)
	{
		printf("Address = %d\n",ptr[i]);
		printf("Addressdata = %d\n",data[i]);
	}


	return 0;
}

