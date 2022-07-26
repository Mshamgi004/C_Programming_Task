#include "server.h"

// Function defination to handle the client
void handle_connection(struct sockaddr_in client_address, int new_server_sockfd)
{
    char ip[INET_ADDRSTRLEN] = {0};       // char buffer to store the ip address of connected clients
    char client_buffer[MAX_BUFFER_SIZE] = {0};   // char buffer to store the name of connected clients
    char recv_msg[32];   // char buffer to store the reciveing message
	
	recv_from_client(new_server_sockfd, client_buffer);  // Function call to recieve the name from client
    
   
	//get the name, IP and Port client details
    int port = ntohs(client_address.sin_port);
    inet_ntop(AF_INET, &(client_address.sin_addr), ip, INET_ADDRSTRLEN);
    printf("CLIENT NAME = %s\n",client_buffer);
    printf("[CLIENT-INFO] : [port = %d , ip = %s]\n",port, ip);
	
	// To check for the no. of clients connected 
    if(server.total_client >= NO_OF_CLIENTS) 
	{
        perror("----No more space for client to connect to the server----\n");
    }
	else
	{
		printf("YES: client can be connected \n");
	}
	
	//populate the new client data and saving it in client_list
   	strncpy(server.client_list[server.total_client].client_name,client_buffer,strlen(client_buffer));
    server.client_list[server.total_client].port = port;
    strcpy(server.client_list[server.total_client].ip, ip);
    server.client_list[server.total_client].file_des =  new_server_sockfd;
    
    server.total_client++;
    
}
