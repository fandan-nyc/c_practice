#include <stdio.h> 

char toLower(char);
int main(int argc, char ** argv){
	char x = argv[1][0];
	printf("to lower x: %c\n", toLower(x));
}

char toLower(char x){
	return (x>= 'A' && x <='Z') ? (x-'A' + 'a') : x;
}