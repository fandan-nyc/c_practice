#include<stdio.h>
#include "dbg.h"
#include "log_find.h"
#include "parser.h"
#include <stdlib.h>


int main(int argc, char* argv[]){
	match_condition mc = get_match_condition(argc, argv);
	int keywords_count = get_key_words_count(argc, argv);
	// each keyword is no larger than MAX_LINE_KEN
	char* keywords[keywords_count];
	get_key_words(argc, argv, keywords);
	match_words match_words_func = NULL;
	if(mc == AND){
		match_words_func = match_and;
	}else{
		match_words_func = match_or;
	}
	FILE* file = fopen("sample.txt", "r+");
	check(file, "cannot find file");
	char* line_ptr = malloc(MAX_LINE_LEN);
	char* file_prt= fgets(line_ptr, MAX_LINE_LEN, file);
	while(file_prt != NULL){
		int tmp = find_word(keywords, keywords_count, line_ptr, match_words_func);
		if(tmp){
			log_info("%s",line_ptr);
		}
		file_prt= fgets(line_ptr, MAX_LINE_LEN, file);
	}
	return 0;
error:
	if(file) fclose(file);
	return 0;
}
