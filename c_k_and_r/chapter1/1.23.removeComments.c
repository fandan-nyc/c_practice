#include <stdio.h> 

// remove comments from c program 
// no nested comments

#define MAX_LINE 1000


int commentSingCounter = 0;
char s[MAX_LINE];

void getLine(){
	int i = 0;
	int c;
	while( i < MAX_LINE-1  && (c=getchar()) != EOF){
		if( commentSingCounter == 2){
			if(c == '\n'){
				commentSingCounter = 0;
			}
		}else if( c != '/'){
			commentSingCounter = 0;
			s[i++] =c;
		}else{
			++commentSingCounter;
			if( commentSingCounter == 2){
				i = i-1;
			}
			else{
				s[i++] = c;
			}
		}
	}
	s[i] = '\0';
}

int main(int argc, char ** argv){
	getLine();
	printf("\nthe program looks like:\n");
	printf("%s",s);
}