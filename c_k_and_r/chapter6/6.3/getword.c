
#include <ctype.h>
#include <stdio.h>
#include "dataType.h"


char getch();
void ungetch();
static int counter = 1;

WordType getword(char *s, int max){
	int c;
	while(isspace(c=getch())){
		if(c == '\n')
			counter ++;
	}
	if(c == EOF){
		return END;
	}
	if(!isalnum(c)){
		return NON_WORD;
	}
	int counter  = 0;
	s[counter++] = c;
	while( counter < max && isalnum( s[counter++]= c = getch()))
		;
	ungetch(c);
	s[counter-1] = '\0';
	return WORD;
}


int getLineNum(){
	return counter;
}