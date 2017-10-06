#include <stdio.h>

static int getFirstCharInDic(char*, char*);

int main(int argc, char ** argv){
	printf("get the first apperance of char in the input, which shows in the dict also\n");
	printf("the input: %s\n", argv[1]);
	printf("the dict: %s\n", argv[2]);
	printf("the first loc: %d\n",getFirstCharInDic(argv[1], argv[2]));
}

int getFirstCharInDic(char * input, char * dict){
	int counter = 0;
	while( *input != '\0'){
		char * z= dict;
		while( *z != '\0'){
			if(*input == *z){
				return counter;
			}
			else{
				++z;
			}
		}
		++counter;
		++input;
	}
	return -1;
}