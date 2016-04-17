#include <stdio.h> 

static void squeeze(char *, char *);

int main(int argc, char **argv){
	printf("delete chars in x which also exits in y\n");
	printf("x: %s\n",argv[1]);
	printf("y: %s\n",argv[2]);
	squeeze(argv[1], argv[2]);
	printf("after squeeze\n");
	printf("%s\n",argv[1]);
}

void squeeze(char * x, char * y){
	char * w =  x;
	while(*w != '\0'){
		char * z = y;
		while( *z != '\0' && *z != *w){
			++z;
		}
		if(*z == '\0'){
			*(x++) = *(w++);
		}
		else{
			*x = *(++w);
		}
	}
	*x = *w;
}