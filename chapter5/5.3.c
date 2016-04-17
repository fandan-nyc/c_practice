#include <stdio.h>
#undef strcat
#undef strcp

char * strcat(char *, const char *);

int main(int argc, char ** argv){
	char *s = argv[1];
	char *t = argv[2];
	printf("the first input: %s\n",s);
	printf("the second  input: %s\n", t);
	char *  p = strcat(s,t);
	printf("after cat, %s\n", p);

}

void strcp(char *s,const char *t){
	while( (*s++ = *t++))
		;
}

char * strcat(char *s, const char *t){
	char * p  = s ;
	while(*s){
		++s;
	}
	strcp(s, t);
	return  p;
}