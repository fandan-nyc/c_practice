
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include "dataType.h"

TreeNode * talloc(); 
void push(TreeNode *);
TreeNode * pop();
int isEmpty();
void reset();

TreeNode * addTreeNode( TreeNode * p, char * s) {
	if(p == NULL){
		p = talloc();
		p->word = strdup(s);
		p->count = 1;
		p-> left = NULL;
		p-> right = NULL;
		return p;
	}
	else{
		int compare =  strcmp(s, p->word); 
		if(compare == 0){
			++(p->count);
		}else if(compare < 0){
			p->left = addTreeNode(p->left, s);
		}else{
			p-> right = addTreeNode(p->right, s);
		}
	}
	return p;
}



static TreeNode * addTreeNodeByCount( TreeNode * p, TreeNode * q) {
	int compare;
	if(p == NULL){
		p = talloc();
		p->word = q->word;
		p->count = q->count;
		p-> left = NULL;
		p-> right = NULL;
		return p;
	}
	else{
		compare =  q->count - p->count; 
		if(compare <= 0){
			p->left = addTreeNodeByCount(p->left, q);
		}else{
			p-> right = addTreeNodeByCount(p->right, q);
		}
	}
	return p;
}

TreeNode * talloc(){
	TreeNode * p =  malloc(sizeof (TreeNode));
	return p;
}

static void printSingleTreeNode(TreeNode * node){
	printf("%s shows up in %d times\n", node->word, node->count);
}

TreeNode * sortByCount(TreeNode *root){
	TreeNode * result;
	reset();
	push(root);
	while(!isEmpty()){
		TreeNode * curr = pop();
		if(curr-> left != NULL){
			push(curr->left);
		}
		if(curr-> right != NULL){
			push(curr->right);
		}
		result = addTreeNodeByCount(result, curr);
	}
	return result;
}


void printTreeNode(TreeNode * tnode){
	push(tnode);
	while(!isEmpty()){
		TreeNode * curr = pop();
		if(curr-> left != NULL){
			push(curr->left);
		}
		if(curr-> right != NULL){
			push(curr->right);
		}
		printSingleTreeNode(curr);
	}
}

void printTreeNodeTraversal(TreeNode * tnode){
	if(tnode == NULL){
		return;
	}else{
		printTreeNodeTraversal(tnode->left);
		printSingleTreeNode(tnode);
		printTreeNodeTraversal(tnode->right);
	}
}







