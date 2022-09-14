#include "server.h"

// Function defination for cleanup()
void cleanup() 
{   
    int server_sockfd;  // variable used for storing the socket fd

    close(server_sockfd);  // Closing teh socket fd
    
    // Traversing through the list of client's connected stored in the total_list of structures
    for(int clean = 0; clean < server.total_client; clean++)  
    {
        close(server.client_list[clean].file_des);  // Clears the list of conneted clients
    }
}
