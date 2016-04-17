#include <stdio.h> 

int main(){
	int c; 
	char tmp = EOF;
	while((c=getchar())!= EOF){
		if(c != ' ' || tmp != ' '){
			putchar(c);
			tmp = c;
		}
	}
}