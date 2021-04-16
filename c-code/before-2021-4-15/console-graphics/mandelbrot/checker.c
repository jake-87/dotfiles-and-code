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
		printf("blank");
	}
	else
	{
		printf("color");
	}	

