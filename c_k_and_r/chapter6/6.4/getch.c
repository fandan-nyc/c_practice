#include <stdio.h>

int tmp = -1 ;

char getch(){
	if(tmp != -1){
		char x= tmp; 
		tmp = -1; 
		return x;
	}
	return getchar();
}

void ungetch(char x){
	tmp = x;
}