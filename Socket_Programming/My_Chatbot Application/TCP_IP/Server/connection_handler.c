#include "server.h"

// *****************************WORKING***************************** //
// Function defination to handle the client
void handle_connection(struct sockaddr_in client_information, int new_server_sockfd)
{
	//struct server_data server;
	//get the name, IP Address and port no: client 
	char ip[INET_ADDRSTRLEN] = { 0 };  // char buffer to store the ip address of connected clients
	char client_buffer[MAX_BUFFER_SIZE] = { 0 };   // char buffer to store the name of connected clients
	int port = ntohs(client_information.sin_port);
	char port_number[MAX_BUFFER_SIZE];

	char client1_password[MAX_BUFFER_SIZE] = { 0 };

	char file_buffer[10][100];
	
	inet_ntop(AF_INET, &(client_information.sin_addr), ip, INET_ADDRSTRLEN);
	
	server_recv_from_client(new_server_sockfd, client_buffer);  // Function call to recieve the name from client

	printf("\t||--------------Details of the client connected to server-----------------||\n");
	printf("\t||------------------------------------------------------------------------||\n");
	printf("\t|| [CLIENT NAME] : %s\n", client_buffer);
	printf("\t||------------------------------------------------------------------------||\n");
	printf("\t|| [IP ADDRESS]  : %s\n", ip);
	printf("\t||------------------------------------------------------------------------||\n");
	sprintf(port_number,"%d",port);
	printf("\t|| [PORT NUMBER] : %s\n",port_number); 
	printf("\t||------------------------------------------------------------------------||\n");
	printf("\t|| [FILE DESCRIPTOR = %d\n", new_server_sockfd);
	printf("\t||------------------------------------------------------------------------||\n");


	//printf("\t|| [PASSWORD]    : %s\n", client1_password);

	// client_handle_list(client_buffer, ip, port_number);
	get_client_details(client_buffer, ip, port_number,new_server_sockfd);


	printf("\t __________________Storing client data in CLIENT_INFO.txt___________________\n");

	// client_handle_list(client_buffer, ip, port_number);
	// To check for the no. of clients connected 
	if (server.total_client >= NO_OF_CLIENTS)
	{
		printf("****ERROR : No more space for client to save****\n");
	}

	//populate the new client data and saving it in client_list
	strncpy(server.client_list[server.total_client].client_name, client_buffer, strlen(client_buffer));
	//printf("Name = %s\n",server.client_list[server.total_client].client_name);
	server.client_list[server.total_client].port = port;
	strcpy(server.client_list[server.total_client].ip, ip);
	server.client_list[server.total_client].file_des = new_server_sockfd;
	//printf("File des = %d\n",server.client_list[server.total_client].file_des);

	//strncpy(server.client_list[server.total_client].client_password, client1_password, strlen(client1_password));
	server.total_client++;
}
	// FILE *fptr;
	// fptr = fopen("CLIENT_INFO.txt", "a+");
	// if(fptr == NULL)
	// {
	// 	fprintf(stderr, "Error in opeing the file for reading\n");
	// 	exit(1);
	// }

	// //strcpy(server.client_list[server.total_client].client_name, client_buffer);
	// //fwrite(&server, sizeof(struct server_data), 1, fptr);
	//fprintf(fptr, "%s\n",client_buffer);
	//fprintf(fptr, "IP Address = %s\n", ip);
	//fprintf(fptr, "Port Number = %s\n", port_number);
	//printf("Name = %s",server.client_list[server.total_client].client_name);

	// int file_results = fputs(file_buffer, fptr);

	// int line = 0;

	// while(!feof(fptr) && !ferror(fptr))
	// {
	// 	if(fgets(file_buffer[line], 100, fptr) != NULL)
	// 	{
	// 		line++;
	// 	}
	// }

	// for(int i = 0; i < line; i++)
	// {
	// 	printf("file_buffer = %s\n", file_buffer[i]);
	// }
	//fclose(fptr);

	// for(int i = 0; i < line; i++)
	// {
	// 	printf("file_buffer = %s\n", file_buffer[i]);
	// }
	
	// printf("file_buff = %s\n", file_buffer);

	//fclose(fptr);


	// client_handle_list(client_buffer, ip, port_number);
	//get_client_details(client_buffer, ip, port_number);
	
	// client_handle_list(client_buffer, ip, port_number);
	//get_client_details(client_buffer, ip, port_number);

	// 1: First append the data in a file CLIENT_INFO.txt


	// FILE *fptr;
	// fptr = fopen("CLIENT_INFO.txt", "a+");
	// if(fptr == NULL)
	// {
	// 	fprintf(stderr, "Error in opening the file for appending\n");
	// 	exit(1);
	// }
	
	// printf("New file created\n");
	// strncpy(server.client_list[server.total_client].client_name, client_buffer, strlen(client_buffer));
	// printf("NAME = %s\n",server.client_list[server.total_client].client_name);
	// server.client_list[server.total_client].port = port;
	// printf("Port number = %d\n",server.client_list[server.total_client].port);
	// strcpy(server.client_list[server.total_client].ip, ip);
	// printf("IP ADDRESS = %s\n",server.client_list[server.total_client].ip);
	// server.client_list[server.total_client].file_des = new_server_sockfd;
	// printf("FILE des = %d",server.client_list[server.total_client].file_des);
	// // printf("New file created\n");
	// // strcpy(values.client_name, client_buffer);
	// // printf("%s\n", values.client_name);
	// // values.port = port;
	// // printf("%d\n",port);
	// // strcpy(values.ip, ip);
	// // printf("%s\n",ip);
	// // values.file_des = new_server_sockfd;
	// // printf("%d\n", values.file_des);
	// // server.total_client++;
	// // printf("All values stored\n");
	// //values.client_name = client_buffer;

	// printf("Condition check\n");
	// //fwrite(&values,sizeof(struct client),1,fptr);
	// fwrite(&server,sizeof(struct server_data), 1, fptr);
	// if(strlen(server.client_list[server.total_client].client_name) > 0)
	// {
	// 	fputs(server.client_list[server.total_client].client_name, fptr);
	// 	fputs("\n",fptr);
	// }
	
	// if(strlen(values.client_name) > 0)
	// {
	// 	fputs(values.client_name,fptr);
	// 	fputs("\n",fptr);
	// }
	// if(values.client_name != 0)
	// {
		//fwrite(&values, sizeof(struct client), 1, fptr);
		//fprintf(fptr, "Name = %s\n", values.client_name);
	//}
	//fwrite(&values, (struct client), 1, fptr);
	//server.total_client++;
	
	// 2: Second display the data in file operation
	// display();
	// printf("Reachd display\n");

	// // 3: Get the client data in file
	// //values.client_name = get_client_details(client_buffer);
	// get_client_details(client_buffer);
	// printf("Reached get_client_details\n");

	//client_handle_list(client_buffer, ip, port_number);

	//server.total_client++;

