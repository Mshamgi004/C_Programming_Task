int Client_decision(int client_sockfd, char* send_buffer)
{
	char choice;
	int select = 1;
	char input[MAX_BUFFER_SIZE];
	int option;
	int input_status;
	char recv_msg[MAX_BUFFER_SIZE];
	char buffer[MAX_BUFFER_SIZE];
	char chat_c[MAX_BUFFER_SIZE];
	int client_socket;
	int socket_fd_delete;
	
	// ---------------------------------WORKING ------------------------------------------------//
	// Trying to build the exact operation for menu driven function in client side
	while(select == 1)
	{
		printf("---------------------------------------------------------------------------------\n");
		printf("Press 1 to know the other client details\n");
		printf("Press 2 to chat with a client\n");
		printf("Press 3 to exit\n");
		printf("---------------------------------------------------------------------------------\n");
		printf("Enter your choice:");
		scanf("%s",input);
	
		input_status = input;         // Checking for the condition to be true for input status
		if(input_status == 1)
		{
			continue;
        }
		else      // if input is a digit
        {
            option = input_status;
			if(option == 0)
			{
				return -1;
			}
		}
		switch (option)
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
			default:
				printf("Invalid Option\n Try Again\n");
				break;
		}
	}	
	return 0;
}
