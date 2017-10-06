#include "headers.h"


int sp = 0;
double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full");
}

double pop(){
	if(sp >0)
		return val[--sp];
	else{
		printf("error: empty stack\n");
		return 0.0;
	}
}