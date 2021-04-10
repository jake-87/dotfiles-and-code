#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
long double comparedouble(long double a, long double b)
{
	if (fabsl(a - b) < 0.00000001)
	{
		return 1.f;
	}
	else
	{
		return 0.f;
	}
}
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
} // evil bitwise hack
long double fact(long double dubnumber, int ident) // this computes factorials of long doubles, dispite the fact that it cant actually understand anything other than a whole number, it gets given long doubles and it has to return long doubles so it has to suffer
{
	int number = dubnumber;
	if (number < 0)
	{
		printf("Oops! You tried to factorial a negative number! Ident is %d\n",ident);
		printf("Number was %d\n",number);
		exit(-1); // negative case
	}
	if (number == 0)
	{
		return 1.0; // normal useage case
	}
	double a = (number * fact(number - 1,ident)); //recursion which im sure is very bad practice but it works so who cares? not me
	return (long double) a;
}
long double psel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / (fact(n - k,ident))); // combanatorics, i dont understand it any more than you do, so read here if you want to: https://en.wikipedia.org/wiki/Combinatorics , to the best of my ability it just does a bunch of probablility math using factorials and stuff
}
long double sel(long double n,long double k,int ident)
{
	return((fact(n,ident)) / ((fact(k,ident)) * (fact(n - k,ident)))); // see above, but this one is slightly different
}
long double doublerand()
{
	long double random = ((long double)rand()/RAND_MAX);
	return random;
}
long double negdoublerand()
{
	long double random = ((long double)rand()/RAND_MAX);
	return random * -1.0;
}
