#include "const.h"

char getch();
void ungetch(char);

char getword(char *s, int max){
	int counter = 0; 
	int c ;
	while(isspace(c=getch()))
		;
	if(c != EOF){
		s[counter++] = c;
	}
	if(!isalpha(c)){
		s[counter] = '\0';
		return c;
	}
	while(--max > 0 && isalnum((s[counter++] = c = getch())))
		;
	ungetch(c);
	s[counter-1] = '\0';
	return s[0];
}