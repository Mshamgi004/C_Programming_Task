#include "client.h"

// Function defination of sending message to the server
int client_send_to_server(int client_socket, char* send_msg)
{
	int write_bytes = 0;   // Variable used for writing the message
	int len = strlen(send_msg);    // Declaring a socklen_t variable -> serlen
	char buffer[MAX_BUFFER_SIZE];
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE];
	int client_sockfd;

	// printf("Enter your name: \n");
	// fgets(buffer, 1024, stdin);
	// printf("Name = %s\n", buffer);
	// strcpy(client_name, buffer);
	// printf("Name = %s\n", client_name);
	// //printf("Enter your name:");
	// //scanf("%s\n", client_name);
	// strcpy(send_msg, client_name);
	//printf("Mess = %s\n", send_msg);

	if ((write_bytes = send(client_socket, send_msg, len, 0)) <= 0)   // Storing the send buffer in serlen
	{
		perror("****ERROR: send() failed*****\n");
		return -1;
	}
	else
	{
		//printf("--------ENTER THE APPLICATION--------\n");
		Client_decision();//(client_sockfd, send_buffer);
	}
	//Client_decision(client_sockfd, send_buffer);
	return write_bytes;
}

