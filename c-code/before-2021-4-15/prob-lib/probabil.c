#include <stdio.h>
#include <stdlib.h>
#include "probabil.h"
int factorial(int n)
{
	if (n < 0)
	{
		fprintf(stderr,"Error - Negative number %d cannot be factorialed.\n",n);
		exit(1);
	}
	if (n == 0)
	{
		return 1;
	}
	return (n * factorial(n - 1));
}
int pselect(int n, int k)
{
	return ((factorial(n)) / (factorial(n - k)));
}
int cselect(int n, int k)
{
	return ((factorial(n)) / (factorial(k)) * factorial(n - k));
}

float convertPercent(float n, float min, float max)
{
	return (((n - min) / (max - min)) * 100);
}

float percentage(float n, float k)
{
	return (((n) / (k)) * 100);
}
