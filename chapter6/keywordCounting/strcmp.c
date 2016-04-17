int strCmp(char * a, char * b){
	while( *a != '\0' && *b != '\0' && *a == *b){
		++a;
		++b;
	}
	return *a - *b;
}

