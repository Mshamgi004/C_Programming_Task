
// Updated the version of function 
#include "client.h"

// Fucntion defination in CLient side for a user friendly application
int Client_decision(int client_sockfd, char* send_buffer)
{
	int choice;
	int option;
	char recv_msg[MAX_BUFFER_SIZE];
	char buffer[MAX_BUFFER_SIZE];
	char chat_c[MAX_BUFFER_SIZE];
	int client_socket;
	int socket_fd_delete;
	
	printf("---------------------------------------------------------------------------------\n");
	printf("Press 1 to know the other client details\n");
	printf("Press 2 to chat with a client\n");
	printf("Press 3 to exit\n");
	printf("Enter your choice:\n");
	printf("---------------------------------------------------------------------------------\n");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		{
			printf("LIST all client details\n");
			LIST_clients(buffer, send_buffer);
			break;
		}
		case 2:
		{
			printf("Enter name of client to chat with:\n");
			CONNECT_to_Client(buffer, chat_c);
			break;
		}
		case 3:
		{
			printf("Exit the application\n");
			server_delete_client(socket_fd_delete);
			break;
		}
		// default:
		// printf("wrong Input\n");
	}
		return 0;
}