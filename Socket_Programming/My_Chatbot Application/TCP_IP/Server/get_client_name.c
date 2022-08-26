#include "server.h"

//****************************WORKING******************************//
// Function defination to read the contents stored in file
int get_client_name(char client_buffer[MAX_BUFFER_SIZE])
{
	/*
	char client_buffer[MAX_BUFFER_SIZE];
	int nameExist = 0;
	
	FILE *fptr;
	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in reading the new content\n");
		exit(1);
	}

	while(fread(&values, sizeof(struct client), 1, fptr))
	{
		if(values.client_name == client_buffer)
		{
			nameExist = 1;
		}
	}
	if(nameExist == 0)
	{
		return *client_buffer;
	}
	else
	{
		return get_client_name(client_buffer);
	}

	return 0;
	*/
	int found;
	FILE *fptr;
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in opening the file for reading\n");
		exit(1);
	}

	while(!feof(fptr))
	{
		fgets(client_buffer,MAX_BUFFER_SIZE,fptr);

		// if(strncmp(values.client_name, client_buffer,strlen(values.client_name)) == 0)
		// {
		// 	printf("Name = %s\n", client_buffer);
		// }
		// else
		// {
		// 	printf("Not found\n");
		// }
		if(strstr(client_buffer,values.client_name) != NULL)
		{
			printf("Name = %s\n", client_buffer);
			found = 1;
		}
		if(found == 0)
		{
			printf("Not found\n");
		}
	}
	return 0;
}
