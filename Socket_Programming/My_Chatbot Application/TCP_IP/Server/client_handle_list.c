#include "server.h"

// -------------------------------------Modifying the logic for file operation-------------------------------------//

/*
void client_handle_list(char* client_buffer, char* ip, char* port_number)
{
	char *search;
	int wordExist = 0;
	
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

	strcpy(search, client_buffer);
	fprintf(fptr, "Name: %s\n", client_buffer);
	strcpy(search, ip);
	fprintf(fptr, "IP Address: %s\n", ip);
	strcpy(search, port_number);
	fprintf(fptr, "Port Number: %s\n", port_number);

	fclose(fptr);

	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr,"\nError to open the file\n");
		exit(1);
	}
	else
	{
		printf("File opened for reading\n");
	}

	// //fwrite (&detail, sizeof(struct client), 1, fptr);
	// if (strlen(client_buffer) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(client_buffer, fptr);
	// 	fputs("\n", fptr);
	// }
	// else
	// {
	// 	printf("Not able to print the name\n");
	// }

	// if (strlen(ip) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(ip, fptr);
	// 	fputs("\n", fptr);
	// }
	// else
	// {
	// 	printf("Not able to print the ip address\n");
	// }
	// if(strlen(port_number) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(port_number, fptr) ;
	// 	fputs("\n", fptr) ;
	// }
	// else
	// {
	// 	printf("Not able to print the port no\n");
	// }

	//----------------------------------------------------------WORKING----------------------------------------------------//
	
 	while (fgets(client_buffer,MAX_BUFFER_SIZE, fptr) != NULL) 
	{
        printf("NAME = %s\n", client_buffer);
		//fprintf(fptr, "Name: %s\n", client_buffer);
		if(strstr(client_buffer,search) != NULL)
		{
			wordExist = 1;
			break;
		}
		fclose(fptr);

		if(wordExist == 1)
		{
			printf("Client name already regisitered\n");
		}
		else
		{
			printf("New data added\n");
			fptr = fopen("CLIENT_INFO.txt", "a");
			// strcpy(search, client_buffer);
			// fprintf(fptr, "Name: %s\n", client_buffer);
		}
    }
	while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
	{
		printf("IP ADDRESS = %s\n", ip);
		//fprintf(fptr, "IP Address: %s\n", ip);
		if(strstr(ip,search) != NULL)
		{
			wordExist = 1;
			break;
		}
		fclose(fptr);

		if(wordExist == 1)
		{
			printf("Client name already regisitered\n");
		}
		else
		{
			printf("New data added\n");
			fptr = fopen("CLIENT_INFO.txt", "a");
			
		}
	}
	while(fgets(port_number,MAX_BUFFER_SIZE,fptr) != NULL)
	{
		printf("Port_number = %s\n", port_number);
		//fprintf(fptr,"Port number: %s\n", port_number);
		if(strstr(port_number,search) != NULL)
		{
			wordExist = 1;
			break;
		}
		fclose(fptr);

		if(wordExist == 1)
		{
			printf("Client name already regisitered\n");
		}
		else
		{
			printf("New data added\n");
			fptr = fopen("CLIENT_INFO.txt", "a");
		}
	}
	
	//fclose (fptr);
}
*/
//--------------------------------------------------------------WORKING ON THE FILE OPERATION PART-------------------------------------------------//
void client_handle_list(char* client_buffer, char* ip, char* port_number)
{
	struct client detail;

	char *search = malloc(1000);

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

	strcpy(search, client_buffer);
	fprintf(fptr, "Name: %s\n", client_buffer);
	strcpy(search, ip);
	fprintf(fptr, "IP Address: %s\n", ip);
	strcpy(search, port_number);
	fprintf(fptr, "Port Number: %s\n", port_number);

	detail.client_name = get_client_name(client_buffer);
	if(detail.client_name != 0)
	{
		fwrite(&detail, sizeof(client), 1, fptr);
	}
	else
	{
		printf("New content\n");
	}

	fclose(fptr);

	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in reading\n");
		exit(1);
	}
	while(fread(&detail, sizeof(client),1,fptr))
	{
		printf("%-10d%-20s%-15s", detail.client_name, detail.ip, detail.port);
	}

	get_client_name(client_buffer);

}

int get_client_name(char client_name)
{
	int nameExist = 0;
	
	FILE *fptr;
	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in reading the new content\n");
		exit(1);
	}

	struct client detail1;
	while(fread(&detail1, sizeof(client), 1, fptr))
	{
		if(detail1.client_name == client_name)
		{
			nameExist = 1;
		}
	}
	if(nameExist == 0)
	{
		return client_name;
	}
	else
	{
		return get_client_name(client_name);
	}

	return 0;
}
