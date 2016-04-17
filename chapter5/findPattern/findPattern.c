#include "constants.h"

int getLine(char *, int);
char * alloc(int);
void printLines(char **, int);
void strCopy(char *, char *);

int main(int argc, char ** argv){
	if(argc < 2){
		printf("find pattern. usage: ./out.a [-x] [-n]\n");
	}
	int except = 1;
	int rowNum = 1;
	char * pattern = argv[argc-1];
	while(--argc > 0 && (*++argv)[0] == '-'){
		int i = 1;
		char x;
		while( (x = *(++(*argv)))){
		switch(x){
			case 'n':
				rowNum = 0;
				break;
			case 'x':
				except = 0;
				break;
			default:
				printf("not known operator %c is ignored\n",x); 
				break;
			}
		}
	}
	char tmpLine[MAX_CHAR_PER_LINE];
	int len ;
	char *store[MAX_LINE];
	int lineCounter = 0;
	int lineNumbers[MAX_LINE];
	int* lineNumbersP = lineNumbers;
	while((len = getLine(tmpLine,MAX_CHAR_PER_LINE)) > 0){
		if((strstr(tmpLine, pattern)!=NULL) == except) {
			char * p = alloc(len);
			store[lineCounter] = p;
			strCopy(p,tmpLine);
			if(rowNum){
				*lineNumbersP++ = lineCounter;
			}
			lineCounter++;
		}
	}
	printLines(store, lineCounter-1);
}

