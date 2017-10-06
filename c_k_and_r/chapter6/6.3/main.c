
#include "dataType.h"
#define MAX_WORD 100
#include <string.h>
#include <stdio.h>

TreeNode * talloc();
LineNum * lalloc();
int getLineNum();
WordType getword(char*, int);
TreeNode * addTreeNode(TreeNode *, char *, int);
void printTreeNode(TreeNode * tree);


int main(int argc, char ** argv){
	char str[MAX_WORD];
	int c;
	TreeNode * root = NULL;
	while(( c= getword(str,MAX_WORD)) != END ){
		 root= addTreeNode(root, str, getLineNum());
	}
	printTreeNode(root);


}

TreeNode *addTreeNode(TreeNode * node, char * s, int line){
	if(node == NULL){
		TreeNode * p = talloc();
		p-> word= strdup(s);
		LineNum * tmpLine = lalloc();
		tmpLine->lineNum = line;
		tmpLine-> next = NULL;
		p-> left = NULL;
		p-> right = NULL;
		p->lineNum = tmpLine;
		node = p;
	}
	else{
		int compare = strcmp(s, node->word);
		if(compare < 0){
			node->left =addTreeNode(node->left, s, line);
		}
		else if(compare > 0){
			node->right = addTreeNode(node->right, s, line);
		}else{
			LineNum * tmp = node->lineNum;
			while(tmp != NULL && tmp->next != NULL && tmp->lineNum != line){
				tmp = tmp->next;
			}
			if(tmp->lineNum != line && tmp->next == NULL){
				LineNum * x = lalloc();
				x->lineNum = line;
				x->next = NULL;
				tmp->next = x;
			}
		}
	}
	return node;
}

void printSingleNode(TreeNode * singleNode){
	if(singleNode != NULL){
		printf("%s: ", singleNode->word);
		LineNum * tmp = singleNode -> lineNum;
		while(tmp != NULL){
			printf("%d ", tmp->lineNum);
			tmp = tmp-> next;
		}
		printf("\n");
	}
}

void printTreeNode(TreeNode * tree){
	if(tree != NULL){
		printTreeNode(tree->left);
		printSingleNode(tree);
		printTreeNode(tree->right);
	}

}