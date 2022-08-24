#include "client.h"

//  To list all client details
int LIST_clients(char* buffer, char* send_buffer)
{
	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;
	//char buffer[MAX_BUFFER_SIZE];
	int socket;

	index_sender = find_the_client_index_list(socket);
	if (strncmp(buffer, "LIST", 4) == 0) // Providing the list to client by server using cmd 
	{
        // Setting the buffer initially
		memset(buffer, 0, sizeof(send_buffer));
        
        // Creating a loop to iterate over a sending messageG
		for (int val_send = 0; val_send < server.total_client; val_send++)
		{
            // Concaneting the buffer value to client name's 
            printf("List of clients connected\n");
			strcat(buffer, server.client_list[val_send].client_name);
			strcat(buffer, "\n");
		}
		//server_send_to_client(socket, buffer);   // sending it to client
		client_send_to_server(socket, buffer);
	}
	return 0;
}
