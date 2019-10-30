CFLAGS=-Wall --NDEBUG

clean:
	rm -f *.o;

run: clean
	cc -c -o log_find.o log_find.c;
	cc -c -o parser.o parser.c
	cc log_find.o parser.o main.c -o main.o;

test: run
	./main.o -o aaa bb
