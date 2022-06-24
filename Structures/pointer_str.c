// C program to use pointer in structure

#include<stdio.h>

struct value
{
	int val1;
	int val2;
	int val3;
};

int main()
{
	struct value result;
	struct value *valres;
	
	valres = &result;
	
	valres->val1 = 1;
	valres->val2 = 2;
	valres->val3 = 3;
	
	printf("Value result = %d %d %d \n", valres->val1, valres->val2, valres->val3);
	
	return 0;
}	  	
