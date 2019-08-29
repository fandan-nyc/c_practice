#include<stdio.h>

int main(int argc, char* argv[]){
	int number[4] = {0};
	char name[4] = {'a'};

	printf("numbers : %d, %d, %d, %d\n", number[0],number[1],number[2],number[3]);
	printf("name: %c, %c, %c, %c\n", name[0],name[1],name[2],name[3]);

	printf("%s\n", name);

	number[0] = 100;
	number[1] = 200;
	number[2] = 300;
	number[3] = 400;

	name[0] = 'D';
	name[1] = 'a';
	name[2] = 'n';
	name[3] = '\0';
	// if you set name[3] something else, you will see that the printf does not print out name correctly due to the lack of \0

	printf("numbers : %d, %d, %d, %d\n", number[0],number[1],number[2],number[3]);
	printf("name: %c, %c, %c, %c\n", name[0],name[1],name[2],name[3]);
	printf("%s\n", name);

	char *another = "Dan";
	printf("another: %s\n", another);
	printf("another : %c, %c, %c, %c\n", another[0],another[1], another[2], another[3]);
}
