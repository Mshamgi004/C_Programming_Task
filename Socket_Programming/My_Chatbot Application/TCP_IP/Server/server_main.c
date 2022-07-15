#include "server.h"

int main(int argc, int argv[])
{	
	int server_sockfd = setup_server(PORT,BACKLOG);
	
	while(1)
	{	
		
		int client_sockfd = accept_new_connection(server_sockfd);
		//printf("REached accept");
				
		handle_connection(client_sockfd);
		//printf("Reached handle connection");
	
		printf("......Waiting for connection!!!......\n");
	}
	return 0;
}
