#include <stdio.h> 
#include <stdlib.h>

static char * itob(int,int, char*);
static char itoc(int);
static void reverse(char *);

int main(int argc, char ** argv){
	int input = atoi(argv[1]);
	int b = atoi(argv[2]);
	char result[32];
	itob(input, b,result);
	printf("the input is %d\n",input);
	printf("the b is %d\n",b);
	printf("converted num is %s\n", result);

}

static char * itob(int x, int b, char result[]){
	int i = 0;
	while(x != 0){
		result[i++] = itoc(x % b);
		x /= b;
	}
	if(x < 0){
		result[i++]='-';
	}
	result[i] = '\0';
	reverse(result);
	return result;
}

static char itoc(int x){
	if(x < 10){
		return x + '0';
	}
	else{
		return 'A' + x - 10;
	}
}

static void reverse(char input[]){
	int i = 0;
	int counter  = 0;
	while(input[counter++] != '\0'){
		;
	}
	int low =0, high = counter -2;
	while(low < high){
		char tmp = input[low];
		input[low] = input[high];
		input[high] = tmp;
		++low;
		--high;
	}
	input[counter-1] ='\0';
}