#include "const.h"
#include "libs.h"


static char store[MAX_LINE * MAX_CHAR_PER_LINE];
static char *p  = store ;


char * alloc(int size){
	if(p + size < store + MAX_LINE * MAX_CHAR_PER_LINE){
		p += size ; 
		return p - size;
	}
	printf("error: full stack, cannot alloct memory\n");
	return  0 ;
}

void freeM(char * x){
	if(x >= store && x < store + MAX_CHAR_PER_LINE * MAX_LINE)
		p = x ;
}