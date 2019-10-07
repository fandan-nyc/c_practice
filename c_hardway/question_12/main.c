#include <stdio.h>

int main(int argc, char* argv[]){
	int areas[] = {1,2,3,4};
	char name[] = {'a', 'b', 'c', '\0'};
	char another[] = "abc";
	printf("the size of int is %ld\n", sizeof(int));
	printf("the size of char is %ld\n", sizeof(char));
	printf("the size of double is %ld\n", sizeof(double));
	printf("length of areas is %ld\n", sizeof(areas)/sizeof(int));

	return 0;

}
