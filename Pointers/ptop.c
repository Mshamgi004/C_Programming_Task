// Pointer toi pointer case in C programming

#include<stdio.h>

int main()
{
	    int val1 = 5;
	    int *val2;
	    val2 = &val1;

	    *val2 = 6;

	    int **val3;
	    val3 = &val2;

	    int ***val4;
	    val4 = &val3;

	    printf("The value of val1 = %d\n", *val2);
	    printf("The value of val1 = %d\n", *val3);
	    printf("The value of val1 = %d\n", *(*val3));
	    printf("The value of val1 = %d\n", *(*(*val4)));

	    return 0;


    
}
