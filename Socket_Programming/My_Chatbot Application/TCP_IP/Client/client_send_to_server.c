#include "client.h"

// Function defination of sending message to the server
int client_send_to_server(int client_socket, char *send_msg)
{	
	int write_bytes = 0;      // Variable used for writing the message
	int clilen;         // Declaring a socklen_t variable -> serlen
	clilen = strlen(send_msg);     // Storing the send buffer in serlen
		
	if((write_bytes = send(client_socket, send_msg, serlen,0)) < 0)  // send() message to server 
	{				
		printf("****Error: send() failed****\n");
		exit(1);
	}
	else
	{
		printf("Messgae to server send sucessfully\n");
	}
	return write_bytes;						
}	
