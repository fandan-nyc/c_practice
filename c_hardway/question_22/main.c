#include "q22.h"
#include "dbg.h"

const char* NAME = "Dan Fan";

void scope_demo(int count){
	log_info("count is %d", count);

	if(count > 10){
		int count = 100;
		log_info("count in this scope is %d", count);
	}

	log_info("count is at exit %d", count);
	count = 3000;
	log_info("count after assgin %d", count);
}

int main(int argc, char* argv[]){
	log_info("my name: %s", NAME);
	log_info("curreng age: %d", get_age());
	set_age(9800);
	log_info("current age is %d", get_age());
	log_info("size: %d", MAX_SIZE);
	MAX_SIZE = 99;
	print_size();

	log_info("ratio at first: %f", update_ratio(2.0));
	log_info("ratio at second: %f", update_ratio(3.0));
	log_info("ratio at third: %f", update_ratio(4.0));
	int count = 11;
	scope_demo(count);
	log_info("count after all: %d", count);
}
