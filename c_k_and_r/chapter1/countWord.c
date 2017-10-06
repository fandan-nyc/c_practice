#include <stdio.h> 
#define IN  0
#define OUT 1

int main(){
	int c;
	int status = OUT;
	int wordCount = 0;
	while((c=getchar())!= EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			status = OUT;
		}
		else if(status == OUT){
			++wordCount;
			status = IN;
		}
	}
	printf("we have %d words in total\n",wordCount);
}