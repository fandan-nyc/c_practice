#include <stdio.h>

void swap(char *x, int i, int j);
void reverse(char *, int, int );

int main(int argc, char ** argv){
	char *x = argv[1];
	printf("original input %s\n",x);
	int i = 0 ;
	char *p  = x;
	while(*p != '\0'){
		++i;
		++p;
	}
	reverse(x, 0,i-1);
	printf("reversed input %s\n",x);
}

void reverse(char *x, int start, int end){
	if(start < end){
		swap(x, start, end);
		reverse(x, start+1, end-1);
	}
}

void swap(char *x, int i, int j){
	int tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

