#ifndef DATA_TYPE_H
#define DATA_TYPE_H
typedef struct TreeNode TreeNode;

struct TreeNode {
	char * word; 
	int count;
	TreeNode * left; 
	TreeNode * right;
};
#endif

