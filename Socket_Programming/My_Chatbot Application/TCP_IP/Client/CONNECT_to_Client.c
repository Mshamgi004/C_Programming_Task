// Function defination to communicate with all clients
// Working on cmd operatio so as to remove the command line user input and send the message form user input only ....... 

#include "client.h"

// Function defination to communicate with all clients
int CONNECT_to_Client(char* buffer, char* chat_c)
{
	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;
	char send_buffer[MAX_BUFFER_SIZE];

	if (strncmp(buffer, "CONNECT", 7) == 0)     // To connect to another client
	{
		sscanf(buffer, "%*[^:]:%s", chat_c);
		strcpy(server.client_list[index_sender].chatwith, chat_c);

		index_receiver = find_the_client_index_by_name(server.client_list[index_sender].chatwith);
		server.client_list[index_sender].chatwith_fd = server.client_list[index_receiver].file_des;
		//server_send_to_client(server.client_list[index_sender].file_des, CONNECTED);
		client_send_to_server(server.client_list[index_sender].file_des, CONNECTED);

	}

	if (strlen(server.client_list[index_sender].chatwith) != 0)
	{
		snprintf(send_buffer, sizeof(send_buffer), "[%s] : %s", server.client_list[index_sender].client_name, buffer);
		printf("-----------------------\n");
		printf("Buffer = %s\n", send_buffer);

		//server_send_to_client(server.client_list[index_sender].chatwith_fd, send_buffer);
		client_send_to_server(server.client_list[index_sender].chatwith_fd, send_buffer);
	}
	return 0;
}
