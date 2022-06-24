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

