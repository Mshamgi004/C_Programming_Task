#include "server.h"

// Function defination to delete the client
void server_delete_client(int socket_fd_delete)
{
	char client_buffer[MAX_NAME_SZE];
	int delete = 0;
	int index = 0;

	// Iterating the variable till tital no. of clients
	for (delete = 0; delete < NO_OF_CLIENTS; delete++)
	{
		// Condition for deleting the client
		if (server.client_list[delete].file_des == socket_fd_delete)
		{
			server.total_client--;
			printf("\t------------------Connected client deleted fd : [%d]----------------------------\n",socket_fd_delete);
			//printf("\t------------------Name of Connected client deletd : [%s]------------------------\n",client_buffer);
		}
	}

	close(socket_fd_delete);
}
