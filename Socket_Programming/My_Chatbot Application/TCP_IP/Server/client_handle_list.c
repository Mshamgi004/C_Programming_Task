#include "server.h"

// Fucntion defination to store the client details in the (.txt) file

// *****************************WORKING*********************************//
void client_handle_list(struct client detail)
{	
	struct client_file
	{
		char client_buffer[MAX_BUFFER_SIZE];
		char ip[INET_ADDRSTRLEN];
		int port;
	}list;

   	FILE *fptr;
   	fptr = fopen("CLIENT_INFO.txt", "w");
   	if (fptr == NULL) 
	{
    	fprintf(stderr, "\nError to open the file\n");
      	exit (1);
   	}

   	fwrite (&list, sizeof(struct client_file), 1, fptr);
   	
   	if(fwrite != 0)
	{
		printf("Contents to file written successfully !\n");
	}
    else
	{
    	printf("Error writing file !\n");
	}	
   	fclose (fptr);
   	
	FILE *fptr1;
   	
   	fptr1 = fopen ("CLIENT_INFO.txt", "r");
   	if (fptr1 == NULL) 
	{
      	fprintf(stderr, "\nError to open the file\n");
      	exit (1);
   	}
  	while(fread(&list, sizeof(struct client_file), 1, fptr1))
	{
    	printf("NAME = %s\n", list.client_buffer);
		printf("IP Address = %s\n", list.ip);
		printf("Port = %d\n", list.port);
	}	
   	fclose (fptr1);
}
