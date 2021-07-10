#ifndef interpolateh
#define interpolateh
#include <stdio.h>
#include <stdint.h>
#include "flags.h"
#include "register.h"
#define i16 int16_t
#define ui16 uint16_t
union memdata {
	i16 * ip;
	ui16 * up;
	float * fp;
	char * cp;
	i16 i;
	ui16 u;
	float f;
	char c;
};
typedef struct {
	i16 * type; 
	// 1 = int
	// 2 = uint
	// 3 = float
	// 4 = char
	// 5 = int *
	// 6 = uint *
	// 7 = float *
	// 8 = char *
	i16 * dcpy;
	union memdata * d;
} mem_d;
typedef struct {
	i16 * reg;
	i16 * type; // see above
} reg_d;
void interpolate(unsigned int * ibuf, int size);
void hacf(char * message, int code, int ii);
void setflags(i16 num, ui16 ** flags);
int ckreg(i16 i);
#endif
