#include <stdio.h> 

int strrindex(char *, char *);

int main(int argc, char ** argv){
	char * input = argv[1];
	char * dict = argv[2];
	printf("input %s\n",input);
	printf("dict %s\n", dict);
	int x = strrindex(input, dict);
	printf("strrindex %d\n", x);
}

int strrindex(char *s, char *t){
	int position = -1; 
	int i = 0;
	while(s[i] != '\0'){
		int k = 0; 
		for(int j = i; s[j] !='\0' && t[k] != '\0' && s[j] == t[k];++j, ++k){
			;
		}
		if(t[k] == '\0'){
			position = i;
		}
		i++;
	}
	return position;
}