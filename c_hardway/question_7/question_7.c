#include <stdio.h>

int main(int argc, char* argv[]){
    int distance = 100;
    float power = 2.345f;
    double super = 5678.12;
    char init = 'A';
    char first_name[] = "Dan";
    char last_name[] = "Fan";

    printf("you are %d miles aways\n", distance);
    printf("you have %f levels of power.\n", power);
    printf("you have %f awesome super power \n", super);
    printf("the initial is %c\n", init);
    printf("the name is %s %s\n", first_name, last_name);

    long universe =  1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L;
    // if the long is within int, it will give you warning and print out the same value for int vs long
    // if the long is > int max, it will give you 0 for %d which is undefined and give you real value for %ld
    printf("the entire universe number defined is %d\n", universe) ;
    printf("the entire universe number defined is %ld\n", universe) ;

    double next = 1.2 / universe;
    printf("the next number is %e\n", next) ;

    char nul = 'a';
    int x = nul * 2;
    printf("you can multiply char with in as : %d\n", x);



}
