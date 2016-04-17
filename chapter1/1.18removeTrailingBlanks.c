#include <stdio.h>
#define MAX_LEN 10

// remove trailing blanks and tabs

void trailEndingSpaceAndTab(char x[]){
	int i = 0;
	int lastPoint = 0;
	while(x[i] != '\0'){
		if(x[i] != '\t' && x[i] != ' '){
			lastPoint = i;
		}
		i++;
	}
}

void getLine(char s[], int maxLen){
	int i = 0;
	int c;
	while(i < maxLen && (c = getchar())!=EOF){
		s[i++] = c;
	}
	if(i == maxLen){
		s[maxLen-1] = '\0';
	}
	else{
		s[i] = '\0';
	}
}

int main(int argc, char ** argv){
	char s[MAX_LEN]; 
	getLine(s,MAX_LEN);

	trailEndingSpaceAndTab(s);
	printf("\n\n%s\n",s);
}