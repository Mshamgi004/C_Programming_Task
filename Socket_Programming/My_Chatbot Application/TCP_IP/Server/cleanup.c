#include "server.h"

void cleanup() 
{
    close(server_sockfd);
    for(int clean = 0; clean < server.total_client; clean++) 
    {
        close(server.client_list[clean].file_des);
    }
}
