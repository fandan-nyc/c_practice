#include <stdio.h>
#include <stdlib.h>

int bitCount(int);

void printBinary(int input){
	char s[32];
	for(int i = 31; i >= 0; --i, input >>= 1){
		s[i] = (input&1) + '0';
	}
	printf("print binary %s\n", s);
}

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	printBinary(input);
	printf("number of 1 bits in input is: %d",bitCount(input)); 
}

int bitCount( int x){
	int count = 0;
	while(x > 0){
		x = x&(x-1);
		++count;
	}
	return count;
}