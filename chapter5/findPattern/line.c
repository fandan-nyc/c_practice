#include "constants.h"

int getLine(char * input, int max_char){
	int c ; 
	int i = 0;
	while((input[i++] = c = getchar()) != EOF && c != '\n')
		;
	if(c == EOF)
		return 0;
	input[i++] = '\0';
	return i;
}

void strCopy(char * a, char * b){
	while((*a++ = *b++))
		;
}

void printLines(char ** input, int lines){
	printf("\n start to print out: \n");
	while(lines -- >=0){
		printf("%s", *(input++));
	}
}