#include <stdio.h>
 
int atoiRecur(char *, int);

int main(int argc, char ** argv){
	char *x = argv[1];
	printf("the input is %s",x);
	printf("the integer is %d",atoiRecur(x,0));
}

int atoiRecur(char * x, int total){
	if(*x == '\0' ){
		return total;
	}else{
		total = total * 10 + (*x - '0') ; 
		return atoiRecur(++x, total); 
	}
}