#include <stdio.h>
#include "q22.h"
#include "dbg.h"

int MAX_SIZE = 199;

static int THE_AGE = 38;

int get_age(){
	return THE_AGE;
}

void set_age(int age){
	THE_AGE = age;
}

double update_ratio(double ratio){
	static double data = 1.00;
	double old = data;
	data = ratio;
	return old;
}

void print_size(){
	printf("the max size: %d\n", MAX_SIZE);
}
