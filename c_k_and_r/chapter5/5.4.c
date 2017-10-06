#include <stdio.h>

int strend(char *,char*);

int main(int argc, char ** argv){
	char * a  = argv[1];
	char * b  = argv[2];
	int x =strend(a,b);
	if(x == 0 ){
		printf("a does not end with b\n");
	} else if(x == 1){
		printf("a ends with b\n");
	}
	else{
		printf("error: not sure what is going on with siganl %d\n",x );
	}
}

int strend(char *s, char *t){
	char * p = s;
	char * q = t;
	int pLen = 0;
	int qLen  = 0 ;
	while(*p){
		++p;
		++ pLen ;
	}
	while(*q){
		++q;
		++ qLen;
	}
	if(pLen < qLen){
		return 0;
	}
	s += (pLen - qLen) ;
	while( *s != '\0' && *s == *t){
		++s;
		++t;
	}
	if(*s == '\0'){
		return 1;
	}
	return 0;
}