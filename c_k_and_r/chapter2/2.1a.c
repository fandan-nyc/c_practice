#include <limits.h>
#include <stdio.h>


int main(int argc, char ** argv){

	printf("bits of a bype: %d\n", CHAR_BIT);
	printf("char max: %d\n", CHAR_MAX);
	printf("cahr min: %d\n", CHAR_MIN);
	printf("signed char max: %d\n",SCHAR_MAX);
	printf("signed char min: %d\n",SCHAR_MIN);
	printf("unsigned char max: %d\n",UCHAR_MAX);

	printf("short min : %d\n",SHRT_MIN);
	printf("short max : %d\n",SHRT_MAX);
	printf("unsigned short max : %d\n",USHRT_MAX);


	printf("int max : %d\n",INT_MIN);
	printf("int min : %d\n",INT_MAX);
	printf("unsigned int max : %u\n",UINT_MAX);


	printf("long min : %ld\n",LONG_MIN);
	printf("long max : %ld\n",LONG_MAX);
	printf("unsigned long max : %lu\n",ULONG_MAX);
}