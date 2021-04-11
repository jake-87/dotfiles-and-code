#include <stdio.h>
#include "../probabil.h"
int main()
{
	int psel = pselect(5,3); // calculate the pselect of 5,3
	printf("Pselect 5,3 is %d\n",psel);
	int csel = cselect(5,3); // calculate the cselect of 5,3
	printf("Cselect 5,3 is %d\n",csel);
	float convertPercentage = convertPercent(150,50,400);
	printf("150 is %f percent of the bounds 50,400\n",convertPercentage);
	float npercentage = percentage(60,165);
	printf("60 is %f percent of 165.\n",npercentage);
}
