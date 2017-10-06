#include "libs.h"

static char maybeToLower(char, int);

int strcmpByChar(char * x, char *y, int useFold){
	while(*x != '\0' && *y != '\0' && (maybeToLower(*x, useFold) == maybeToLower(*y, useFold))){
		++x;
		++y;
	}
		;
	return maybeToLower(*x, useFold) - maybeToLower(*y, useFold);
}

// for the benefit of practicing the pointer to func, 
// we just convert the str to long and anything overflow get ignored
int strcmpByNum(char *x, char *y, int useFold){
	long xNum = atol(x);
	long yNum = atol(y);
	return xNum - yNum;
}

static char maybeToLower(char p, int useFold){
	if(useFold){
		 char x = (p>= 'A' && p<= 'Z') ? (p-'A'+ 'a') : p;
		 return x;
	}
	return p;
}