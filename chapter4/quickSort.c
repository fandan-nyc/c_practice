#include <stdio.h>

void qsort(int[], int, int);

int main(int argc, char ** argv){
	int v[] ={9,8,3,6,5,4,7,2,1,10};
	printf("original array: ");
	for(int i = 0; i < 10; i++){
		printf(" %d",v[i]);
	}
	printf("\n"); 
	qsort(v, 0,9);
    printf("sorted array: ");
	for(int i = 0; i < 10; i++){
		printf(" %d",v[i]);
	}
}

void qsort(int input[], int start, int end){
	if(start >= end){
		return;
	}
	int i = start+1, last  = start;
	void swap(int[], int, int);
	swap(input, start, (start + end)/2);
	for(; i <= end; i++){
		if(input[i]< input[start]){
				swap(input, ++last, i);
		}
	}
	swap(input, last, start);
	qsort(input, start, last-1);
	qsort(input, last+1, end);
}

void swap(int input[], int i, int j){
	int tmp = input[i];
	input[i] = input[j];
	input[j] = tmp ;
}