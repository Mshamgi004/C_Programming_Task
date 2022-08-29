#include "server.h"

// Function defination to send the message to client
int server_send_to_client(int client_socket, char* send_msg)
{
	int write_bytes = 0;   // Variable used for writing the message
	int server_length;   // Creating a variable -> server_length  
	server_length = strlen(send_msg);   // assigning the address to the variable server_length

	if ((write_bytes = send(client_socket, send_msg, server_length, 0)) > 0)   // send() message
	{
		printf("\t||---------------------------[CLIENT : %d]--------------------------------||\n", client_socket);
	}
	else
	{
		perror("*****Error : send failed*****");
		return -1;
	}
	return write_bytes;
}
