#include <stdio.h>

#define MAX_LINE 100

char s[MAX_LINE];

void getLineDetab();

int main(int argc, char ** argv){
	getLineDetab();

	printf("the detabbed line is\n");
	printf("%s\n",s);
}

void getLineDetab(){
	int i = 0; 
	int c ; 
	while( i < MAX_LINE && (c=getchar()) != EOF){
		if(c =='\t'){
			for( int j = 0; j < 4; j++){
				s[i++] = '#';
			}
		}
		else{
			s[i++] = c;
		}
	}
	s[i] = '\0';
}



