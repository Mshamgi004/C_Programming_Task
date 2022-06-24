// C program to understand the concept of constant pointers

#include<stdio.h>

int main()
{
	// pval is a viariable being declared as const ptr pointing to an integer. It means pointer shoudn't point to any other integer.
	int count = 44;
	const int *pcount;
	pcount = &count;
	
	*pcount = 45;
	
	printf("The value of pcount = %d\n", &pcount);
	

/*	
	// pval is a pointer to int const (int const *). It means pval pointer is pointing to an integer value whose value can't be changed
	const int val = 34;
	int const *pval;
	//int val2 = 35;
	
	//pval = &val;
	
	*pval = 35;
	
	printf("The address of pval = %d\n", pval);
	printf("The value of pval = %d\n", *pval);
*/	
	return 0;
}	
