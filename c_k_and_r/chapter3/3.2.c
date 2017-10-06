#include <stdio.h> 

const int MAX_LINE = 1000;
char s[MAX_LINE]; 
void getLine(void);

int main(int argc, char ** argv){
	getLine();
	int i = 0;
	while( s[i] != '\0'){
		switch(s[i]){
			case '\t':
				printf("%s","\\t");
				break;
			case '\n':
				printf("%s","\\n");
				break;
			default:
				printf("%c",s[i]);
				break;
		}
		i++;
	}
}


void getLine(){
	int i=0;
	int c ;
	while(i < MAX_LINE -1 && (c=getchar()) != EOF){
		s[i++] =c;
	}
	s[i] = '\0';
}