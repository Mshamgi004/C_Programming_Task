#include "server.h"

//processing the received data from clients
int process_recv_data(int socket, char* buffer)
{
	// Creating the chatting and sending buffer to store the message 
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE] = { 0 };

	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier

	index_sender = find_the_client_index_list(socket); // Storing the index values of client in index_sender

	// Providing the list to client by server using cmd 
	if (strncmp(buffer, "LIST", 4) == 0)
	{
		// Setting the buffer initially
		memset(buffer, 0, sizeof(send_buffer));

		// Creating a loop to iterate over a sending message
		for (int val_send = 0; val_send < server.total_client; val_send++)
		{
			// Concaneting the buffer value to client name's 
			strcat(buffer, server.client_list[val_send].client_name);
			strcat(buffer, "\n");
		}
		server_send_to_client(socket, buffer);   // sending it to client
		goto out;
	}

	// To connect to another client
	if (strncmp(buffer, "CONNECT", 7) == 0)    
	{
        printf("\tI want to talk :%s\n", buffer);
		
		sscanf(buffer, "\t%*[^:]:%s", chat_c);
		strcpy(server.client_list[index_sender].chatwith, chat_c);

		index_receiver = find_the_client_index_by_name(server.client_list[index_sender].chatwith);
		server.client_list[index_sender].chatwith_fd = server.client_list[index_receiver].file_des;
		
		server_send_to_client(server.client_list[index_sender].file_des, CONNECTED);
		goto out;
	}

	// To showcase the message to the connected client from the server
	if (strlen(server.client_list[index_sender].chatwith) != 0)
	{
		snprintf(send_buffer, sizeof(send_buffer), "\t[%s] : %s\n", server.client_list[index_sender].client_name, buffer);
		printf("\tMessage from Client: %s\n", send_buffer);
		
		server_send_to_client(server.client_list[index_sender].chatwith_fd, send_buffer);
	}

out:
	
	return 0;
}
