#include "header.h"

static int c  = -1;
char getch(){
	if(c != -1){
		int x  = c;
		c = -1;
		return x;
	}
	return getchar();
}

void ungetch(char x){
	c = x ;
}