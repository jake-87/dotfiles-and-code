#include <stdio.h>
#include <stdlib.h>
int main()
{
	const int width = 800, height = 800,max = 50;
  	int i, j;
  	FILE *fp = fopen("first.ppm", "wb"); /* b - binary mode */
  	(void) fprintf(fp, "P6\n%d %d\n255\n", width, height);
	for ( i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			int row = i; int col = j;
			double c_re = (col - width/2.0)*4.0/width;
			double c_im = (row - height/2.0)*4.0/width;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < max) {
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < max)
			{
				fprintf(fp,"255 255 255\n");
			}
			else
			{
				fprintf(fp, "0 0 0");
			}	
		}
	}
	fclose(fp);
}
