// Source file containg the function defination


#include "strpointer.h"

// Function defination of reading the item
void read_item(struct Item *val)
{
	// Printing the product details
	printf("----------PRODUCT DETAILS----------\n");
	printf("Enter the product name: \n");
	scanf("%s", val->itemname);
	
	printf("---------------------------\n");
	
	printf("Enter the price: \n");
	scanf("%f", &val->price);
	
	printf("---------------------------\n");
	
	printf("Enter the quantity: \n");
	scanf("%d", &val->quantity);
	
	// Storing the total amount by multiplying quantity and price
	val -> amount = (float)val -> quantity * val -> price;
}


