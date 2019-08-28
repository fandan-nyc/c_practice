#include<stdio.h>

int main(int argc, char* argv[]){
	if (argc != 2){
		printf("error: you need one arg\n");
		return 1;
	}
	for(int i = 0; argv[1][i] != '\0'; i ++){
		char letter = argv[1][i];
		switch(letter){
			case 'a':
			case 'A':
				printf("%c is a vowel.\n", letter);
				break;
			default:
				printf("just a normal letter %c\n", letter);
		}
	}
	return 0;
}

/*dfan-mbp143:question_10 dfan$ ./question_10 "Dan FAN"
just a normal letter D
a is a vowel.
just a normal letter n
just a normal letter
just a normal letter F
A is a vowel.
just a normal letter N
dfan-mbp143:question_10 dfan$ ./question_10 Dan FAN
error: you need one arg
dfan-mbp143:question_10 dfan$ ./question_10 zzz
just a normal letter z
just a normal letter z
just a normal letter z
*/
