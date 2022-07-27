#include "client.h"

// Function defination to recv message from server
int client_recv_from_server(int client_socket, char *recv_msg)
{
		int read_bytes = 0;      // Variable use to store the read_bytes 
		
		if((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0)) > 0)   // recv() message from server
		{
			printf("%s\n",recv_msg);
		}	  
		else if(read_bytes == 0)
		{
			printf("*****Client Disconnected*****\n");
			close(client_socket);
		}
		else
		{
			printf("*****ERROR: recv() failes******\n");
		}
		return 0;
}
