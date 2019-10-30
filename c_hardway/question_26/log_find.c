#include "log_find.h"
#include "dbg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int MAX_LINE_LEN = 1024;
const int MAX_LINES = 10;

int get_len(char* word){
	if(word == NULL){
		return -1;
	}
	int count = 0; 
	while(*word++ != '\0'){
		count++;
	}
	return count;
}

int str_compare(char* keyword, char* source, int len){
	for(int i = 0; i < len; i++){
		if(keyword[i] != source[i]){
			return -1;
		}
	}
	return 1;
}


int has_match(char* keyword, char* target){
	char* target_ptr = target;
	int target_len = get_len(target_ptr);
	int keyword_len = get_len(keyword);
	if(target_len < keyword_len) return -1;
	for(int i = 0; i <= target_len - keyword_len; i++){
		if(str_compare(keyword, target_ptr, keyword_len) == 1){
			return 1;
		}
		target_ptr++;
	}
	return -1;
}


int  match_and(char** key_words, int key_word_count, char* line){
	int res = 0;
	int i = 0;
	while(i < key_word_count){
		res += (has_match(key_words[i], line) == 1) ? 1 : 0;
		i++;
	}
	return (res == key_word_count ) ? 1 : 0;
}


int match_or(char** key_words, int key_word_count, char* line){
	int res = 0;
	int i = 0;
	while(i < key_word_count){
		if(has_match(key_words[i], line) == 1) return 1;
		i++;
	}
	return 0;
}

int find_word(char* targets[], int target_count, char* source, match_words match_words_func){
	return match_words_func(targets, target_count, source);
}

void read_line(char* dest, FILE * source){
	char* i = fgets(dest, MAX_LINE_LEN, source);
	check(i != NULL, "fail to read line from source");
error:
	if (dest) free(dest);
	if (source) fclose(source);
}
