#include "server.h"


//****************************WORKING******************************//
// Function defination to read the contents stored in file
int get_client_details(char *client_buffer, char *ip, char *port_number)
//int get_client_details(char *client_buffer, char *ip, char *port_number)
{

	int nameExist = 0;
	// FILE *fptr;

	// if(fptr = fopen("CLIENT_INFO.txt", "r") 
	// if(fptr == NULL)
	// {
	// 	fprintf(stderr, "Error in opening the file for reading\n");
	// 	exit(1);
	// }
	// FILE *fptr;
	// if(fptr = fopen("CLIENT_INFO.txt", "r"))   // Condition check for file is present or not ...
	// {
	// 	fclose(fptr);
	// 	printf("File exist\n");
	// 	//return -1;
	// }
	// else
	// {
		printf("Create a new file\n");                      
		fptr = fopen("CLIENT_INFO.txt", "a+");           // If not present create one and then append the data
		if(fptr == NULL)
		{
			fprintf(stderr, "Error in opening the file\n");
			exit(1);
		}
		strcpy(values.client_name, client_buffer);              // Copy the user input name client_buffer into structure holding client_name
		fprintf(fptr,"NAME = %s\n", values.client_name);       // Display 
		strcpy(values.ip, ip);                                  // Copy the IP address of user to structure ip
		fprintf(fptr,"IP ADDRESS = %s\n", ip);                 // Display 
		// strcpy(values.port, port_number);                      // Copy the port number of user to structure port number
		// fprintf(fptr, "Port number = %d\n", values.port);             // Display

		fclose(fptr);
	//}
	// strcpy(values.client_name, client_buffer);
	// fprintf(fptr,"NAME = %s\n", values.client_name);
	// strcpy(values.ip, ip);
	// fprintf(fptr,"IP ADDRESS = %s\n", ip);
	// strcpy(values.port, port_number);
	// fprintf(fptr,"PORT NUMBER = %s\n", port);

	printf("File opened for reading again\n");           
	fptr = fopen("CLIENT_INFO.txt", "r");                     // OPening the file for reading again
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in opening the file for reading\n");
		exit(1);
	}
	printf("FIle opened succcess for reading the data\n");

	//while(fread(&values, sizeof(struct client), 1, fptr))
	//while(fread(&server, sizeof(struct server_data), 1, fptr))         
	while(fgets(values.client_name, MAX_BUFFER_SIZE,fptr))   // Getting the valus of client_name
	{
	
		printf("Enter for strcmp()\n");
		if(strcmp(values.client_name, client_buffer) == 0)
		{
			printf("%s\n",values.client_name);
			printf("%s\n",client_buffer);
			nameExist = 1;
			printf("NAME ALREADY EXISTS\n");
			break;
		}
	}
	fclose(fptr);
		// while(fread(&server, sizeof(struct server_data), 1, fptr))
	// {
	// 	if(strcmp(server.client_list[server.total_client].client_name, client_buffer) == 0)
	// 	{
	// 		nameExist = 1;
	// 	}
	// }
	if(nameExist == 0)
	{
		// return *client_buffer;
		printf("NO MATCH FOUND\n");
	}
	else
	{
		printf("MATCH FOUND\n");//return get_client_details(client_buffer, ip, port_number);

	}

	//fclose(fptr);
}	

	/*
	FILE *fptr;
	if(fptr = fopen("CLIENT_INFO.txt", "r"))   // Condition check for 
	{
		fclose(fptr);
		printf("File exist\n");
		//return -1;
	}
	else
	{
		printf("File not exist\n");
		//printf("New file created and name added\n");
		fptr = fopen("CLIENT_INFO.txt","w");
		if(fptr == NULL)
		{
			fprintf(stderr, "Error in opening the file\n");
		}
		printf("New file created\n");
		fprintf(fptr, "Name = %s\n", client_buffer);

		fclose(fptr);
	}
	// fptr = fopen("CLIENT_INFO.txt", "r");
	// if(fptr == NULL)
	// {
	// 	fprintf(stderr, "Error in opening the file for writing\n");
	// 	exit(1);
	// }
	
	// fprintf(fptr, "Name = %s\n", client_buffer);
	// fprintf(fptr, "IP Address = %s\n",ip);
	// fprintf(fptr, "Port number = %s\n", port_number);
	
	// fclose(fptr);
	printf("New data to be read\n");
	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Error in opening the file for reading\n");
		exit(1);
	}

	while(fread(client_buffer, MAX_BUFFER_SIZE, 1, fptr))
	{
		//printf("Name = %s\n", client_buffer);

		int nameExist = 0;
	//char client_buffer[MAX_BUFFER_SIZE];

	//struct server_data server;
	//if(strcmp(values.client_name, client_buffer) != NULL)
		//if(strcmp(server.client_list[server.total_client].client_name, client_buffer) == 0)
		if(strcmp(values.client_name, client_buffer) == 0)
		{
			nameExist = 1;
			printf("Name already exixt");
			break;
		}
		// else if(nameExist == 1)
		// {
		// 	printf("Name already exixt\n");
		// }
		//else
		if(nameExist == 0)
		{
			printf("New name to be added\n");
			FILE *fptr;
			fptr = fopen("CLIENT_INFO.txt","a+");
			if(fptr == NULL)
			{
				fprintf(stderr, "Error in opening the file for writing\n");
				exit(1);
			}
			//fprintf(fptr, "Name = %s\n", client_buffer);
			//fwrite(client_buffer, MAX_BUFFER_SIZE, 1, fptr);
			fclose(fptr);
			printf("New name appended\n");
			break;
		}
	}
	printf("NNNN\n");
	return 0;
}	
*/
	/*
	while(fread(ip,INET_ADDRSTRLEN, 1, fptr))
	{
		printf("IP Address = %s\n", ip);
		FILE *fptr;
		fptr = fopen("CLIENT_INFO.txt","a+");
		if(fptr == NULL)
		{
			fprintf(stderr, "Error in opening the file for writing\n");
			exit(1);
		}

		fwrite(ip, INET_ADDRSTRLEN, 1, fptr);
		
		printf("New name appended\n");
	}
	while(fread(port_number, MAX_BUFFER_SIZE, 1, fptr))
	{
		printf("Port Number = %s\n", port_number);
		FILE *fptr;
		fptr = fopen("CLIENT_INFO.txt","a+");
		if(fptr == NULL)
		{
			fprintf(stderr, "Error in opening the file for writing\n");
			exit(1);
		}

		fwrite(port_number, MAX_BUFFER_SIZE, 1, fptr);
		
		printf("New name appended\n");
	}
	*/


	//int nameExist = 0;
	//char client_buffer[MAX_BUFFER_SIZE];

	//struct server_data server;
	//if(strcmp(values.client_name, client_buffer) != NULL)
	// if(strcmp(server.client_list[server.total_client].client_name, client_buffer) == 0)
	// {
	// 	nameExist = 1;
	// 	//break;
	// 	printf("Name already exixt");
	// }
	// // else if(nameExist == 1)
	// // {
	// // 	printf("Name already exixt\n");
	// // }
	// //else
	// if(nameExist == 0)
	// {
	// 	printf("New name to be added\n");
	// 	FILE *fptr;
	// 	fptr = fopen("CLIENT_INFO.txt","a+");
	// 	if(fptr == NULL)
	// 	{
	// 		fprintf(stderr, "Error in opening the file for writing\n");
	// 		exit(1);
	// 	}

	// 	while(fwrite(client_buffer, MAX_BUFFER_SIZE, 1, fptr))
	// 	{
	// 		printf("New name appended\n");
	// 	}

// 		fclose(fptr);

// 	}
// 	return 0;
// }

	// while(fread(client_buffer, MAX_BUFFER_SIZE, 1, fptr))
	// {
	// 	printf("Name = %s\n", client_buffer);
	// }
	// while(fread(ip,INET_ADDRSTRLEN, 1, fptr))
	// {
	// 	printf("IP Address = %s\n", ip);
	// }
	// while(fread(port_number, MAX_BUFFER_SIZE, 1, fptr))
	// {
	// 	printf("Port Number = %s\n", port_number);
	// }

	//server_check_detail(client_buffer);

// 	fclose(fptr);

// 	return 0;

// }

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
// 	int found;
// 	struct client values;
// 	FILE *fptr;
// 	if(fptr == NULL)
// 	{
// 		fprintf(stderr, "Error in opening the file for reading\n");
// 		exit(1);
// 	}

// 	while(!feof(fptr))
// 	{
// 		fgets(client_buffer,MAX_BUFFER_SIZE,fptr);

// 		// if(strncmp(values.client_name, client_buffer,strlen(values.client_name)) == 0)
// 		// {
// 		// 	printf("Name = %s\n", client_buffer);
// 		// }
// 		// else
// 		// {
// 		// 	printf("Not found\n");
// 		// }
// 		if(strstr(client_buffer,values.client_name) != NULL)
// 		{
// 			printf("Name = %s\n", client_buffer);
// 			found = 1;
// 		}
// 		if(found == 0)
// 		{
// 			printf("Not found\n");
// 		}
// 	}
// 	return 0;
// }


//****************************WORKING******************************//
// // Function defination to read the contents stored in file
// int get_client_name(char client_buffer[MAX_BUFFER_SIZE])
// {
// 	/*
// 	char client_buffer[MAX_BUFFER_SIZE];
// 	int nameExist = 0;
	
// 	FILE *fptr;
// 	fptr = fopen("CLIENT_INFO.txt", "r");
// 	if(fptr == NULL)
// 	{
// 		fprintf(stderr, "Error in reading the new content\n");
// 		exit(1);
// 	}
// 	while(fread(&values, sizeof(struct client), 1, fptr))
// 	{
// 		if(values.client_name == client_buffer)
// 		{
// 			nameExist = 1;
// 		}
// 	}
// 	if(nameExist == 0)
// 	{
// 		return *client_buffer;
// 	}
// 	else
// 	{
// 		return get_client_name(client_buffer);
// 	}
// 	return 0;
// 	*/
// 	int found;
// 	struct client values;
// 	FILE *fptr;
// 	if(fptr == NULL)
// 	{
// 		fprintf(stderr, "Error in opening the file for reading\n");
// 		exit(1);
// 	}

// 	while(!feof(fptr))
// 	{
// 		fgets(client_buffer,MAX_BUFFER_SIZE,fptr);

// 		// if(strncmp(values.client_name, client_buffer,strlen(values.client_name)) == 0)
// 		// {
// 		// 	printf("Name = %s\n", client_buffer);
// 		// }
// 		// else
// 		// {
// 		// 	printf("Not found\n");
// 		// }
// 		if(strstr(client_buffer,values.client_name) != NULL)
// 		{
// 			printf("Name = %s\n", client_buffer);
// 			found = 1;
// 		}
// 		if(found == 0)
// 		{
// 			printf("Not found\n");
// 		}
// 	}
// 	return 0;
// }

// //****************************WORKING******************************//
// // Function defination to read the contents stored in file
// /*
// int get_client_name(char *client_buffer)
// {
// 	/*
// 	char client_buffer[MAX_BUFFER_SIZE];
// 	int nameExist = 0;
	
// 	FILE *fptr;
// 	fptr = fopen("CLIENT_INFO.txt", "r");
// 	if(fptr == NULL)
// 	{
// 		fprintf(stderr, "Error in reading the new content\n");
// 		exit(1);
// 	}

// 	while(fread(&values, sizeof(struct client), 1, fptr))
// 	{
// 		if(values.client_name == client_buffer)
// 		{
// 			nameExist = 1;
// 		}
// 	}
// 	if(nameExist == 0)
// 	{
// 		return *client_buffer;
// 	}
// 	else
// 	{
// 		return get_client_name(client_buffer);
// 	}

// 	return 0;
// 	*/
// 	//int found;
// 	// FILE *fptr;
// 	// fptr = fopen("CLIENT_LIST.txt", "r");
// 	// if(fptr == NULL)
// 	// {
// 	// 	fprintf(stderr, "Error in opening the file for reading\n");
// 	// 	exit(1);
// 	// }

// 	// while(!feof(fptr))
// 	// {
// 	// 	if(fgets(client_buffer,MAX_BUFFER_SIZE,fptr) == NULL)
// 	// 	{
// 	// 		fprintf(stderr, "Error in getting the file\n");
// 	// 		exit(1);
// 	// 	}
// 	// }

// 	//fclose(fptr);
// 		// if(strncmp(values.client_name, client_buffer,strlen(values.client_name)) == 0)
// 		// {
// 		// 	printf("Name = %s\n", client_buffer);
// 		// }
// 		// else
// 		// {
// 		// 	printf("Not found\n");
// 		// }
// 	// 	if(strstr(client_buffer,values.client_name) != NULL)
// 	// 	{
// 	// 		printf("Name = %s\n", client_buffer);
// 	// 		found = 1;
// 	// 	}
// 	// 	if(found == 0)
// 	// 	{
// 	// 		printf("Not found\n");
// 	// 	}
// // 	if (strcmp (values.client_name, client_buffer) == 0) /* test if strings are equal */
// //         //printf ("\n string  : %s\n teststr : %s  EQUAL\n", str, teststr);
// //         printf("Name alreday exists\n");
// //    	else
// //         //printf ("\n string  : %s\n teststr : %s  DIFFER\n", str, teststr);
// //         printf("New name to be added\n");
// //         // fptr = fopen("File.txt", "a+");
// //         // if(fptr == NULL)
// //         // {
// //         //     fprintf(stderr, "Error in opeing th efile\n");
// //         // }
// //         // fprintf(fptr,"%s",val.str);
// //         // fclose(fptr);
// // 	// }
		
// // 	return 0;
// // }

