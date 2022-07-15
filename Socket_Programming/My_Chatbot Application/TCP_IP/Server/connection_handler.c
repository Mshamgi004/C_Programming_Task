#include "server.h"

void *handle_connection(int client_sockfd)
{	
	int port;
	int server_sockfd;
	struct sockaddr_in client_address;
	char server_name[LENGTH_NAME];
	char recv_buffer[LENGTH_NAME];
	char send_buffer[LENGTH_NAME];
	char server_responce[1024];

	// Naming of the client
	if(recv(server_sockfd, recv_buffer, LENGTH_NAME,0) == -1)
	{
		printf("No input name given");
	}
	else
	{
		strcpy(server_name,LENGTH_NAME);
		printf("%s %d joined in the chat room", server_name, port);
	}
	while(1)
	{
		bzero(server_responce, 1024);           // Creating a buffer = server_responce
		recv(client_sockfd,recv_buffer,sizeof(recv_buffer),0);  // Reading client message
				
		if(strcmp(server_responce, "Bye\n") == 0)         // strcmp() used to compare the string "Bye"
		{
			printf("---SERVER Disconnected from %s:%d\n:", inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));
			break;
		}
		else
		{
			printf("Message from Client: %s\n", recv_buffer); // Printing the message received from client and sending it to server
			//printf("Message from Client1: %s\n", server_responce);
			send(client_sockfd, send_buffer, strlen(send_buffer), 0); // Writing to the client to sent the message		
			bzero(send_buffer, sizeof(send_buffer));           // Creating a buffer = server_responce
		}
		return server_sockfd;
	}
}	
