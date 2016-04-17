// reserve polish calculator 
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_OP 100
static const int NUMBER = '0';
static float stack[MAX_OP];
static float * stackP = stack;

static int store[MAX_OP];
char getOp(char * s);
void push(float input);
float pop();

int main(int argc, char ** argv){
	if(argc < 4){
		printf("usage: ./a.out 4 5 +");
	}
	float tmp ;
	while(--argc > 0){
		switch(getOp(*++argv)){
			case NUMBER:
				push(atof(*argv));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				tmp = pop();
				push(pop() - tmp);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				tmp = pop();
				if(tmp == 0 ){
					printf("error: 0 divisor.");
					return -1;
				}
				push(pop() / tmp);
				break;
			default:
				printf("unknown operator: %s\n",*argv);
				break;
		}
	}
	printf("the result is: %5.5f\n",pop());

}


// this does not consider all corner cases
char getOp(char * s){
	int c;
	if(isdigit(s[0]) ){
		return NUMBER;
	}else{
		return s[0];
	}
}

void push(float input){
	if(stack >= stack + MAX_OP){
		printf("the stack is full.\n");
		return ;
	}
	*stackP++ = input ;
}

float pop(){
	if( --stackP >= stack){
		return *stackP;
	}
	else{
		printf("the stack is empty");
		return 0.0;
	}
}