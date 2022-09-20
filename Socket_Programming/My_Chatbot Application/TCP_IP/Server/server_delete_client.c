//*************************************************************WORKING ON THIS*********************************************//

#include "server.h"

// Function defination to delete the client
void server_delete_client(int socket_fd_delete)
{
	char client_buffer[MAX_NAME_SZE];
	int delete = 0;
	int index = 0;

	// char str[1000];
	// int counter = 0;
	// int line_no = 0;

	

	// Iterating the total fd's through whole structure total_list
	for (delete = 0; delete < NO_OF_CLIENTS; delete++)
	{
		// Condition for deleting the client by checking teh socket_fd_delete is present on structure
		if (server.client_list[delete].file_des == socket_fd_delete)
		{
			// traversing through all the index values for deleting the client
			for(index = delete; index < NO_OF_CLIENTS; index++)
			{
				//Array indexing shifting when there is client present in the structure
				server.client_list[index] = server.client_list[index + 1];
			}
		}	
	}
	server.total_client--;
	printf("\t||------------------Connected client deleted fd : [%d]--------------------||\n",socket_fd_delete);
	close(socket_fd_delete);

	// while (!feof(fptr)) 
    // {
    //     strcpy(str, "\0");
    //     fgets(str, MAX, fptr);
    //     if (!feof(fptr)) 
    //     {
    //     	counter++;
    //         /* skip the line at given line number */
    //         if (counter != line_no) 
    //         {
    //             fprintf(fptr1, "%s", str);
    //         }
    //     }
    // }
    // fclose(fptr);
    // fclose(fptr1);
    // remove("CLIENT_INFO.txt");  		// remove the original file 
    // rename("CLIENT_temp.txt", "CLIENT_INFO.txt");

	// fptr = fopen("CLIENT_INFO.txt","r"); 
    // char ch = fgetc(fptr); 
    // //printf(" Now the content of the file %s is : \n",); 
    // while(ch != EOF) 
    // { 
    //     printf("%c",ch); 
    //     ch = fgetc(fptr); 
    // }
    // fclose(fptr);
	/*------- End of reading ---------------*/
		


}
