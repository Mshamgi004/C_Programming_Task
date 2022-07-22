// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP for sending messages from both sides continuously.
// Server Socket program.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>

#define PORT 8000
#define NO_OF_CLIENTS 10
#define MAX_NAME_SZE 20
#define MAX_BUFFER_SIZE 1024


struct client 
{
  	char cname[MAX_BUFFER_SIZE];
    	int file_des;
    	int client_socket;
    	int port;
    	char ip[INET_ADDRSTRLEN];
    	char client_name[32];
    	char buffer_name[32];
}detail;

struct server_data 
{
    	int total_client;
    	struct client client_list[NO_OF_CLIENTS];
}server;

void client_handle_list(struct client *client_name);

int main()
{
	int server_sockfd, new_server_sockfd;    // Declaring the socket file despcriptor = server_sockfd & new_server_sockfd
	int bind_check;        // Variable to store the bind check
	int accept_check;      // Variable to store the accept check
	int opt_port;          // Variable used for setsockopt()
	char server_responce[1024];         // Creating a buffer = server_responce
	
	socklen_t clilen;      // Defining the socklen_t address
	struct sockaddr_in server_address, client_address;   // Creating a sockaddr structure to hold the address
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Creating a server socket
	if(server_sockfd == -1)                            // Checking for server_socket is created or not 
	{
		printf("Error in creating the socket");
		return -1;
	}
	printf("....Server Socket created succesfully !.... \n");
	
	// Forcefully sets the socket port number
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_port , sizeof(opt_port));
	
	bzero(&server_address, sizeof(server_address));    //bzero clears any data 
	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;    
	server_address.sin_port = htons(PORT);   
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind_check = bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)); // Binding 
	if(bind_check == -1)                  
	{
		printf("Error in binding \n");
	 	return -1;
	}
	printf("Socket binded succefully ! \n");
	
	listen(server_sockfd, 6);          // Listening the incoming connection
	
    	while(1)
	{   	
		//pid_t childpid;
		//childpid = fork();
		
		
	//			printf("Enter into another process");	
			
			clilen = sizeof(client_address);       // Setting the sizeof client length
			bzero(&client_address, sizeof(client_address));
			new_server_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &clilen); // accept
			if(new_server_sockfd == -1)       
			{
				printf("Error in accepting the message");
				return -1;
			}
			printf(".....Server sockfd is ready to accept the incoming messages....\n");
			
			pid_t childpid;
			if((childpid = fork()) == 0)
			{	
				for(;;)                                         
				{
			
			
					char ip[INET_ADDRSTRLEN] = {0};
			    		char buffer_name[MAX_BUFFER_SIZE] = {0};
			    		int read_bytes = 0;
					int read_name = 0;
					char recv_msg[32];
					int client_socket;
					
			   		
			   		bzero(buffer_name,sizeof(buffer_name));  // bzero() 
			   		read_name = recv(client_socket, buffer_name, sizeof(buffer_name), 0);
			   		
			   		int port = ntohs(client_address.sin_port);
			    		inet_ntop(AF_INET, &(client_address.sin_addr), ip, INET_ADDRSTRLEN);
			    		
			    		printf("CLIENT NAME = %s\n",buffer_name);
			    		
			    		printf("[CLIENT-INFO] : [port = %d , ip = %s]\n",port, ip);
			   		if(server.total_client >= NO_OF_CLIENTS) 
			    		{
						perror("ERROR : no more space for client to save");
			    		}
			   		
			   		bzero(recv_msg,sizeof(recv_msg));     // read message
			   		read_bytes = recv(new_server_sockfd, recv_msg, sizeof(recv_msg), 0);
			   		
			   		/*
			   		int port = ntohs(client_address.sin_port);
			    		inet_ntop(AF_INET, &(client_address.sin_addr), ip, INET_ADDRSTRLEN);
			    		
			    		printf("CLIENT NAME = %s\n",buffer_name);
			    		printf("[CLIENT-INFO] : [port = %d , ip = %s]\n",port, ip);
			   		if(server.total_client >= NO_OF_CLIENTS) 
			    		{
						perror("ERROR : no more space for client to save");
			    		}
			    		*/
					//populate the new client data 
			   		strcpy(server.client_list[server.total_client].cname ,buffer_name);
			    		server.client_list[server.total_client].port = port;
			    		strcpy(server.client_list[server.total_client].ip, ip);
			    		server.client_list[server.total_client].file_des = new_server_sockfd;
			    		
			    		server.total_client++;
			
					/*
					int val;
					int write_bytes = 0;
					char client_name[32];
					
					
					
					
					bzero(recv_msg,sizeof(recv_msg));     // bzero() used to erase   		
					
					read_bytes = recv(new_server_sockfd, recv_msg, sizeof(recv_msg), 0);
					
					printf("Client messsage recieved: %s \n");
					gets(recv_msg);       
					
					printf("------------------------------------\n");
			
					bzero(recv_msg, sizeof(recv_msg));     // bzero() used to erase the data stored in buffer 
							
					printf("Enter message to be send to server: %s ");
					gets(recv_msg);
					
					write_bytes = send(new_server_sockfd, recv_msg, strlen(recv_msg), 0); // send() function
					*/
					client_handle_list(&buffer_name);
			}
		}		
	}		
	close(new_server_sockfd);	// Closing the server sockfd
	
	return 0;
}	

void client_handle_list(struct client *buffer_name)
{	
	int val;
	int read_name;
	int new_server_sockfd;
	//read_name = recv(new_server_sockfd, client_name, sizeof(client_name), 0);
	//gets(client_name);
	
	FILE *fptr;
	fptr = fopen("clientlist.txt", "w");
	if(fptr == NULL)
	{
		printf("Error");
		exit(1);
	}
	while(fread(&detail, sizeof(struct client), fptr))
	{
		printf("Name = %s\n IP = %d\n PORT = %d\n", detail.buffer_name, detail.ip, detail.port);
	close(fptr);	
}					 

	
	

