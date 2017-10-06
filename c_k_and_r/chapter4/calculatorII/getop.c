#include "header.h"

int getch();
void ungetch(char c);

int getop(char s[]){
	int i = 0;
	int c ; 
	while((s[0] = c = getch()) == ' '|| c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.'){
		return c;
	}
	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	if(c == '.'){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	ungetch(c);
	return NUMBER;
}