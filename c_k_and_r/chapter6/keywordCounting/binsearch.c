#include "const.h"

int binsearch(char * s, struct keyword *keywords, int max, int (*func)(char * a, char * b)){
	int left  = 0; 
	int right = max -1;
	while(left <= right){
		int middle = ( left + right) /2 ;
		int result  =func(s, keywords[middle].key);
		if(result == 0)
			return middle;
		else if ( result > 0)
			left = middle +1;
		else
			right = middle -1;
	}
	return -1;
}