// Header file 

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
