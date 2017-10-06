#include "dataType.h"
#include <stdio.h>
#define ARR_MAX 100
static int counter = -1 ;
static TreeNode * store[ARR_MAX];


void push(TreeNode *p){
	if(counter < ARR_MAX-1){
		store[++counter] = p;
	}
	else{
		printf("error: stack is full\n");
	}
}

TreeNode * pop(){
	if(counter < 0 ){
		printf("error: stack is full\n");
		return NULL;
	}
	return store[counter--];
}

int isEmpty(){
	return counter < 0;
}

void reset(){
	counter = -1;
}
