#include "server.h"

// Function defination of find index of the client data structure from client socket
int find_the_client_index_list(int socket) 
{
	int index = 0;   // variable used to store the index

	// Traversing through whole total_list of client so as to get the fd	
	for(int index_val = 0; index_val < server.total_client; index_val++) 
	{
		// checking for server socket fd to be equal to socket
		if(server.client_list[index_val].file_des == socket) 
		{
			// Storing the values of index_val at index
			index = index_val;
        	}
    }
    return index;
}
