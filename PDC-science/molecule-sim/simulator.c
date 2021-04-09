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
		printf("Initing molecule %d\n",i);
	}
	kevinsmath(4.0,1.0,5.0);
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
	printf("c and d are %f and %f\n",c,d);
	double S = (((eoxy1 - eoxy2)/((fabs(eoxy1 - eoxy2) + c)) + d));
	printf("S is %f\n",S);
	if (er1 == 0.0)
	{
		printf("0\n");
		return 0;
	}
	if (er1 == 1.0)
	{
		double result = ((1.0/etot) * (2.0/(psel(etot,1.0))) * (1.0/3.0) * (S));
		printf("result for er1 = 1 is %f\n",result);
		return result;
	}
	if (er1 == etot)
	{
		printf("%f\n",S/3.0);
		return (S / 3.0);
	}
	else 
	{
		double result = ((er1/etot) * ((2 * (sel(er1,1) * psel(etot - 2, er1 - 1)) + (sel(er1,1) * psel(etot - 3,er1 - 2)) / psel(etot,er1))) * (1.0/3.0) * (S));
		printf("result for er1 = %f is %f\n",er1,result);
		return result;
	}
	return 0;
}
