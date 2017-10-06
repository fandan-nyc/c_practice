#include <ctype.h>
#include <stdio.h>
char getch();
void ungetch(char);

char getword(char * s, int max){
	char * t  = s;
	int counter = 0;  
	char c; 
	while(isspace(c=getch()))
		;
	if(c != EOF){
		*s++ = c;
	}
	if(!isalpha(c)){
		*s = '\0';
		return c;
	}
	while( counter++ < max && isalnum(*(s++) = c = getch()))
		;
	ungetch(c);
	*(s-1) = '\0';
	return *t;
}