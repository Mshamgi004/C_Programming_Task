#include "server.h"


void send_to_client(int client_socket, char *send_msg)
{
				
	int write_bytes = 0;
	bzero(send_msg, sizeof(send_msg));     // bzero() used to erase the data stored in buffer 
						
	printf("Enter message to be send to server: %s ",send_msg);
	// gets(send_msg);
				
	write_bytes = send(server_sockfd, send_msg, strlen(send_msg), 0); 
	printf("\n[CLIENT : %d] || Wrote [%d] number of bytes || BYTES = [%s]\n",server_sockfd,write_bytes, send_msg);
}	
