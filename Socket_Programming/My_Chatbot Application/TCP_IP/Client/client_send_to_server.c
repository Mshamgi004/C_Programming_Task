#include "client.h"

// Function defination of sending message to the server
int client_send_to_server(int client_socket, char *send_msg) 
{
	int write_bytes = 0;   // Variable used for writing the message
	int len = strlen(send_msg);    // Declaring a socklen_t variable -> serlen

	printf("Tell your name:%s\n", client_name);
	//scanf("%s\n", client_name);

	if((write_bytes = send(client_socket, send_msg, len, 0) <= 0))   // Storing the send buffer in serlen
	{
		printf("send() failed");
		return -1;
	}
	else
	{
		Client_decision(client_sockfd, send_buffer);
	}
	return write_bytes;
}
