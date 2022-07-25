#include "server.h"

void handle_connection(struct sockaddr_in client_address, int new_server_sockfd)
{
    char ip[INET_ADDRSTRLEN] = {0};
    char client_buffer[MAX_BUFFER_SIZE] = {0};
    char recv_msg[32];
	
	//get extra server details
	recv_from_client(new_server_sockfd, client_buffer);
    
   
	//get the IP and Port client details
    int port = ntohs(client_address.sin_port);
    inet_ntop(AF_INET, &(client_address.sin_addr), ip, INET_ADDRSTRLEN);
    printf("[CLIENT-INFO] : [port = %d , ip = %s]\n",port, ip);
   
    if(server.total_client >= NO_OF_CLIENTS) 
	{
        perror("----No more space for client to connect to the server----\n");
    }
	
	//populate the new client data 
   	strncpy(server.client_list[server.total_client].client_name,client_buffer,strlen(client_buffer));
    server.client_list[server.total_client].port = port;
    strcpy(server.client_list[server.total_client].ip, ip);
    server.client_list[server.total_client].file_des =  new_server_sockfd;
    
    server.total_client++;
    
}
		
			
