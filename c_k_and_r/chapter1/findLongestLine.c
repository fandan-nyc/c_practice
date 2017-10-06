#include <stdio.h> 
#define MAX_LEN 100

int getLine(char s[], int maxLen){
	int i = 0;
	int c; 
	while((c=getchar()) != EOF && c !='\n' && i < maxLen){
		s[i++] = c;
	}
	if(c == '\n'){
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}

void copyStr(char from[], char to[]){
	int i = 0; 
	while((to[i] = from[i]) != '\0'){
		++i;
	}
}

int main(int argc, char ** argv){
	int max = 0; 
	int len; 
	char str[MAX_LEN];
	char longest[MAX_LEN];
	while((len = getLine(str, MAX_LEN)) > 0){
		if(len > max){
			max = len;
			copyStr(str,longest);
		}
	}
	if(max > 0){
		printf("the longest str is \n");
		printf("%s\n", longest );
	}
}