// C program to understand the concept of pass by value and reference using pointer

#include "pointer_passbyref1.h"

int main()
{
	int a;
	a = 10;
	Increament(&a);
	printf("The value of a = %d\n",a);
	printf("Address of variable = %d\n", &a);
	
	return 0;
}		

