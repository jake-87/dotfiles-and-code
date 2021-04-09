#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "simulator.h"
#define MAXELEC 5
#define SRTELEC 2
#define MOLNUMB 10
int main()
{
	double molecules[MOLNUMB];
	double etot = MAXELEC;
	for (int i = 0; i <= MOLNUMB; i++)
	{
		molecules[i] = SRTELEC;
		printf("Initing molecule %d\n",i);
	}
	printf("pselect 5 \"over\" 2 = %f\n",psel(5,2));
	printf("select 5 \"over\" 2 = %f\n",sel(5,2));
}
double kevinsmath(double er1,double er2,double etot)
{
	double eoxy1 = er1 - 2.0;
	double eoxy2 = er2 - 2.0;
	if (eoxy1 - eoxy2 == 0.0)
	{
		double d = 0.0;
	}
}
