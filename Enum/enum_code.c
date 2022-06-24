// Create an enum type and display the values to that variable //

#include<stdio.h>

int main()
{       

        // Creating an enum named Company
	enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
	
	// Creating variables of Company
	enum Company myCompany1 = XEROX;
	enum Company myCompany2 = GOOGLE;
	enum Company myCompany3 = EBAY;
	
	// Printing the values stored in variables
	printf("%d\n %d\n %d\n",myCompany1,myCompany2,myCompany3);
	
	return 0;
}
