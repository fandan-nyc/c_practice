#include <stdio.h> 
#include <stdarg.h>

void miniPrintf(char * input, ...);

int main(int argc, char ** argv){
	char * x = "abc %s, %d, %f\n";
	miniPrintf(x, "ddef",1,12.45);
}

void miniPrintf(char * input, ...){

	int argcInt;
	float argcDouble;
	char * argcStr;

	va_list list;
	va_start(list, input);
	for(int i = 0; input[i] != '\0';++i){
		if(input[i] != '%'){
			putchar(input[i]);
		}else{
			switch(input[++i]){
				case 'd':
					argcInt = va_arg(list, int);
					printf("%d", argcInt);
					break;
				case 'f':
					argcDouble = va_arg(list, double);
					printf("%f", argcDouble);
					break;
				case 's':
					argcStr = va_arg(list, char *);
					while(*argcStr != '\0'){
						putchar(*argcStr++);
					}
					break;
				case '%':
					putchar('%');
					break;
				default:
					putchar(input[i-1]);
					putchar(input[i]);
					break;
			}
		}
	}
	va_end(list);


}
