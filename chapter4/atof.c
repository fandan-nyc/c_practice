#include <stdio.h> 

static double atof(char *);

int main(int argc, char ** argv){
	char* input = argv[1];
	printf("input is %s\n",input);
	printf("input to float: %5.5f\n",atof(input));
}

static double atof(char * input){
	int total = 0, power = 1;
	int signal = 1;
	if(*input == '-'){
		signal = -1;
	}
	while(*input != '.' && *input != '\0'){
		total = total * 10 + *input - '0';
		++input;
	}
	if(*input == '.'){
		++input;
		while(*input != '\0'){
			power *= 10;
			total = total * 10 + *input - '0';
			++input;
		}
	}
	return ((double) total) * signal / power;
}