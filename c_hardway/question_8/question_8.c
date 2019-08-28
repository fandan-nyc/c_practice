#include <stdio.h>

int main(int argc, char* argv[]){
    int i = 0 ;
    if (argc == 1){
        printf("you have only one arg. stop here\n");
    } else if (argc > 1 && argc < 4){
	printf("here are the args you have\n");
	for (int i = 0; i < argc; i ++){
	    printf("arg %d: %s\n", i, argv[i]);
	}
    } else{
	printf("too many args\n");
    }
}
