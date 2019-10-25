#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *msg){
	if(errno){
		perror(msg);
	}else{
		printf("error: %s", msg);
	}
	exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef void (*swap_func)(int* target, int i, int j);

void swap(int * values, int i, int j){
	int tmp = values[i];
	values[i] = values[j];
	values[j] = tmp;
}

int  compare(int a, int b){
	return a - b;
}

int *bubble_sort(int *numbers, int count, compare_cb cmp, swap_func swap){
	int tmp = 0;
	int * target = malloc(count * sizeof(int));
	if(!target){
		die("target failed");
	}
	if(count == 0){
		return numbers;
	}
	memcpy(target, numbers, count * sizeof(int));
	for(int i = 1; i < count; i++){
		int j = i;
		while( j > 0 && cmp(target[j], target[j-1])< 0){
			swap(target, j, j-1);
			j--;
		}
	}
	return target;
}

int main(int argc, char* argv[]){
	int values[] = {1, 9, 3, 5, 8, 0};
	int* res = bubble_sort(values, 6, compare, swap);
	for(int i = 0; i < 6; i++){
		printf("%d\n",res[i]);
	}

}
