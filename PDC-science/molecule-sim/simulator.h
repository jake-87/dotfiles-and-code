#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long double fact(long double number, int ident) // this computes factorials of long doubles, dispite the fact that it cant actually understand anything other than a whole number, it gets given long doubles and it has to return long doubles so it has to suffer
{
	if (number < 0.0)
	{
		printf("Oops! You tried to factorial a negative number! Ident is %d\n",ident);
		printf("Number was %Lf\n",number);
		exit(-1); // negative case
	}
	if (number == 0.0)
	{
		return 1.0; // normal useage case
	}
	double a = (number * fact(number - 1,ident)); //recursion which im sure is very bad practice but it works so who cares? not me
	return a;
}
long double psel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / (fact(n - k,ident))); // combanatorics, i dont understand it any more than you do, so read here if you want to: https://en.wikipedia.org/wiki/Combinatorics , to the best of my ability it just does a bunch of probablility math using factorials and stuff
}
long double sel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / ((fact(k,ident)) * (fact(n - k,ident)))); // see above, but this one is slightly different
}
