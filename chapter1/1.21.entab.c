#include <stdio.h>
#define MAX_LINE 1000

char s[MAX_LINE];
int spaceNum;

void entab();

int main(int argc, char ** argv){
	entab();
	printf("after entab\n");
	printf("%s\n", s);
}

void entab(){
	int i = 0; 
	int c ;
	spaceNum = 0;
	while( i < MAX_LINE && (c = getchar()) != EOF){
		if(c != ' '){
			s[i++] = c;
			spaceNum = 0;
		}
		else if(spaceNum == 3){
			s[i-3] = '\t';
			spaceNum = 0;
			i = i-2;
		}
		else{
			s[i++] = c;
			++spaceNum;
		}
	}
	s[i] = '\0';
}

