#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXWR 100


int main(){
	int hist[MAXWR];
	int c ;
	int status = OUT;
	int word = 0;
	for(int i=0; i<MAXWR; ++i)
        hist[i]=0;
	while((c=getchar())!= EOF){
		if(c == ' '|| c == '\n' || c == '\t'){
			if(status == IN){
				++word;
			}
			status = OUT;
		}
		else{
			hist[word] += 1;
			status= IN;
		}
	}
	int max = 0; 
	for(int i = 0; i < sizeof(hist) / sizeof(hist[0]);i++){
		if(max < hist[i]){
			max = hist[i];
		}
	}
	while(max > 0){
		for(int i = 0; i < sizeof(hist) / sizeof(hist[0]); i++){
			if(hist[i] >= max){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		--max; 
		printf("\n");
	}
}