#include "server.h"

// Function defination to delete the client
void server_delete_client(int socket_fd_delete)
{
	char client_buffer[MAX_NAME_SZE];
	int delete = 0;
	int index = 0;

	// Iterating the total fd's through whole structure total_list
	for (delete = 0; delete < NO_OF_CLIENTS; delete++)
	{
		// Condition for deleting the client by checking teh socket_fd_delete is present on structure
		if (server.client_list[delete].file_des == socket_fd_delete)
		{
			// traversing through all the index values for deleting the client
			for(index = delete; index < NO_OF_CLIENTS; index++)
			{
				//Array indexing shifting when there is client present in the structure
				server.client_list[index] = server.client_list[index + 1];
			}
		}	
	}
	server.total_client--;
	printf("\t------------------Connected client deleted fd : [%d]----------------------------\n",socket_fd_delete);
	close(socket_fd_delete);
}
