#include "parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

match_condition get_match_condition(int argc, char* argv[]){
	char** ptr = argv;
	for(int i = 0; i < argc; i++){
		if(strcmp(*ptr, "-o") == 0){
			return OR;
		}
		ptr++;
	}
	return AND;
}

int get_key_words_count(int argc, char* argv[]){
	check( (argc > 1), "need at least 1 arg for keyword");
	int count = 0;
	for(int i = 1; i < argc; i++){
		if(strcmp(argv[i], "-o") != 0){
			count++;
		}
	}
	check((count > 0), "need at least 1 key word to search" );
	return count;
error:
	exit(-1);
}

void get_key_words(int argc, char* argv[], char** keywords){
	check( (keywords != NULL), "failed to init keyword" );
	int count = 0;
	for(int i= 1; i < argc; i ++){
		if(strcmp(argv[i], "-o") != 0){
			keywords[count++] = argv[i];
		}
	}
	return;
error:
	debug("failed");
	exit(-1);
}
