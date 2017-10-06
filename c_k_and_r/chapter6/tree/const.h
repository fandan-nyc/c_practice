#ifndef CONST_H
#define CONST_H
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef  struct tnode {
	char * word;
	int count; 
	struct tnode * left; 
	struct tnode * right;
} tnode;
#endif