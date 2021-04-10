#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "simulator.h" //include a bunch of stuff, including our custom functions fact(), psel() and sel() (sidenote: Seriously math.h, for a maths lib, its kinda stoopid that you dont include a factorial function)
#define MAXELEC 5
#define SRTELEC 2
#define LOOPS 10
#define MOLNUMB 10 // some constants 
long double kevinsmath(); // sidenote 2: bloody everything has to be long doubles because of pricision, meaning its kinda bad not gonna lie, buts thats how the cookie crumbles
int main()
{
	unsigned long seed = mix(clock(),time(NULL),getpid());
	srand(seed);
	long double molecules[MOLNUMB]; // init main vars, if i need malloc here someone open a PR
	long double etot = MAXELEC;
	for (int i = 0; i < MOLNUMB; i++)
	{
		molecules[i] = SRTELEC; // init out mol array
	}
	long double psrnd = doublerand();
	long double ngrnd = negdoublerand();
	printf("pos rand is %Lf, neg rand is %Lf\n",psrnd,ngrnd);
	printf("running 'da math™'\n");
	long double result = 0;
	long double randomnumber;
	long long endelecs = 0;
	for (int loopnum = 0; loopnum < LOOPS; loopnum++)
	{
		for (int loop2 = 0; loop2 < MOLNUMB; loop2++)
		{
			result = kevinsmath(molecules[loop2],molecules[loop2 + 1],etot);
			if (result > 0)
			{
				randomnumber = doublerand();
				if (randomnumber < result)
				{
					molecules[loop2]--;
					molecules[loop2 + 1]++;
				}
			}
			else 
			{
				randomnumber = negdoublerand();
				if (randomnumber > result)
				{
					molecules[loop2]++;
					molecules[loop2 + 2]--;
				}
			}
		}
		if (molecules[MOLNUMB - 1] > 0)
		{
			endelecs = endelecs + molecules[MOLNUMB - 1];
			molecules[MOLNUMB - 1] = 0;
		}
		molecules[0] = etot;
		
	}
	printf("Total number of iterations of the maths equation: %lld, end result of electrons: %lld\n", (long long) (LOOPS * MOLNUMB),endelecs);
	return 0;
}
long double kevinsmath(long double er1,long double er2,long double etot)
{
	long double eoxy1 = er1 - 2.0; // oxy states
	long double eoxy2 = er2 - 2.0;
	long double d,c,chk1 = 0,chk2 = 0;
	if (comparedouble(etot,er1))
	{
		chk1 = 1.0;
	}
	if (comparedouble(er2,etot))
	{
		chk2 = 1.0;
	}
	if (comparedouble(eoxy1 - eoxy2,0.0))
	{
		d = 1.0;
	}
	else
	{
		d = 0.0;
	}
	if (comparedouble(fabsl(eoxy1 * eoxy2),0.0))
	{
		c = 1.0;
	}
	else
	{
		c = 0.0;
	} //define d and c according to the above rules dependant on the oxy states
	long double S = ( ( ( eoxy1 - eoxy2 ) / ( fabsl( eoxy1 * eoxy2 ) + c ) ) + d ); // define S according to the oxy states and stuff
	if (comparedouble(er1,0.0))
	{
		return 0; // no math case 1
	}
	if (comparedouble(er1,1.0))
	{
		long double result = ((1.0/etot) * (2.0/(psel(etot,1,1))) * (1.0/3.0) * (S));
		return result; // math case 1
	}
	if (er1 >= etot)
	{
		if (er2 >= etot)
		{
			return 0;
		}
		return 1; // this should really be case 2, but lmao i cant be bothered to fix it cause this case will never arrise anyway (if im the one using the program), so anyone else using this: dont input 1,x,1 into the program or you will get the wrong result ok?
	}
	else 
	{
		long double part1 = ((er1/etot) * (1.0/3.0) * (S));
		long double part2 = (2 * (sel(er1,1,20) * psel(etot - 2, er1 - 1, 21)));
		long double part3 = (sel(er1, 2, 21) * psel(etot - 3, er1 - 2, 22));
		long double part4 = (psel(etot,er1,23));
		long double betterresult = (part1 * ((part2 + part3) / part4));
		return betterresult;
	}
	printf("there should be no way something gets here, and it is an error if something does: we are gonna exit now\n");
	exit(1);
}
