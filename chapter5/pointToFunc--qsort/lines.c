#include "libs.h"
#include "const.h"

static int readLine(char *, int maxChar);
static char tmp[MAX_CHAR_PER_LINE];
static void strCopy(char *, char *);
char * alloc(int);

void printLines(char ** x, int total){
	printf("\n print the following lines\n");
	for(int i = 0 ; i < total; i ++){
		printf("%s", *x++);
	}
}


int readLines(char ** x, int maxLines){
	int len ; 
	int counter = 0;
	while( (len = readLine(tmp, MAX_CHAR_PER_LINE)) > 0){
		char *p = alloc(len);
		strCopy(p, tmp);
		*x++ = p;
		++counter ;
	}
	return counter;
}

static int readLine(char * s, int max){
	int counter = 0; 
	int c;
	while(counter < max &&(s[counter++] = c = getchar()) != EOF && c != '\n')
		;
	if(c == EOF){
		return 0;
	}
	if(counter == max){
		printf("you have reached to your line size limit: %d\n",max);
		printf("any char besize the limit will get ignored\n");
		s[max-2] = '\n';
		s[max-1] = '\0';
		return max;
	}
	s[counter++] = '\0';
	return counter;
}

static void strCopy(char * a, char * b){
	while((*a++ = * b++))
		;
}