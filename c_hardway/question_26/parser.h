#ifndef __parser_h__
#define __parser_h__

typedef enum match_condition {AND, OR} match_condition;


match_condition get_match_condition(int argc, char* argv[]);
void get_key_words(int argc, char* argv[], char** keywords);
int get_key_words_count(int argc, char* argv[]);
#endif
