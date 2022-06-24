// C program to understand the concept of pointers with array 

#include<stdio.h>
#include<string.h>

int main()
{	
	char multiple[] = "a string";
	char *ptr = multiple;
	
	for(int val = 0; val < strnlen(multiple,sizeof(multiple)); val++)

	printf("multiple[%d] = %c *(ptr + %d) = %c &multiple[%d] = %p ptr + %d = %p\n", val, multiple[val], val, *(ptr + val), val, &multiple[val], val, ptr+val);
	
	return 0;
}	
		
	
