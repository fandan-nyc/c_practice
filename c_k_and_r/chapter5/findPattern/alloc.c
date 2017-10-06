#include "constants.h"

char store[MAX_LINE * MAX_CHAR_PER_LINE];
char * p = store;

char * alloc(int size){
	if(store + MAX_LINE * MAX_CHAR_PER_LINE > p + size){
		p += size;
		return p-size;
	}
	printf("the stack is full\n");
	return 0; 
}

void free(char *x){
	if(p > store && p < store + MAX_CHAR_PER_LINE * MAX_LINE){
		p = x;
	}
}