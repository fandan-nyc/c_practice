#include <stdio.h>

static int tmp = -1; 
char getch(){
	if(tmp == -1){
		return getchar();
	}
	char x =  tmp;
	tmp = -1;
	return x;
}

void ungetch(char x){
	tmp = x;
}