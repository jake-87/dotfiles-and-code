#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
typedef struct Tri
{
	int vert[3][2];
} tri;
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
 
/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
int isInside(tri * triangle,int px, int py)
{ 
	int x1 = triangle->vert[0][0];
	int y1 = triangle->vert[0][1]; 
	int x2 = triangle->vert[1][0]; 
	int y2 = triangle->vert[1][1]; 
	int x3 = triangle->vert[2][0]; 
	int y3 = triangle->vert[2][1]; 
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);
 
   /* Calculate area of triangle PBC */  
   float A1 = area (px, py, x2, y2, x3, y3);
 
   /* Calculate area of triangle PAC */  
   float A2 = area (x1, y1, px, py, x3, y3);
 
   /* Calculate area of triangle PAB */   
   float A3 = area (x1, y1, x2, y2, px, py);
   /* Check if sum of A1, A2 and A3 is same as A */
   if (A == A1 + A2 + A3)
   {
//	   printf("Equal\n");
	   return 1;
   }
   else
   {
//	   printf("Not Equal\n");
	   return 0;
   }
   return (A == A1 + A2 + A3);
}
int main(void)
{
	int trinum;
	printf("How many tris?");
	scanf("%d",&trinum);
	tri triangle[100];
	char * blank = "   ";
	char * full = "███";
	for (int i = 0; i < trinum; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("Tri %d vert %d X : ",i,j);
			scanf("%d",&triangle[i].vert[j][0]);
			printf(" You entered %d\n",triangle[i].vert[j][0]);
			printf("Tri %d vert %d Y : ",i,j);
			scanf("%d",&triangle[i].vert[j][1]);
			printf(" You entered %d\n",triangle[i].vert[j][1]);
		}
	}
	const int screenx = 40;
	const int screeny = 40;
	int chk = 0;
	for (int i = 0; i < screenx; i++)
	{
		for (int j = 0; j < screeny; j++)
		{
			if (i % 2 == 0)
			{
				printf("%s",full);
			}
			else
			{
				printf("%s",blank);
			}
			/*
			for (int num = 0; num < trinum; num++)
			{
				if (isInside(&triangle[num],j,i) == 1)
				{
					printf("%s",full);
					chk = 1;
				}
			}
			if (!chk)
			{
				printf("%s",blank);
			}
			chk = 0; */
		}
		printf("\n");
	}
}
