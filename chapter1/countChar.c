#include <stdio.h>

int main(){
	int charCount = 0;
	int lineCount = 0;
	int c;
	while((c=getchar())!=EOF){
		++charCount;
		if(c == '\n')
			++lineCount;
	}
	printf("number of chars: %d\n",charCount);
	printf("number of lines: %d\n",lineCount);

}