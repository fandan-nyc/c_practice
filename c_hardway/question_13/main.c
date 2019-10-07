#include <stdio.h>

int main(int argc, char* argv[]){
	for (int i = 1; i < argc; i ++){
		printf("%s\n", argv[i]);
	}
	char* values[] = {"new york", "washington", "boston"};
	for(int i = 0; i < 3; i ++){
		printf("%s, ",values[i]);
	}
	return 0;
}
