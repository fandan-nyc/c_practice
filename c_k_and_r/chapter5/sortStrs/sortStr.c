#include "header.h"

int readLines(char *x[],int maxLine);
void printLines(char *x[],int totalLines);
void qsort(char *x[], int, int);

int main(int argc, char ** argv){
	char * x[MAX_LINES];
	int lines = readLines(x, MAX_LINES);
	printf("\nprintout the input:\n");
	qsort(x,0,lines-1);
	printLines(x,lines);
}

void printLines(char *x[], int totalLines){
	for(int i = 0; i < totalLines; i ++){
		printf("%s",x[i]);
	}
}