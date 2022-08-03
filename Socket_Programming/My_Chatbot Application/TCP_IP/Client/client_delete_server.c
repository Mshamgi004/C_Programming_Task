#include "client.h"

// Function defination to delete the client
void server_delete_client(int socket_fd_delete) 
{
    int delete = 0;
    int index = 0;

	// Iterating the variable till tital no. of clients
    for(delete = 0; delete < NO_OF_CLIENTS; delete++) 
	{
		// Condition for deleting the client
        if(server.client_list[delete].file_des == socket_fd_delete) 
		{
			printf("-------Socket deleted = [%d]\n",socket_fd_delete);
        }
    }
    close(socket_fd_delete);
}
