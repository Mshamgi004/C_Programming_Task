#include "server.h"

// Function call to handle the text file in server side to read the contents of client
/************************************************WORKING****************************************/
void client_handle_list(char *client_buffer, char *ip)
{	
	int val_read;
   	FILE *fptr;
   	fptr = fopen("CLIENT_INFO.txt", "w");
   	if (fptr == NULL) 
	{
    	fprintf(stderr, "\nError to open the file\n");
      	exit (1);
   	}
	else
	{
		printf("FILE OPENED SUCCESSUFULLY\n");
	} 
	
	//fwrite (&detail, sizeof(struct client), 1, fptr);
	if(strlen(client_buffer) > 0)
	{
		// writing in the file using fputs()
		fputs(client_buffer, fptr) ;
		fputs("\n", fptr) ;
	}
	else
	{
		printf("Not able to print the name\n");
	}

	if(strlen(ip) > 0)
	{
		// writing in the file using fputs()
		fputs(ip, fptr) ;
		fputs("\n", fptr) ;
	}
	else
	{
		printf("Not able to print the ip address\n");
	}
	// if(strlen(port) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(port, fptr) ;
	// 	fputs("\n", fptr) ;
	// }
	// else
	// {
	// 	printf("Not able to print the port no\n");
	// }
	
	
	
   	// if(fwrite != 0)
	// {
	// 	printf("Contents to file written successfully !\n");
	// }
    // else
	// {
    // 	printf("Error writing file !\n");
	// }	
   	fclose(fptr);
   	
	fptr = fopen ("CLIENT_INFO.txt", "r");
   	if (fptr == NULL) 
	{
      	fprintf(stderr, "\nError to open the file\n");
      	exit(1);
   	}
	
	for(val_read = 0; val_read < server.total_client; val_read++)
	{
		printf("Started reading\n");
		//while(fread(&detail, sizeof(struct client), 1, fptr1))
		while(fgets(client_buffer,MAX_BUFFER_SIZE,fptr) != NULL)
		{
    	// printf("NAME = %s\n", detail.client_name);
		// printf("IP Address = %s\n", detail.ip);
		// printf("Port = %d\n", detail.port);
			printf("NAME = %s\n",client_buffer);
		}

		while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
		{
    		// printf("NAME = %s\n", detail.client_name);
			printf("IP Address = %s\n", ip);
			// printf("Port = %d\n", detail.port);
		
		}
	}

  	// //while(fread(&detail, sizeof(struct client), 1, fptr1))
	// while(fgets(client_buffer,MAX_BUFFER_SIZE,fptr) != NULL)
	// {
    // 	// printf("NAME = %s\n", detail.client_name);
	// 	// printf("IP Address = %s\n", detail.ip);
	// 	// printf("Port = %d\n", detail.port);
	// 	printf("NAME = %s\n",client_buffer);
	// }

	// while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
	// {
    // 	// printf("NAME = %s\n", detail.client_name);
	// 	printf("IP Address = %s\n", ip);
	// 	// printf("Port = %d\n", detail.port);
		
	// }
	
	

	// while(fgets(port,MAX_BUFFER_SIZE,fptr) != NULL)
	// {
    // 	printf("Port = %s\n", port);
  	// }
   	fclose (fptr);
}

