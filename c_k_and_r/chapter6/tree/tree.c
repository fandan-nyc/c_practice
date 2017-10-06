#include "const.h"

 tnode * talloc();

void treePrint( tnode * tree){
	if(tree != NULL){
		treePrint(tree -> left);
		printf("%s shows up %d times.\n", tree->word, tree->count);
		treePrint(tree -> right);
	}
}

 tnode * addNode( tnode * x, char * input){
 	if(x == NULL){
 		x = talloc();
 		x -> word = strdup(input); 
 		x -> count = 1; 
 		x ->left = NULL; 
 		x -> right = NULL;
 	}else{
 		int result = strcmp(x->word, input);
 		if(result == 0){
			++(x->count);
	 	}else if(result > 0){
 			x->left = addNode(x->left, input);
 		}else{
 			x->right = addNode(x->right, input);
 		}
 	}
 	return x;
}

 tnode *talloc(void){
 	return ( tnode *) malloc(sizeof(tnode));
}