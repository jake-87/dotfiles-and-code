#include <stdio.h>
#include <math.h>
FILE *ppmfile;
int checkpix;
int square(int nx, int ny, int width, int height, int j, int i,int ir, int ig, int ib) 
{		
			ppmfile = fopen("paint.ppm","a");
			if (i > ((nx)-width) && i < ((nx)+width)) 
			{       
                                 if (j > ((ny)-height) && j < ((ny)+height)) // check if we are inside the square
                                 {           
					 checkpix = 1; //  set the pixel to 
                                 }           
					 
                        }        
 			fclose(ppmfile);
			return 0;
}
int circle(int locx, int locy, int width, int j, int i, int ir, int ig, int ib)
{
	ppmfile = fopen("paint.ppm","a");
	double distancesqrd = ((locx-i)*(locx-i)+(locy-j)*(locy-j));
	double distance = sqrt(distancesqrd);
	if (distance <= width)
	{
		checkpix = 1;
	}
	fclose(ppmfile);
	return 0;
}
int main()
{
	
	ppmfile = fopen("paint.ppm","w");
	int nx;//=600;
	int ny;//=600; // init the height and width of the image
	int ir = 255;
	int ig = 255;
	int ib = 255; // init default colors
	int shapetype[99];
	int shapelocx[99];
	int shapelocy[99];
	int shapewidth[99];
	int shapeheight[99];
	int shapenum;
	char endlist[10000000];
	printf("How large should the canvas be? x {space} y >>> ");
	scanf("%d %d",&nx,&ny);
	int chkpixel = 0;
	fprintf(ppmfile,"P3\n%d %d\n255\n",nx,ny); // printf headers
	fclose(ppmfile);
	printf("%s",endlist);
	printf("How many shapes do you want? (Less then 100) >>> ");
	scanf("%d",&shapenum);
	int counter = 0;
	for (int ii = 0; ii < shapenum; ii++)
	{
		printf("Shape %d:\n",ii+1);
		printf("What shape do you want?\n (1) Square \n (2) Circle\n >>> ");
		scanf("%d", &shapetype[ii]);
		printf("Where should the shape be located? Input co-ords as x {space} y >>> ");
		scanf("%d %d",&shapelocx[ii],&shapelocy[ii]);
		printf("How large should the shape be? Input as width {space} height (Note: if the shape is a circle, only the width will be used as the radius.) >>> ");
		scanf("%d %d",&shapewidth[ii],&shapeheight[ii]);
		counter++;
	}
	printf("What color should the shapes be? Input as r {space} g {space} b >>> ");
	scanf("%d %d %d",&ir,&ig,&ib);
	printf("Calculating...\n");
	for (int j = ny; j > 0; j--) // for every y pixel increment j
	{
		for (int i = 0; i < nx; i++) // for every x pixel increment i
		{
			for (int inc = 0; inc < counter; inc++)
			{
				if (shapetype[inc] == 1) 
				{
					square(shapelocx[inc],shapelocy[inc],shapewidth[inc],shapeheight[inc],j,i,ir,ig,ib); 
				} //r,g,b); // call the square func with the params
				if (shapetype[inc] == 2) { circle(shapelocx[inc],shapelocy[inc],shapewidth[inc],j,i,ir,ig,ib);}
				if (checkpix != 0)
				{
					if (chkpixel == 1)
					{
						break;
					}
					checkpix = 1;
					ppmfile = fopen("paint.ppm","a");
					fprintf(ppmfile,"%d %d %d\n",ir,ig,ib);
					fclose(ppmfile);
					chkpixel = 1;
				}
			}
			if (checkpix == 0)
			{
				ppmfile = fopen("paint.ppm","a");
				fprintf(ppmfile,"0 0 0\n");
				fclose(ppmfile);

			}
			chkpixel = 0;
			checkpix = 0;
		}
		checkpix = 0;
	}
	printf("\nDone. Outputted as \"paint.ppm\".\n");
}
