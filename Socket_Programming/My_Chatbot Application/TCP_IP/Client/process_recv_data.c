#include "client.h"

//processing the received data from clients
int process_recv_data(int socket, char* buffer)
{
	// Creating the chatting and sending buffer to store the message 
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE] = { 0 };

	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	

	//index_sender = find_the_client_index_list(socket); // Storing the index values of client in index_sender

	LIST_clients(buffer,send_buffer);    // Function call to list the clients
	
	CONNECT_to_Client(buffer, chat_c);    // Function call to connect to client
	
	return 0;
}
