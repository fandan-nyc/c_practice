#include <stdio.h> 

static double atof(char * input);

int main(int argc, char ** argv){
	char * input = argv[1];
	printf("the input is %s\n", input);
	double x = atof(input);
	printf("atof gives %f\n",x);

}

static int itoch(char x){
	if(x >= '0' && x <= '9'){
		return x  - '0';
	}
	return 0;
}

static double atof( char * input){
	int power  = 1;
	double total = 0 ; 
	int sign = 1;
	if(*input == '-'){
		sign = -1;
		++input;
	}else if(*input == '+'){
		++input;
	}
	while( *input != 'e' && *input != 'E' && *input != '\0' && *input !='.'){
		total = ((total * 10) + itoch(*input));
		++input;
	}
	if(*input == '.'){
		++input;
		while(*input != 'e' && *input != 'E' && *input != '\0'){
			power *= 10;
		    total = (total * 10) + itoch(*input);
		    ++input;
		}
	}
	int powerSign = -1;
	int powerSci = 0;
	if(*input == 'e' || *input =='E'){
		++input;
		if(*input == '-'){
			powerSign = 1;
			++input;
		}else if(*input == '+'){
			powerSign = -1;
			++input;
		}
		while(*input != '\0'){
			powerSci = powerSci * 10 + itoch(*input);
			++input;
		}
		if(powerSign == 1){
			while(powerSci-- > 0){
				power *= 10;
			}
		}
		else{
			while(powerSci-- > 0){
				power /= 10;
			}
		}
	}
	return total / power;
}

