#include "const.h"
#define MAX_CHAR 100
#define SIZE (sizeof keyWord)/(sizeof(struct keyword))

struct keyword * binsearch(char *, struct keyword *, int);
char getword(char *, int);


struct keyword keyWord[] = {{"apple",0},{"boy",0},{"cat",0}};

int main(int argc, char ** argv){
	char x[MAX_CHAR];
	int c ; 
	while( (c = getword(x, MAX_CHAR)) !=EOF){
		if(isalpha(c)){
			struct keyword * p = binsearch(x, keyWord, SIZE);
			if(p != NULL){
				++ (p-> count);
			}
		}
	}
	struct keyword * keyP = keyWord;
	for(; keyP < keyWord + SIZE ; ++keyP){
		if( keyP->count >=0){
			printf("the %s has shown up %d times\n", keyP->key, keyP->count);
		}
	}
}