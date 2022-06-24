// Pointers containing inside the structure program

#include<stdio.h>

struct intPtr
{
	int *ptr1;
	int *ptr2;
};

int main()
{
	struct intPtr pointers;
	int val1 = 10;
	int val2;
	
	pointers.ptr1 = &val1;
	pointers.ptr2 = &val2;
	*pointers.ptr2 = -97;
	
	printf("val1 = %d, *pointers.ptr1 = %d\n", val1, *pointers.ptr1);
	printf("val2 = %d, *pointers.ptr2 = %d\n", val2, *pointers.ptr2);
	
	return 0;
}		
