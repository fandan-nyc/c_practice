#include<stdio.h>

int main(int argc, char* argv[]){
	int ages[] = {1,2,3,4,5};
	char* names[] = {"a","b","c","d", "e"};
	int count = sizeof(ages)/ sizeof(int);
	for(int i = 0; i < count; i ++){
		printf("%s: %d\n", names[i], ages[i]);
	}

	printf("--------\n");

	int * curr_age = ages;
	char** curr_names = names;

	for(int i = 0 ; i < count; i ++){
		printf("%s is %d years old\n", *(curr_names +i), *(curr_age + i));
	}
	printf("----------\n");

      // pointer is like array
        int * age_pt = ages;
	char** name_pt = names;
	for(int i = 0; i < count; i ++){
		printf("%s is %d years old\n", name_pt[i], age_pt[i]);
	}

     // print the size of array and size of pointer
     printf("the size of array: %lu\n", sizeof(ages));
     printf("the size of pointer: %lu", sizeof(age_pt));
}
