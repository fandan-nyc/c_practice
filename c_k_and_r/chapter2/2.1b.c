#include <stdio.h>
#include <limits.h>


int main(int argc, char ** argv){
	
	printf("from limits.h\n");
	printf("signed char max: %d\n", CHAR_MAX);
	printf("signed char min: %d\n", CHAR_MIN);
	printf("unsigned char max: %d\n", UCHAR_MAX);
	printf("from my calculattion\n");
	unsigned char c= ~0; 
	c >>= 1; 
	printf("signed char max: %d\n",c);
	printf("signed char min: %d\n",-c-1);
	printf("unsigned char max: %d\n",c<<1 |1);
	printf("unsigned char max: %d\n",2*c+1);

	unsigned short d= ~0; 
	d >>= 1; 
	printf("signed short max: %d\n",d);
	printf("signed short min: %d\n",-d-1);
	printf("unsigned short max: %d\n",d<<1 |1);
	printf("unsigned short max: %d\n",2*d+1);

	unsigned int e= ~0; 
	e >>= 1; 
	printf("signed int max: %d\n",e);
	printf("signed int min: %d\n",-e-1);
	printf("unsigned int max: %u\n",e<<1 |1);
	printf("unsigned int max: %u\n",2*e+1);

	unsigned long f= ~0; 
	f >>= 1; 
	printf("signed long max: %ld\n",f);
	printf("signed long min: %ld\n",-f-1);
	printf("unsigned long max: %lu\n",f<<1 |1);
	printf("unsigned long max: %lu\n",2*f+1);







}