#include<stdio.h>

int main(int argc, char* argv[]){
	// normal pointer, should work fine
	int var1 =0, var2 = 10;
	int * ptr = &var1;
	ptr = &var2;
	printf("%d\n", *ptr);
	printf("%d\n", var1);
	*ptr = 98;
	// will change the value of var2 since they both point to the same mem
	printf("%d\n", *ptr);
	printf("%d\n", var2);

	// const pointer
	int * const ptr1 = &var1;
	// ptr1 = &var2;
	// the assignment above will have const_example.c:12:7: error: cannot assign to variable 'ptr1' with const-qualified type 'int *const'
	const int* ptr2 = &var1;
	ptr2 = &var2; // no problem, since it is pointer to const int
	// *ptr2 =  99; // this will fail, since it is a pointer to const, so we cannot change the value the pointer points to
}
