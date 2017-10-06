
#include "header.h"
static const int MAX_ELE = 100;
static double s[MAX_ELE];
static int counter = 0;
void push(double x){
	if(counter >= MAX_ELE){
		printf("error: double stack is full");
	}
	else{
		s[counter++] = x;
	}
}

double pop(){
	if(counter == 0){
		printf("error: double stack is empty");
		return 0.0;
	}
	else{
		return s[--counter];
	}
}