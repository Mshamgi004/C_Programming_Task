// Create functions code !!!

#include<stdio.h>
#include<stdlib.h>
#include "header.h"




int main()
	int result = 0;
	float f1 = -15.5;
	float f2 = 6.0;
	float f3 = 5.0;
	int i1 = 718;
	float abvalueresult = 0.0;
	
	// Testing the GCD function
	result = gcd(150,25);
	printf("The GCD = %d\n", result);
	printf("The GCD = %d\n",gcd(150,25));
	
	printf("-----------------------------------------\n");
	
	
	// Testing absolute value function
	abvalueresult = abvalue(f1);
	printf("result = %.2f\n",abvalueresult);
	
	abvalueresult = abvalue(f2) + abvalue(f3);
	printf("result = %.2f\n",abvalueresult);
	
	abvalueresult = abvalue( (float) i1 );
	printf("result = %.2f\n",abvalueresult);
	
	printf("-----------------------------------------\n");
	
	
	// Testing the squareRoot function 
	printf("Square root = %.2f\n", squareRoot(16.0));
	printf("Square root = %.2f\n", squareRoot(81.0));
	printf("Square root = %.2f\n", squareRoot(-49.0));
	
	return 0;
}	

	
	
	
	
	
