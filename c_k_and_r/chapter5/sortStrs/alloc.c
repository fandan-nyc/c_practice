#include "header.h"

static char buf[MAX_BUF];
static char *bufLoc = buf ;
char * alloc(int size){
	if(bufLoc + size < buf + MAX_BUF){
		bufLoc += size ;
		return bufLoc - size ; 
	}else{
		return 0 ;
	}
}

void free(char * p){
	if(p >= buf && p < buf+ MAX_BUF){
		bufLoc = p ;
	}
}
