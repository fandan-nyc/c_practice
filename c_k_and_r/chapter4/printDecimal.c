#include <stdio.h>
#include <stdlib.h>

void printDecimal(int);

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	printDecimal(input);
	printf("\n");
	return 0;
}

void printDecimal( int n){
	if(n < 0){
		putchar('-');
		n = -n ; 
	}
	if(n / 10){
		printDecimal(n/10);
	}
	putchar(n %10 + '0');
}

