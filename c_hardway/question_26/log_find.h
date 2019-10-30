#include <stdio.h>
#ifndef __log_find_h__
#define __log_find_h__

const extern int MAX_LINE_LEN;
const extern int MAX_LINES;

typedef int (*match_words)(char** key_words, int key_word_count, char* line);
int match_and(char** key_words, int key_word_count, char* line);
int match_or(char** key_words, int key_word_count, char* line);

int find_word(char* target[], int target_count, char* source, match_words match_words_func);
void read_line(char* dest, FILE * source);

#endif
