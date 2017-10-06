#include <stdio.h>
#include <stdlib.h>

int revertPart(int, int, int);
void printBinary(int);

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	int p = atoi(argv[2]);
	int n = atoi(argv[3]);
	printf("input: %d\n",input);
	printf("    p: %d\n",p);
	printf("    n: %d\n",n);
	printf("input in binary:  ");
	printBinary(input);
	int result = revertPart(input, p,n);
	printf("result in binary: ");
	printBinary(result);
}

int revertPart(int x, int p, int n){
	int tmp =((~((~0) << n)) << (p-n+1));
 	return ((~tmp) & x)| (tmp &(~x));
}

void printBinary(int input){
	char s[32];
	for(int i = 31; i >= 0; --i, input >>= 1){
		s[i] = (input&1) + '0';
	}
	printf("print binary %s\n", s);
}