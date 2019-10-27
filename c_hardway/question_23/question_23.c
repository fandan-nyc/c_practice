#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char* to, int count){
	int i = 0;
	for(i = 0; i < count; i++){
		to[i] = from[i];
	}
	return i;
}

int duffs_device(char* from, char* to, int count){
	{
		int n = (count +7)/8;
		switch(count%8){
			case 0:
				do{
					*to++ = *from++;
					case 7:
					*to++=*from++;
					case 6:
					*to++=*from++;
					case 5:
					*to++=*from++;
					case 4:
					*to++=*from++;
					case 3:
					*to++=*from++;
					case 2:
					*to++=*from++;
					case 1:
					*to++=*from++;
				}while (--n > 0);
		}
	}
}

int DanDevice(char* from, char* to, int count){
	{
		int n = (count +7) / 8;
		switch(count %8) {
			case 0:
again:				*to++ = *from++;
			case 7:
				*to++ = *from++;
			case 6:
				*to++ = *from++;
			case 5:
				*to++ = *from++;
			case 4:
				*to++ = *from++;
			case 3:
				*to++ = *from++;
			case 2:
				*to++ = *from++;
			case 1:
				*to++ = *from++;
				if( --n > 0 ){
					goto again;
				}
		}
	}
}

int main(int argc, char* argv[]){
	char from[10] = "abcdefg";
	char to[10] = "zzzzzzz";
	normal_copy(from, to, 10);
	memset(to, 99, 9);
	debug("%s", to);
	duffs_device(from, to, 10);
	memset(to, 99, 9);
	DanDevice(from, to, 10);

	debug("%s", from);
	debug("%s", to);
}
