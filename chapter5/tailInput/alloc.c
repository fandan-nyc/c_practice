#include "const.h"


static const int totalSize = MAX_LINE * MAX_CHAR_PER_LINE; 
static char store[totalSize];
static char * p = store;

char * alloc(int size){
	if(p + size < store + totalSize){
		p += size;
		return p-size;
	}
	else{
		printf("the stack is full\n");
		return 0;
	}
}

void freeM(char * x){
	if( x > store && x < store + totalSize){
		p = x;
	}
}