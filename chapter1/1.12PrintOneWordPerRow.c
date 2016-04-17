#include <stdio.h> 

#define IN 0
#define OUT 1

int main(){
	int c; 
	int status = OUT;
	while((c=getchar())!= EOF){
		if(c  == ' '|| c == '\t' || c == '\n'){
			if(status == IN){
				putchar('\n');
			}
			status = OUT;
		}
		else{
			status = IN;
			putchar(c);
		}
	}
}