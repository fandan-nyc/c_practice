#include <stdio.h> 

#define MAX_LINE 1000

int max =0;
char s[MAX_LINE];
char longest[MAX_LINE];

void copyStr();

int getLine();


int main()
{
	int len = 0;
	while((len = getLine()) >0 ){
		if(len > max ){
			max = len; 
			copyStr();
		}
	}
	printf("longest line \n");
	printf("%s",longest);
	return 0;
}

void copyStr(void){
	int i = 0;
	while(i < MAX_LINE  && (longest[i] = s[i]) != EOF){
		++i;
	}
}

int getLine(){
	int i = 0; 
	int c;
	while(i < MAX_LINE && (c=getchar())!=EOF && c != '\n'){
		s[i++] = c;
	}
	if(c == '\n'){
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}