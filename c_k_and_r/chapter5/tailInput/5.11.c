#include "const.h"

static void printLastNLines(char ** x, int n, int totalLines);
int readLines(char **, int );

int main(int argc, char ** argv){
	// this will support tail -n 
	int defaultNLines = DEFAULT_LINE;
	if(argc == 1){
		;
	}else if(argv[1][0] == '-' && argv[1][1] == 'n'){
		if(argc >=3 )
			defaultNLines = atoi(argv[2]);
		if(defaultNLines <= 0){
			printf("we cannot print %d lines for you, sorry\n", defaultNLines);				
			return -1;
		}
	}else{
		printf("the operator %s is not recognized\n", argv[1] );
		return -1;
	}
	char *x[MAX_LINE];
	int totalLines = readLines(x, MAX_LINE);
	printLastNLines(x, defaultNLines, totalLines);
	return 1;
}

static void printLastNLines(char ** x, int n, int totalLines){
	printf("\nprint the last %d rows:\n", n);
	n = (n > totalLines) ? totalLines : n;
	for(int i = totalLines - n; i < totalLines; ++i){
		printf("%s",x[i]);
	}
}