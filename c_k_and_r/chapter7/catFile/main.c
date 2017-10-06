
#include <stdio.h>
void copyFile(FILE * input, FILE *output);

int main(int argc, char ** argv){
	
	if(argc == 0){
		copyFile(stdin, stdout);
	}else{
		FILE * file;
		while( --argc >0){
			if((file = fopen( * ++argv,"r")) == NULL){
				printf("the file %s cannot be open.\n",*argv);
				return 2;
			}
			else{
				copyFile(file, stdout);
				fclose(file);
			}
		}
	}
	return 0;

}

void copyFile(FILE * input, FILE *output){
	int c;
	while( (c=getc(input)) != EOF){
		putc(c,output);
	}
}