#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "simulator.h"
#define MAXELEC 5
#define SRTELEC 2
#define MOLNUMB 10
long double kevinsmath();
int main()
{
	long double molecules[MOLNUMB];
	long double etot = MAXELEC;
	for (int i = 0; i <= MOLNUMB; i++)
	{
		molecules[i] = SRTELEC;
	}
	for (long double i = 0.f; i <=  ( long double ) MAXELEC; i++)
	{
		for (long double j = 0.f; j <= ( long double ) MAXELEC; j++)
		{
			printf("i is %Lf, j is %Lf ",i,j);
			kevinsmath(i,j, (long double) MAXELEC);
		}
	}
	printf("double is %lld, long double is %lld\n",sizeof(double),sizeof(long double));
}
long double kevinsmath(long double er1,long double er2,long double etot)
{
	long double eoxy1 = er1 - 2.0;
	long double eoxy2 = er2 - 2.0;
	long double d,c;
	if (eoxy1 - eoxy2 == 0.0)
	{
		d = 1.0;
	}
	else
	{
		d = 0.0;
	}
	if (fabsl(eoxy1 * eoxy2) == 0)
	{
		c = 1.0;
	}
	else
	{
		c = 0.0;
	}
	long double S = ( ( ( eoxy1 - eoxy2 ) / ( fabsl( eoxy1 * eoxy2 ) + c ) ) + d );
	printf("S is %Lf ",S);
	if (er1 == 0.0)
	{
		printf("result is 0\n");
		return 0;
	}
	if (er1 == 1.0)
	{
		printf("psel 5,1 is %Lf",psel(etot,1,0));
		long double result = ((1.0/etot) * (2.0/(psel(etot,1,1))) * (1.0/3.0) * (S));
		printf("result is %Lf\n",result);
		return result;
	}
	if (er1 == etot)
	{
		printf("result is %d\n",1);
		return (1);
	}
	else 
	{
		long double result = ((er1/etot) * ((((2 * (sel(er1,1,2) * psel(etot - 2, er1 - 1,3)) + (sel(er1,1,4) * psel(etot - 3,er1 - 2,5)))) / psel(etot,er1,6))) * (1.0/3.0) * (S));
		printf("result is %Lf\n",result);
		return result;
	}
	return 0;
}
