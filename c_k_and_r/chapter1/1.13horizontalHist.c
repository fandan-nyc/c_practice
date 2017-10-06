#include <stdio.h> 
#define IN 1
#define OUT 0

int main(){
	int c ;
	int status = OUT;
	while((c=getchar())!= EOF){
		if(c == ' '|| c == '\t' || c == '\n'){
			if(status == IN)
				putchar('\n');
			status = OUT;
		}
		else{
			status = IN;
			putchar('*');
		}
	}
}