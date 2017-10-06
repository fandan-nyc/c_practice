#include "header.h"
static char s[MAX_LEN];
int getop(char s[]);
void push(double);
double pop(void);

int main(int argc, char ** argv){
	int c ; 
	while((c = getop(s)) != EOF){
		double x; 
		switch(c){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				x = pop();
				push(pop() / x);
				break;
			case '-':
				x = pop();
				push(pop() - x);
				break;
			case '\n':
				printf("    the result is %.8g\n",pop());
				break;
			default:
				printf("error: the op %c is unknown.\n", c);
				break;
		}
	}
}