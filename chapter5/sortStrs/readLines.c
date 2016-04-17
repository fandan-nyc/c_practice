#include "header.h"

char * alloc(int);
int readLine(char *, int);
void strcp(char *, char *);

int readLines(char *x[],int maxLine){
	char tmp[MAX_LEN_PER_LINE];
	int len ;
	char * p;
	int lineCounter;
	while((len = readLine(tmp, MAX_LEN_PER_LINE)) > 0 && (p = alloc(len)) != 0 && lineCounter < MAX_LINES){
		if(p == 0 || lineCounter > MAX_LINES || len < 0){
			printf("error: failed to read all lines");
		}
		strcp(p,tmp);
		x[lineCounter++] = p;
	}
	return lineCounter;
}



int readLine(char *x, int maxLen){
	int counter  = 0; 
	int c;
	while((x[counter++] = c = getchar()) != EOF && c != '\n' && counter < maxLen)
		;
	if(c == '\n'){
		x[counter++] = '\0';
	}
	else if(c == EOF || counter >= maxLen){
		return -1 ;
	}
	return counter;

}

void strcp(char * x, char *y){
	while((*x++ = *y++))
		;
}