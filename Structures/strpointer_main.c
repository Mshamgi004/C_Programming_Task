// C program to create a structure pointer and pass it to a function
// Task: To create a user input billing card

#include "strpointer.h"

int main()
{
	// Creating the object name as instance for structure	
	struct Item info;
	struct Item *pinfo;
	
	// Storing the value of info in pointer pinfo
	pinfo = &info;
	
	// Dynamic memory allocation using malloc() for pinfo pointer
	pinfo -> itemname = (char *)malloc(30 * sizeof(char));
	
	// Checking the working of poinfo
	if(pinfo == NULL)
	{
		exit(-1);
	}
	
	// Calling read_item function 
	read_item(pinfo);
	
	// Calling the print_info function
	print_sum(pinfo);
	
	// Freeing the memory allocated 
	free(pinfo -> itemname);
		
	return 0;
}	


