#include <stdio.h> 

char* expand(char*, char*);

int main(int argc, char ** argv){
	char *s1 = argv[1];
	char s2[100];
	expand(s1, s2);
	printf("\n the expanded str is %s\n", s2);
}

char* expand(char * s1, char * s2){
	if(*s1 != '-'){
		*(s2++) = *s1;
	}
	++s1;
	while(*s1 != '\0' ){
		if(*s1 == '-' && *(s1+1) == '\0'){
			break;
		}
		else if(*s1 == '-'){
			for(int i = *(s1-1) + 1; i <= *(s1+1);i++){
				*(s2++) = (char)i;
			}
			s1+=2;
		}
		else{
			*(s2++) = *(s1++);
		}
	}
	*s2 = '\0';
	return s2;
}