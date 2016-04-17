#include <stdio.h> 

#define MAX_LEN 100

void reverse(char x[], int length){
	int i = 0; 
	int start = 0; 
	int end = length-1;
	while(start < end){
		char tmpStart = x[start];
		x[start] = x[end];
		x[end] = tmpStart;
		++start;
		--end;
	}

}

int getLine(char s[], int max_len){
	int  i = 0; 
	int c;
	while(i < max_len && (c=getchar())!= EOF){
		s[i++] = c;
	}
	s[i]= '\0';
	return i;
}

int main(int argc, char ** argv){
	char x[MAX_LEN];
	int len = getLine(x,MAX_LEN);
	printf("before reverse\n");
	printf("%s\n", x);
	reverse(x,len);
	printf("after reverse\n");
	printf("%s\n", x);
}

