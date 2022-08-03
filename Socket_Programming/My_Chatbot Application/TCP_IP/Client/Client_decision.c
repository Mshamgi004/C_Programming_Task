//***************This is the promte messag to be shown on client side so as to perform different operation*******************/
//----------------------------------------------------WORKING--------------------------------------------------//


#include "client.h"

int Client_decision(int client_sockfd, char *send_buffer)
{
	int choice;
	int option;
	int client_sockfd;
	char recv_msg[MAX_BUFFER_SIZE];

	printf("Press 1 to know the other client details\n");
    printf("Press 2 to chat with a client\n");
    printf("Press 3 to exit\n");
    printf("Enter your choice:\n");
    choice = process_recv_data(socket, buffer);  
      
    switch (choice) 
	{
    	case 1: 
		{
        	printf("LIST all client details\n");
			choice = LIST_clients(buffer,send_buffer);
        	break;
    	}
    	case 2: 
		{
			printf("Enter name of client to chat with:\n");
			choice = CONNECT_to_Client(buffer, chat_c);
			break;
    	}
    	case 3:
		{
			printf("Exit the application\n");
        	break;
		}
    	default:
        	printf("wrong Input\n");
    }
	return 0;
}
