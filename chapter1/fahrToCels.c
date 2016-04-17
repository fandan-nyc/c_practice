#include <stdio.h>

#define LOW 0 
#define HIGH 300

int main(){
	int fahr ;
	float celsius;  
	int step; 

	step = 20; 
	fahr = LOW ; 
	while(fahr < HIGH){
		celsius = 5 * ( fahr - 32.0) / 9.0;
		printf("%3d\t%6.8f\n",fahr, celsius);
		//printf("%d\t%d\n",fahr, celsius);
		fahr += step;
	}
}