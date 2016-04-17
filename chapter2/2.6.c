#include <stdio.h>
#include <stdlib.h>


static char bin[33];

static void intToBinary(int, char*);
// replace the n digits after position in input by the right most n digit of other;
static int replace(int input, int p, int n, int other);

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	int p = atoi(argv[2]);
	int n = atoi(argv[3]);
	int other = atoi(argv[4]);
	printf("the input is %d\n",input);
	intToBinary(input, "input");
	printf("we want to do replace against: x: %d, p: %d, n: %d, other: %d\n",input, p, n, other);
	int replaced = replace(input, p,n, other);
	intToBinary(other,"other");
	intToBinary(replaced,"replaced");
}

void intToBinary(int input, char * varName){
	int counter  = 0;
	for(int i = 31; i >=0; --i,input >>= 1){
		bin[i] = (input & 1) + '0';
	}
	bin[32] = '\0';
	printf("the binary format  %20s is %s\n", varName,bin);
}

int replace(int input, int p, int n, int other){
	// get the right most n digits in in the righ position
	int tmp = (~(~0 << n)); 
	int newTmp = tmp <<(p -n +1 );
	int revertedNewTmp = ~ newTmp;
	return (input & revertedNewTmp) | ((tmp & other) << (p+1-n));
}