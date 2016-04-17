#include "dataType.h"
#include <stdlib.h>

TreeNode * talloc(){
	return malloc(sizeof(TreeNode));
}

LineNum * lalloc(){
	return malloc(sizeof(LineNum));
}