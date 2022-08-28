#include "client.h"


int Client_decision()//(int client_sockfd, char* send_buffer)
{
	int choice;
	//char recv_msg[MAX_BUFFER_SIZE];
	//char buffer[MAX_BUFFER_SIZE];
	//char chat_c[MAX_BUFFER_SIZE];
	//int client_socket;
	//int socket_fd_delete;
	
	printf("\t||----You have entered the application. Now choose what you have to do----||\n");
	printf("\t||    Note: Please select a number between 1 to 3.                        ||\n");
	printf("\t||************************************************************************||\n");
	printf("\n\
	1. 	Press 1 to know the other client details\n\
	2. 	Press 2 to chat with a client\n\
	3.	Press 3 to exit\n");
	printf("\nEnter your choice:\n");
	printf("\n______________\n");
	scanf("\n%d", &choice);

	switch (choice)
	{
		case 1:
		{
			printf("LIST all client details\n");
			//LIST_clients(buffer, send_buffer);
			break;
		}
		case 2:
		{
			printf("Enter name of client to chat with:\n");
			//CONNECT_to_Client(buffer, chat_c);
			break;
		}
		case 3:
		{
			printf("Exit the application\n");
			//server_delete_client(socket_fd_delete);
			break;
		}
		// default:
		//  	printf("wrong Input\n");
		// 	break;
	}
	getchar();
		return 0;
}
