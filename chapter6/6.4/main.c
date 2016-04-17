#include <ctype.h>
#include <stdio.h>
#include "dataType.h"

#define MAX 100
char getword(char *,int);
TreeNode * addTreeNode( TreeNode * p, char * s);
void printTreeNode(TreeNode * tnode);
TreeNode * sortByCount(TreeNode *root);
void printTreeNodeTraversal(TreeNode *);

int main(int argc, char ** argv){
	char s[MAX];
	char c ;
	TreeNode *p = NULL;
	while((c = getword(s, MAX)) != EOF){
		if( isalpha(c)){
			p = addTreeNode( p, s);
		}
	}
	printTreeNode(p);
	printf("\n\n after sort: \n\n");
	TreeNode * new  = sortByCount(p);
	printTreeNodeTraversal(new);
}