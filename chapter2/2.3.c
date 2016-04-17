#include <stdio.h>


static int htoi(char *);
static int charToi(char x);

int main(int argc, char **argv){
	printf("the number of inputs: %d\n",argc);
	char *input = argv[1];
	printf("hex is %s\n", input);
	printf("corresponding int is %d\n", htoi(input));
}

static int htoi(char *x){
	// assume that the input is valid htoi
	if(*x == '0' && ( *(x+1) == 'X' || *(x+1)== 'x')){
		x+= 2;
	}
	int result  = 0;
	while( *x != '\0'){
		result = result * 16 + charToi(*x);
		++x;
	}
	return result;
}

static int charToi(char x){
	if(x >= 'A'  && x  <= 'Z'){
		return x - 'A';
	}
	else if(x >='a' && x <= 'z'){
		return x-'a';
	}
	else if(x >= '0' && x <= '9'){
		return x - '0';
	}
	return 0;
} 
