#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long double fact(long double number, int ident)
{
	if (number < 0.0)
	{
		printf("Oops! You tried to factorial a negative number! Ident is %d\n",ident);
		printf("Number was %Lf\n",number);
		exit(-1);
	}
	if (number == 0.0)
	{
		return 1.0;
	}
	double a = (number * fact(number - 1,ident));
	return a;
}
long double psel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / (fact(n - k,ident)));
}
long double sel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / ((fact(k,ident)) * (fact(n - k,ident))));
}
