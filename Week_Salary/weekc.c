int hours;
double taxes = 0.00;
double grosspay = 0.00;
int netpay = 0.00;



if(hours <= 40)
{
	grosspay = hours * PAYRATE;
}	
else
{
	grosspay = 40 * PAYRATE;
}
// calculate taxes
if (grosspay <= 300)
{
	taxes = grosspay * TAXRATE_300;
}
else if(grosspay > 300 && grosspay <= 450)
{
	taxes = 300 * TAXRATE_300;
	taxes += (grosspay - 300) * TAXRATE_150;
}
else if (grosspay > 450)
{
	taxes = 300 * TAXRATE_300;
       	taxes += 150 * TAXRATE_150;
       	taxes += (grosspay - 450) * TAXRATE_REST;
}

	// calculate the netpay
netpay = grosspay - taxes;
