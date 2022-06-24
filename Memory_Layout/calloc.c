// C program to understand the working of calloc()

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int *ptr = (int *)calloc(75,sizeof(int));
	
	if(!ptr)
	{
		printf("Error");
	}
	else
	{
		printf("Succesfull memory allocation");
	}
	
	free(ptr);
	
	return 0;
}	
				
