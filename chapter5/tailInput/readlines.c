#include "const.h"


static int readLine(char *, int);
static char tmp[MAX_CHAR_PER_LINE];
static void strcopy(char *, char *);
static int  readLine(char * s, int max);


char * alloc(int);
int readLines(char ** x, int max){
	int len ;
	int lineCounter  = 0 ;
	while( lineCounter < max && (len = readLine(tmp, MAX_CHAR_PER_LINE)) > -1 ) {
		if(len > 0){
			char * p = alloc(len);
			strcopy(p, tmp);
			*x++ = p;
			++lineCounter;
		}
	}
	if(lineCounter > max){
		printf("cannot take more lines. we are full");
		return max;
	}
	return lineCounter ;
}



static void strcopy(char * a, char * b){
	while((*a++ = *b++))
		;
}

static int  readLine(char *s, int max){
	int counter = 0; 
	int c ;
	while( counter< max && ( s[counter++] = c = getchar()) != EOF && c != '\n')
		;
	if(counter >= max){
		printf("error: cannot store more than %d chars per line, this line will be skipped", max);
		return 0;
	}
	if(c == EOF )
		return  -1;
	s[counter++] = '\0';
	return counter;
}
