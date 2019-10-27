#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug(){
	debug("ihave brown hair");
	debug("i am %d years old", 37);
}

void test_error(){
	log_err("aaa");
	log_err("name %s age %d", "zack", 199);
}

int test_check(char* file_name){
	FILE * input = NULL;
	char * block = NULL;

	block = malloc(100);
	check_mem(block);

	input = fopen(file_name, "r");
	check(input, "failed to open %s", file_name);

	free(block);
	fclose(input);

	return 0;

error:
	if(block) free(block);
	if(input) fclose(input);
	return -1;

}

int main(int argc, char* argv[]){
	test_debug();
	test_error();
	test_check("aa.txt");
}
