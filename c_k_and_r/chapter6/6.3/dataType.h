#ifndef CONST
#define CONST
typedef enum{ END, NON_WORD, WORD} WordType;
typedef struct LineNum LineNum;

struct LineNum{
	int lineNum;
	LineNum * next; 
} ;

typedef struct TreeNode TreeNode;
struct TreeNode{
	char * word;
	LineNum * lineNum;
	TreeNode * left; 
	TreeNode * right;
};
#endif