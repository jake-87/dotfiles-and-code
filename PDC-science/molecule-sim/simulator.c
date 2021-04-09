#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "simulator.h"
#define MAXELEC 5
#define SRTELEC 2
#define MOLNUMB 10
double kevinsmath();
int main()
{
	double molecules[MOLNUMB];
	double etot = MAXELEC;
	for (int i = 0; i <= MOLNUMB; i++)
	{
		molecules[i] = SRTELEC;
	}
	for (double i = 0.f; i <=  ( double ) MAXELEC; i++)
	{
		for (double j = 0.f; j <= ( double ) MAXELEC; j++)
		{
			printf("i is %.15f, j is %.15f ",i,j);
			kevinsmath(i,j,MAXELEC);
		}
	}
}
double kevinsmath(double er1,double er2,double etot)
{
	double eoxy1 = er1 - 2.0;
	double eoxy2 = er2 - 2.0;
	double d,c;
	if (eoxy1 - eoxy2 == 0.0)
	{
		d = 1.0;
	}
	else
	{
		d = 0.0;
	}
	if (fabs(eoxy1 * eoxy2) == 0)
	{
		c = 1.0;
	}
	else
	{
		c = 0.0;
	}
	double S = ( ( ( eoxy1 - eoxy2 ) / ( fabs( eoxy1 * eoxy2 ) + c ) ) + d );
	printf("S is %.15f ",S);
	if (er1 == 0.0)
	{
		printf("result is 0\n");
		return 0;
	}
	if (er1 == 1.0)
	{
		double result = ((1.0/etot) * (2.0/(psel(etot,1,1))) * (1.0/3.0) * (S));
		printf("result is %.15f\n",result);
		return result;
	}
	if (er1 == etot)
	{
		printf("result is %.15f\n",1.0);
		return (1);
	}
	else 
	{
		double result = ((er1/etot) * ((((2 * (sel(er1,1,2) * psel(etot - 2, er1 - 1,3)) + (sel(er1,1,4) * psel(etot - 3,er1 - 2,5)))) / psel(etot,er1,6))) * (1.0/3.0) * (S));
		printf("result is %.15f\n",result);
		return result;
	}
	return 0;
}
