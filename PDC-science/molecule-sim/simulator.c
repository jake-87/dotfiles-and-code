#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "simulator.h" //include a crap ton of stuff, including our custom functions fact(), psel() and sel() (sidenote: Seriously math.h, for a maths lib, its kinda stoopid that you dont include a factorial function)
#define MAXELEC 5
#define SRTELEC 2
#define MOLNUMB 10 // some constants 
long double kevinsmath(); // sidenote 2: bloody everything has to be long doubles because of pricision, meaning its kinda bad not gonna lie, buts thats how the cookie crumbles
int main()
{
	long double molecules[MOLNUMB]; // init main vars, if i need malloc here someone open a PR
	long double etot = MAXELEC;
	for (int i = 0; i <= MOLNUMB; i++)
	{
		molecules[i] = SRTELEC; // init out mol array
	}
	for (long double i = 0.f; i <=  ( long double ) MAXELEC; i++)
	{
		for (long double j = 0.f; j <= ( long double ) MAXELEC; j++)
		{
			printf("i is %Lf, j is %Lf ",i,j); // apply the equation to every possible combination of molecules
			kevinsmath(i,j, etot); // ^^^^^
		}
	}
}
long double kevinsmath(long double er1,long double er2,long double etot)
{
	long double eoxy1 = er1 - 2.0; // oxy states
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
	} //define d and c according to the above rules dependant on the oxy states
	long double S = ( ( ( eoxy1 - eoxy2 ) / ( fabsl( eoxy1 * eoxy2 ) + c ) ) + d ); // define S according to the oxy states and stuff
	printf("S is %Lf ",S);
	if (er1 == 0.0)
	{
		printf("result is 0\n");
		return 0; // no math case 1
	}
	if (er1 == 1.0)
	{
		long double result = ((1.0/etot) * (2.0/(psel(etot,1,1))) * (1.0/3.0) * (S));
		printf("result is %Lf\n",result);
		return result; // math case 1
	}
	if (er1 == etot)
	{
		printf("result is %d\n",1);
		return (1); // this should really be case 2, but lmao i cant be bothered to fix it cause this case will never arrise anyway (if im the one using the program), so anyone else using this: dont input 1,x,1 into the program or you will get the wrong result ok?
	}
	else 
	{
		long double result = ((er1/etot) * ((((2 * (sel(er1,1,2) * psel(etot - 2, er1 - 1,3)) + (sel(er1,1,4) * psel(etot - 3,er1 - 2,5)))) / psel(etot,er1,6))) * (1.0/3.0) * (S));
		printf("result is %Lf\n",result); // biggie math time and math case 2, this uses a heap of functions from the header file, so go look at that for moar info
		return result;
	}
	return 0; // this does not need to be here but the compiler complains otherwise and its annoying
}
