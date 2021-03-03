#include <stdio.h>
#include <unistd.h>
int main()
{
	long double centaur = 0;
	long double horse = 0.5;
	long double store;
	int counter;
	while (horse != 1)
	{
		counter++;
		centaur += horse;
		store = horse;
		horse = store / 2;
		printf("centaur is %Lf\n",centaur);
		printf("horse is %Lf\n",horse);
		printf("counter is %d\n",counter);
		sleep(0);
	}
}
		
