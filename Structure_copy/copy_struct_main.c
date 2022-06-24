// Task 2
// Create a C program to copy structure into array with and without pragma packing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stucture.h"
//#pragma pack(1)

int main()
{
	int i;
	struct Person person = {"abcd"};
	unsigned char *buffer = (char*)malloc(sizeof(person));
	
	// printing the copied data
	printf("Copied byte of array is:\n");
	
	for(i=0; i < sizeof(person); i++)
	{
		printf("%d ",buffer[i]);
	}	
	printf("\n");
	printf("size of structure is %d",sizeof(person));
	
	//freeing memory..
	free(buffer);
	return 0;
}





