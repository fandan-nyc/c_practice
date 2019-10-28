#include<stdio.h>
#include "dbg.h"

#define MAX_DATA 100
#define print_str(M, ...) printf(M  "\n", ##__VA_ARGS__);
typedef enum EyeColor {
	BLUE, BROWN, GREEN, BLACK, OTHER
} EyeColor;

const char* EYE_COLOR_NAMES[] = {"blue", "brown", "green", "black", "other"};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eye;
	float income;
} Person;

typedef void (*to_str)(Person *person);

void print_person(Person * person){
	print_str("%s", person -> first_name);
	print_str("%s", person -> last_name);
	print_str("%d", person -> age);
	print_str("%s", EYE_COLOR_NAMES[person -> eye]);
	print_str("%f", person -> income);
}

void log_info_internal(to_str func, Person *person){
	func(person);
}


int main(int argc, char* argv[]){
	Person you = {.age=10};
	int i = 0;
	char* in = NULL;
	 
	printf("what is your first name ?\n");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	check(in != NULL, "first name failed to set")
	printf("what is your last name ?\n");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in != NULL, "last name failed to set")
	printf("what is your age ?\n");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc > 0, "you have to enter number");

	printf("what color are your eyes ? \n");
	for(int i = 0; i <= OTHER; i++){
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf("> ");

	int eyes = -1;
	rc = fscanf(stdin, "%d", &eyes);
	check(rc > 0, "you have to enter a number");
	check(eyes > 0 && eyes <= OTHER && eyes < sizeof(EYE_COLOR_NAMES)/sizeof(char*) &&\
		EYE_COLOR_NAMES[eyes], "the eyes input failed");
	you.eye = eyes-1;

	printf("how much do u earn per hour?\n");

	rc = fscanf(stdin, "%f", &you.income);
	check(rc > 0, "you have to give a float for income");

	log_info_internal(print_person, &you);

	return 0;

error:
	return -1;
}
