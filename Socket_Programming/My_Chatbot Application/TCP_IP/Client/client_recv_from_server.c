#include "client.h"

void client_recv_from_server(int client_socket, char *recv_msg)
{
		int read_bytes = 0;
		//char recv_msg[32];
		
		bzero(recv_msg, sizeof(recv_msg));     // bzero() used to erase the data stored in buffer 
					
		if((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0)) > 0)
		{
			printf("%s\n",recv_msg);
		}	  
		else if(read_bytes == 0)
		{
			printf("Client Disconnected\n");
			close(client_socket);
		}
		else
		{
			printf("ERROR: recv failes\n");	
		}	
								
}
