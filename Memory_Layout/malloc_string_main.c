// C program to input a text string and allocate memory using malloc()

#include<stdio.h>
#include<stdlib.h>


int main()
{	
	int size;
	char *text = NULL;
	
	printf("Enter the limit of text: ");
	scanf("%d", &size);
	
	text = (char *)malloc(size * sizeof(char));
	
	if(text != NULL)
	{
		printf("Enter some text: ");
		scanf(" ");
		gets(text);
		printf("Inputted text is: %s\n", text);
	}
	free(text);
	text = NULL;
	
	return 0;
}	
		 
 
