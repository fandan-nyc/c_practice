#include "headers.h"

int getop(char[]);
void push(double);
double pop(void);

int main(int argc, char ** argv){
	int type;
	double op2;
	char s[MAXOP];
	double x ; 

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				x = pop();
				if(x != 0.0)
					push(pop() / x);
				else
					printf("error: zero divisor\n");
				break;
			case '-':
				x = pop();
				push(pop() - x);
				break;
			case '\n':
				printf("\t%.8f\n",pop());
				break;
			default:
				printf("error: unknown command %s\n",s);
				break;
		}
	}
	return 0;
}