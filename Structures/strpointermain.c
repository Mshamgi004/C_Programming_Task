// C program to create a structure pointer and pass it to a function
// Task: To create a user input billing card

#include<stdio.h>
#include<stdlib.h>

// Declaring the structure Item
struct Item
{
	char *itemname;
	int quantity;
	float price;
	float amount;
};

// Function prototypes of reading and printing the sum for billing
void read_item(struct Item *val);
void print_sum(struct Item *val);


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
	

