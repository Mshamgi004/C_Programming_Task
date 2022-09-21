#include "server.h"

// Function defination for deleting the client details
int delete_client_details(int socket_fd_delete)
{   
    FILE *fptr1;
	
	  fptr1 = fopen("CLIENT_INFO.txt", "a+");             // Opening the file for appending the data
	  if(fptr1 == NULL)
	  {
		    fprintf(stderr, "Error in opening the file for appending\n");
		    exit(1);
	  }
	
	  fprintf(fptr1, "||--The client with file descriptor %d hs been deleted from the list--||\n", socket_fd_delete);         // Printing the status of client deletion
    
    fclose(fptr1);         // Closing the fptr
     
    return 0;
}
