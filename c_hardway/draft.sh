mkdir question_$1

cp dbg.h question_$1
cd question_$1

touch question_$1.c
printf "#include<stdio.h>\n#include \"dbg.h\"\n\nint main(int argc, char* argv[]){\n\n\n}" >> question_$1.c

touch Makefile
printf "CFLAGS=-Wall\n\nclean:\n\trm -f question_$1;\n\nrun: clean\n\tmake question_$1;./question_$1" >> Makefile
