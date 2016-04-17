
#include <string.h> 
#include "const.h"

struct keyword * binsearch(char * s, struct keyword *keyWord, int size){
	struct keyword *low = &keyWord[0];
	struct keyword *high = &keyWord[size-1];
	struct keyword  * middle;
	while(low <= high){
		middle = low + (high-low) /2 ;
		int compare = strcmp(s, middle->key);
		if( compare == 0){
			return middle;
		}else if(compare > 0){
			low = middle+1;
		}else{
			high = middle -1;
		}
	}
	return NULL;
}