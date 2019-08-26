#include <stdio.h>

int test(){
    static int x = 0;
    x++;
    return x;
}

int test_1(){
    static int x = 0;
    x ++;
    return x;
}

int main(int argc, char* argv[]){
    printf("data: %d\n", test());
    printf("data: %d\n", test());
    printf("data: %d\n", test_1());
    printf("data: %d\n", test_1());
}
