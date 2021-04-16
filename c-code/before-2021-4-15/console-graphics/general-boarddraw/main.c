#include <stdio.h>
#include <stdlib.h>
#define ANSI_RED "\x1b[31m"
#define ANSI_BLUE "\x1b[34m"
typedef struct 
{
	int x;
	int y;
} point;
int drawboard(int arrlen, point parr[],int width, int height)
{
	int tmpcheck = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			point tmp;
			tmp.x = j;
			tmp.y = i;
			if (tmpcheck == 1)
			{
				break;
			}
			for (int num = 0; num < arrlen; num++)
			{
				if (tmpcheck == 1)
				{
					//printf("should not print blank");
					break;
				}
				if (tmp.x == parr[num].x && tmp.y == parr[num].y)
				{
					printf(ANSI_RED "\u2588\u2588");
					tmpcheck = 1;
					//printf("should not print blank");
					break;
				}
			}
			//printf("%d",tmpcheck);
			if (tmpcheck == 0)
			{
				//printf("prt bnlk");
				printf(ANSI_BLUE "\u2588\u2588");
			}
			tmpcheck = 0;
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	point a;
	a.x = 20;
	a.y = 20;
	point arr[1];
	arr[0] = a;
	drawboard(1,arr,40,40);
}
