#include <stdio.h>
#include <stdlib.h>

int rotate(int, int);
static void printBinary(int);

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	int n = atoi(argv[2]);
	printf("input: %d\n",input);
	printf("    n: %d\n",n);
	printBinary(input);
	int rotated = rotate(input, n);
	printBinary(rotated);

}

int rotate(int x, int n){
	return ((((~0) << n) & x) >> n) | (((((~0) << (32-n)) >> (32 -n)) & x) << (32-n));
}

static void printBinary(int input){
	char s[32];
	for(int i = 31; i >= 0; --i, input >>= 1){
		s[i] = (input&1) + '0';
	}
	printf("print binary %s\n", s);
}