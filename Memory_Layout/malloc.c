// C program to understand the working of malloc()

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int *ptr = (int *)malloc(4*sizeof(int));
	
	if(!ptr)
	{
		printf("Error");
	}
	else
	{
		printf("Successfull memory allocation");
	}
	free(ptr);
	
	return 0;
}	
		 	
