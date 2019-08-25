#include <stdio.h>

enum week {Monday, Tuesday, Wednesday} x;
// you can define a week variable as x
// which is the same as enum week x = Monday;
enum secret {first = 100, second = 200, third = 300};

int main(int argc, char* argv[]){
	enum week y = Wednesday;
	printf("today is %d\n", x + 1);
	printf("today is %d\n", y);
	printf("first value is %d\n", first);
}
