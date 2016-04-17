
void swap(void ** input, int, int);

void quicksort( void ** input, int start, int end, int (*func)(void *, void *, int), int reverse, int useFold){
	if(start >= end)
		return;
	int middle = (start + end)/2;
	int last = start;
	swap(input, start, middle);
	for(int i =  start + 1; i <= end; i++){
		if(((*func)(input[i],input[start],useFold) < 0) != reverse){
			swap(input, i, ++last);
		}
	}
	swap(input, start, last);
	quicksort(input, start, last -1, func, reverse, useFold);
	quicksort(input, last+1, end, func, reverse,useFold);
}

void swap(void **input, int x, int y){
	void * tmp = input[x];
	input[x] = input[y];
	input[y] = tmp;
}