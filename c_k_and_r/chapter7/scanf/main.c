#include <stdio.h>

int main(int argc, char** argv){
	double v; 
	double sum = 0;
	while(scanf("%10lf", &v) == 1){
		sum += v;
		printf("the current sum is %10.3f, after adding %10.3f\n", sum, v);
	}
}