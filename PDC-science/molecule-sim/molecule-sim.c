#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 13
void halt_and_catch_fire();
int checkarr();
int printarr();
int printarr(int array[MAX][MAX],int numOfElements, int bonds, int electrons)
{
	printf("printing array\n");
	char * funcname = "printarr";
	int i = 0,j;
	for (i = 0;i < numOfElements; i++)
	{
		for (j = 0;j < bonds; j++)
		{
			printf("Mol %d, bond %d has electron state %d.\n",i,j,array[i][j]);
		} // loop through the array, printing every electron state
	}
	int chk = checkarr(array,bonds,numOfElements);
	if (chk != 0) // check the array
	{
		halt_and_catch_fire(funcname,"Checkarr");
	}
	printf("Number of electrons: %d\n",electrons); // print number of electons
	return 0;
}

void halt_and_catch_fire(char * messed_up,char * whatmessedup)
{
	printf("%s messed up in func %s\n",whatmessedup,messed_up);
	exit(1); //print what messed up in what function, and exit
}
int checkarr(int array[MAX][MAX], int bonds, int molecules)
{
	printf("Checking array\n");
	char * funcname = "checkarr";
	int i = 0, j = 0;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (array[i][j] > 1)
			{
				return 1; // loop through the array and see if any electrons are greater than 1, which would indicate an error
			} //TODO: impliment more tests
		}
	}
	return 0;
}
double factorial(double i)
{
	if (i < 0)
	{
		printf("You were trying to factorial a negative number silly! %f.\n",i);
	}
	if (i == 0)
	{
		return 1;
	}
	double a = (i * factorial(i - 1));
	return a;
}
double kevinsmath(double numofelec, double numofelec2, double bonds)
{
	int c,d;
	char * name = "kevinsmath";
	if (numofelec != 0 && numofelec2 != 0)
	{
		c = 0;
		d = 0;
	}
	else if (numofelec == 0 || numofelec2 == 0)
	{
		c = 1;
		d = 1;
	}
	if (bonds == 0.0)
	{
		return 0;
	}
	if (bonds == numofelec)
	{
		return 1;
	}
	double S = ((numofelec - numofelec2) / ( (abs(numofelec * numofelec2)) + c ) + d);
	if (numofelec == 1.0)
	{
		double result = ((1/bonds) * (2/((factorial(bonds))/factorial(numofelec))) * (1/3) * (S));
		if (result < -1 || result > 1)
		{
			printf("%f\n",result);
			halt_and_catch_fire(name,"result from numofelec in current mol = 1 was OOB");
		}
		return result;
	}
	else 
	{
		double result = (((((2 * ((numofelec * ((factorial(bonds - 2))) / (factorial((bonds - 2) - (numofelec - 1)))))) + ((factorial(numofelec)/(2 * factorial(numofelec - 2) * (factorial(bonds - 3) / ((factorial(bonds - 3)) - (numofelec - 2))))))) / ((factorial(bonds))/(factorial(bonds - numofelec)))) / (factorial(bonds) / (factorial(bonds) - factorial(numofelec)))) * S * (bonds / numofelec) * (1/3));
		if (result < -1 || result > 1)
		{
			printf("%f\n",result);
			halt_and_catch_fire(name,"result from numofelec in current mol was OOB");
		}
		return result;
	}
}
int main()
{
	char * funcname = "main";
	int molecules = 10;
	int bonds = 5;
	int i, j;
	int electrons = 0;
	int molarr[MAX][MAX]; // init all variables; fairly sure i dont need malloc() or free() here
	for (i = 0; i < MAX; i++)
	{
		if (i < molecules)
		{
			molarr[i][0] = 1;
			molarr[i][1] = 1;
			electrons++;
			electrons++;
			for (j = 2; j < MAX; j++)
			{
				molarr[i][j] = 0; // init the array full of electrons
			}
		}
		else
		{
			for (j = 0; j < MAX; j++)
			{
				molarr[i][j] = 0;
			}
		}
	}
	int chk = checkarr(molarr,bonds,molecules);
	if (chk != 0)
	{
		char * whatmessedup = "checkarr was OOB";
		halt_and_catch_fire(funcname,whatmessedup); // check the array
	}
	printarr(molarr,MAX,bonds,electrons); // print the array
	double result = kevinsmath(5,2,10);
	printf("%f\n",result);
}
