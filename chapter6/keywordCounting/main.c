#include "const.h"
#include <ctype.h>

#define KEYWORD_SIZE  (sizeof keyWordCount)/(sizeof (struct keyword))

static struct keyword keyWordCount[] ={
	"apple",0,
	"boy",0,
	"cat",0,
};
char getword(char *, int);
int binsearch(char * s, struct keyword *keywords, int max, int (*func)(char * a, char * b));
int strCmp(char *, char *);

int main(int argc, char ** argv){
	char x[MAX_CHAR];
	char c ;
	int loc ;
	while((c = getword(x, MAX_CHAR)) != EOF) {
		 if(isalpha(c)){
		 	loc = binsearch(x, keyWordCount, KEYWORD_SIZE, strCmp);
		 	if(loc >=0){
		 		++keyWordCount[loc].count;
		 	}
		 }
	}
	for(int i  = 0; i < KEYWORD_SIZE; i++){
		if(keyWordCount[i].count>0){
			printf("the %s has shown up %d times\n", keyWordCount[i].key, keyWordCount[i].count);
		}
	}
}

