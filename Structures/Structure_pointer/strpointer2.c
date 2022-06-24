// Source file containg the function defination


#include "strpointer.h"


// Function defination of printing the sum
void print_sum(struct Item *val)
{
	
	// Printing the Billing card
	printf("---------BILLING CARD--------\n");
	
	printf("Name: %s\n", val -> itemname);
	
	printf("-----------------------------\n");
	
	printf("Price: %.2f\n", val -> price);
	
	printf("-----------------------------\n");
	
	printf("Quantity: %d\n", val -> quantity);
	
	printf("-----------------------------\n");
	
	printf("Total amount: %.2f\n",val -> amount);
	
	printf("---------THANK YOU----------\n");
}	
