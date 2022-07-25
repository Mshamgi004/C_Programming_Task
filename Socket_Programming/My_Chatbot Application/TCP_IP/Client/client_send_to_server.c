#include "client.h"

void client_send_to_server(int client_socket, char *send_msg)
{	
	int write_bytes = 0;
	socklen_t servlen;
	servlen = strlen(send_msg);
		
	if((write_bytes = send(client_socket, send_msg, servlen,0)) <= 0)
	{				
		printf("Error: Send failed\n");
		exit(1);
	}
	else
	{
		printf("Messgae to server send sucessfully\n");
	}						
}	
