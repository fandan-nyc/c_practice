#include "libs.h"
#include "const.h"

int readLines(char **,int);
void printLines( char **, int);
void quicksort(void * , int, int, int (*func)(void *, void *, int),int,int);
int strcmpByChar( char *, char *);
int strcmpByNum( char *, char *);


int main(int argc, char ** argv){
	int useNum = 0 ; 
	int useReverse = 0;
	int useFold = 0;
	int useDict = 0;
	while( --argc > 0 && argv[argc][0] == '-'){
		char c ; 
		while((c = *++argv[argc])){
			switch(c){
				case 'n':
					useNum = 1 ;
					break;
				case 'r':
					useReverse = 1 ;
					break;
				case 'f':
					useFold = 1;
					break;
				default:
					printf("unknow operator: %c get ignored\n", c);
					break;
			}
		}
	}
	char *store[MAX_LINE];
	int numOfLines  = readLines(store,MAX_LINE);
	printLines(store, numOfLines);
	printf("useFold: %d",useFold);
	quicksort(store, 0, numOfLines-1, (int (*)(void *, void *, int))(useNum ? strcmpByNum: strcmpByChar),useReverse, useFold);
	printLines(store, numOfLines);
	return 0;
}




