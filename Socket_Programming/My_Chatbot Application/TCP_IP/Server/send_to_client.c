#include "server.h"

// Function defination to send the message to client
int send_to_client(int client_socket, char *send_msg)
{
	int write_bytes = 0;   // Variable used for writing the message
	//bzero(send_msg, sizeof(send_msg));     // bzero() used to erase the data stored in buffer 
	socklen_t servlen;
	servlen = strlen(send_msg);					
	//printf("Enter message to be send to server: %s ",send_msg);
				
	if((write_bytes = send(client_socket, send_msg, servlen, 0)) > 0) // send() message
	{
		printf("\n[CLIENT : %d] || BYTES = [%s]\n",server_sockfd,send_msg);
	}
	else
	{
		printf("Error : send failed");
		return -1;
	}
	return write_bytes;

}
