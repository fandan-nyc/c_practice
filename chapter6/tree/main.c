#include "const.h"

void treePrint( tnode * tree);
tnode * addNode( tnode *, char *);

char getword(char *, int);
int main(int argc, char ** argv){
	char x[MAX_SIZE];
	int c ;
	tnode * root = NULL;
	while((c = getword(x, MAX_SIZE)) !=EOF){
		if(isalpha(c)){
			root = addNode(root, x);
		}
	}
	printf("\nthe tree looks like: \n");
	treePrint(root);
}