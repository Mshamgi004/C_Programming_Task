// Implementing the use of malloc() function with realloc()

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	// DEclaring the character pointer
	char *string;
	
	// Initial memeory allocation 
	string = (char *)malloc(15);
	strcpy(string, "Coding");
	printf("String = %s, Address = %d\n",string, string);
	
	string = (char *)calloc(5,4);
	strcpy(string, "Team");
	printf("String = %s, Address = %d\n",string, string);
	
	
	// Reallocating the memory
	//string = (char *)realloc(string,25);
	strcat(string, "M");
	printf("Final String = %s, Address = %d\n", string, string);
	free(string);
	
	return 0;
}	 
