#include <stdio.h>

#define SWAP(t,x,y)  t tmp = x; x = y; y = tmp;
#define SWAP_1(t,x,y)  do{t tmp = x; x = y; y = tmp;}while(0)



int main(){
	int a = 1;
	int b = 3;
	SWAP(int, a,b);
	printf("a %d\n",a);
	printf("b %d\n",b);
}