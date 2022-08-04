#include "server.h"

void client_handle_list(char* client_buffer, char* ip, char* port_number)
{
	int val_read;
	FILE* fptr;
	fptr = fopen("CLIENT_INFO.txt", "a+");
	if (fptr == NULL)
	{
		fprintf(stderr, "\nError to open the file\n");
		exit(1);
	}
	else
	{
		printf("----FILE OPENED SUCCESSFULLY----\n");
	}

	//fwrite (&detail, sizeof(struct client), 1, fptr);
	if (strlen(client_buffer) > 0)
	{
		// writing in the file using fputs()
		fputs(client_buffer, fptr);
		fputs("\n", fptr);
	}
	else
	{
		printf("Not able to print the name\n");
	}

	if (strlen(ip) > 0)
	{
		// writing in the file using fputs()
		fputs(ip, fptr);
		fputs("\n", fptr);
	}
	else
	{
		printf("Not able to print the ip address\n");
	}
	if(strlen(port_number) > 0)
	{
		// writing in the file using fputs()
		fputs(port_number, fptr) ;
		fputs("\n", fptr) ;
	}
	else
	{
		printf("Not able to print the port no\n");
	}
	
 	while (fgets(client_buffer,MAX_BUFFER_SIZE, fptr) != NULL) 
	{
        printf("NAME = %s\n", client_buffer);
    }
	while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
	{
		printf("IP ADDRESS = %s\n", ip);
	}
	while(fgets(port_number,MAX_BUFFER_SIZE,fptr) != NULL)
	{
		printf("Port_number = %s\n", port_number);
	}

	
	fclose (fptr);
}
