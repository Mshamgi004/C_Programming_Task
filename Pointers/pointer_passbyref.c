// C program to understand the concept of pass by value and reference using pointer

#include "pointer_passbyref1.h"

void Increament(int *a)
{	
	// a = a + 1;
	*a = (*a) + 1;
	printf("Address of variable = %d\n", &a);
}



