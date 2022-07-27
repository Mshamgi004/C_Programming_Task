#include "server.h"

// Function defination to handle the client
void handle_connection(struct sockaddr_in client_information, int new_server_sockfd) 
{
	char ip[INET_ADDRSTRLEN] = {0};  // char buffer to store the ip address of connected clients
	char client_buffer[MAX_BUFFER_SIZE] = {0};   // char buffer to store the name of connected clients

    server_recv_from_client(new_server_sockfd,client_buffer);  // Function call to recieve the name from client
   
	//get the name IP address and port no: client 
    int port = ntohs(client_information.sin_port);
    inet_ntop(AF_INET, &(client_information.sin_addr), ip, INET_ADDRSTRLEN);
	printf("---------------------------------\n");
    printf("\n[CLIENT NAME] : %s\n", client_buffer);
	printf("---------------------------------\n");
    printf("\n[CLIENT-INFO] : [port] = %d , [IP Address] = %s\n", port, ip);
	printf("---------------------------------\n");
   	
   	// To check for the no. of clients connected 
    if(server.total_client >= NO_OF_CLIENTS) 
    {
        printf("****ERROR : No more space for client to save****\n");
    }
	
	//populate the new client data and saving it in client_list
    strncpy(server.client_list[server.total_client].client_name ,client_buffer,strlen(client_buffer));
    server.client_list[server.total_client].port = port;
    strcpy(server.client_list[server.total_client].ip, ip);
    server.client_list[server.total_client].file_des = new_server_sockfd;
    
    server.total_client++;
}
