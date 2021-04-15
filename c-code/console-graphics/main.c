#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
typedef struct
{
	int x;
	int y;
}point;
typedef struct
{
	point vert[3];
} tri;
float triangleArea(point p1, point p2, point p3)
{
	float A=sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
    	float B=sqrt(((p3.x-p2.x)*(p3.x-p2.x))+((p3.y-p2.y)*(p3.y-p2.y)));
    	float C=sqrt(((p1.x-p3.x)*(p1.x-p3.x))+((p1.y-p3.y)*(p1.y-p3.y)));
    	float side=((A+B+C)/2);
    	float area=sqrt(side*(side-A)*(side-B)*(side-C));
	return area;
}
int isInside(tri triangle, point p1)
{
	float A = triangleArea(triangle.vert[0],triangle.vert[1],triangle.vert[2]);	
	float A1 = triangleArea(p1,triangle.vert[1],triangle.vert[2]);
	float A2 = triangleArea(triangle.vert[0],p1,triangle.vert[2]);
	float A3 = triangleArea(triangle.vert[0],triangle.vert[1],p1);
	//printf("A is %f, A1 is %f A2 is %f a3 is %f\n",A,A1,A2,A3);
	if (A == A1 + A2 + A3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	int i,j;
	int chk;
	int numtri;
	printf("How many tris? : ");
	scanf("%d",&numtri);
	tri triangle[numtri];
	for (i = 0; i < numtri; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Tri %d vert %d X : ",i,j);
			scanf("%d",&triangle[i].vert[j].x);
			printf("You just entered %d\n",triangle[i].vert[j].x);
			printf("Tri %d vert %d Y : ",i,j);
			scanf("%d",&triangle[i].vert[j].y);
			printf("You just entered %d\n",triangle[i].vert[j].y);
		}
	}
	int xpos,ypos,num;
	char * full = "\u2588\u2588";
	char * empty = "  ";
	point tmp;
	for (ypos = 0; ypos < 40; ypos++)
	{
		for (xpos = 0; xpos < 40; xpos++)
		{
			chk = 0;
			for (num = 0; num < numtri; num++)
			{
				if (chk)
				{
					continue;
				}
				//printf("isInside tri[num] and tmp is %d",isInside(triangle[num],tmp));
				tmp.x = xpos;
				tmp.y = ypos;
				if (isInside(triangle[num],tmp) == 1)
				{
					printf("%s",full);
					chk = 1;
				}
				else
				{
					printf("%s",empty);
				}
			}
		}
		printf("\n");
	}
}
