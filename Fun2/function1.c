// Create functions code !!!

#include<stdio.h>
#include<stdlib.h>


// Function declaration
int gcd(int x, int y);
float abvalue(float x);
float squareRoot(float x);

// Function defination for calculating the GCD..........
int gcd(int x, int y)
{
	int temp;
	
	while(y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}	

// Function defination for calculating the floating numbers........
float abvalue(float u)
{
	if(u < 0)
	{
		u = -u;
	}
	return u;
}	

// Function defination for calculating the square root......
float squareRoot(float v)
{
	const float epsilon = .0001;
	float guess = 1.0;
	float returnValue = 0.0;
	
	if(v < 0)
	{
		printf("Negative argument to squareRoot.\n");
		returnValue -1.0;
	}
	else
	{
	
		while(abvalue(guess * guess - v) >= epsilon)
		{
			guess = ( v/guess + guess ) / 2.0;
		
			returnValue = guess;
		}
		return returnValue;					
	}
}	

int main()
{
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

	
	
	
	
	
