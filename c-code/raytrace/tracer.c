#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	int nx=1600;
	int ny=900;
	printf("P3\n%d %d\n255\n",nx,ny);
	for (int j = ny - 1; j >=0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float fnx = nx; // boilerplate
			float fny = ny;
			float fi = i;
			float fj = j;
			int rand1 = (rand() % 256);
			int rand2 = (rand() % 256);
			int rand3 = (rand() % 256);
			// end boilerplate
			float r =       fi / fnx;
			float g =       fj / fny;
			float b = 0.2;//      0.2;
			int ir = (255.99*r);
			int ig = (255.99*g);
			int ib = (255.99*b);
			printf("%d %d %d\n",ir,ig,ib);
		}
	}
}
