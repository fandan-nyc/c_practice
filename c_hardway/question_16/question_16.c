#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


struct Person {
	char* name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char* name, int age, int height, int weight) {
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	who -> name = strdup(name);
	who -> age = age;
	who -> height = height; 
	who -> weight = weight;
	return who;
}

void Person_destroy(struct Person *who) {
	assert (who != NULL);
	free(who -> name);
	free(who);
}

void Person_print(struct Person *who){
	printf("name: %s\n", who-> name);
	printf("age: %d\n", who-> age);
	printf("height: %d\n", who-> height);
	printf("weight: %d\n", who-> weight);
}

void Person_print_another(struct Person who) {
	printf("name: %s\n", who.name);
}

int main(int argc, char* argv[]){
	struct Person *joe = Person_create("joe alex", 1,2,3);
	struct Person *frank = Person_create("frank blank", 4, 5, 6);
	Person_print(joe);
	Person_print(frank);
	
	joe -> age += 20;
	joe -> weight += 30;
	joe -> height -= 100;
	Person_print(joe);

//	Person_destroy(joe);
//	Person_destroy(frank);
	printf("this is another print\n");
	Person_print_another(*joe);
	// you can use both -> and .
	// -> is for pointer and . is for the object itself
}
