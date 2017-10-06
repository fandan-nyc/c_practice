#include <stdio.h> 

// print lines longer than 10
#define MAX_LEN 100 
#define MAX_TOTAL 1000

int getLine(char s[], int maxLen){
	int i = 0; 
	int c ; 
	while((c=getchar())!= EOF && c != '\n' && i < maxLen){
		s[i++] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int copyStr(char input[], char output[], int start){
	int i = 0; 
	while(i+start < MAX_TOTAL && (output[i+start] = input[i]) !='\0'){
		i++;
	}
	return start + i;
}

int main(int argc, char ** argv){
	char output[MAX_TOTAL];
	char s[MAX_LEN];
	int len= 0;
	int start =0;
	while((len = getLine(s, MAX_LEN)) > 0){
		if(len >= 10){
			start  = copyStr(s, output,start);
		}
	}
	printf("print all lines whose length > 10\n");
	printf("%s",output);
}