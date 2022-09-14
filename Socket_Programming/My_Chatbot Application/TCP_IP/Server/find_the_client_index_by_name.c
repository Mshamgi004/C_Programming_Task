#include "server.h"

// Function defination of find index of the client data structure from client name
int find_the_client_index_by_name(char *name) 
{
    int index = 0;   // var  used to store the index val
	
    // Traversing through whole total_list of client so as to get the name 	
    for(int index_val1 = 0; index_val1 < server.total_client; index_val1++) 
    {
	    	// Comparing the strings in the structures so as to store it in char name var 
		if(strcmp(server.client_list[index_val1].client_name,name) == 0) 
		{
			// Storing the recived names in index
            		index = index_val1 ;
        	}
    }
    return index;
}
