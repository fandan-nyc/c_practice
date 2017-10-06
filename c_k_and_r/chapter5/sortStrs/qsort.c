#include "header.h"


void swap(char ** , int, int);
int strCmp(char *, char*);
void qsort(char ** input, int left, int right){
	if(left >= right){
		return ;
	}
	int middle = ( left + right ) / 2;
	swap(input, left, middle);
	int last = left;
	for(int i = left+1; i <= right; i ++){
		if(strCmp(input[i],input[left]) < 0){
			swap(input, ++last, i);
		}
	}
	swap(input, left, last);
	qsort(input, left, last-1);
	qsort(input, last+1, right);
}

void swap(char ** x, int i, int j){
	char * tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

int strCmp(char * a, char * b){
	while( *a != '\0' && *b != '0' && *a == *b){
		++a;
		++b;
	}
	return *a - *b;
}