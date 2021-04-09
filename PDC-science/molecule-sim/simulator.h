#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double fact(double number, int ident)
{
	if (number < 0.0)
	{
		printf("Oops! You tried to factorial a negative number! Ident is %d\n",ident);
		exit(-1);
	}
	if (number == 0.0)
	{
		return 1.0;
	}
	printf("factorialing %f\n",number);
	return(number * fact(number - 1,ident));
}
double psel(double n, double k)
{
	printf("in select function");
	return((fact(n,-1)) / (fact(n - k,-1)));
}
double sel(double n, double k)
{
	return((fact(n,-2)) / ((fact(k,-2)) - (fact(n - k,-2))));
}
