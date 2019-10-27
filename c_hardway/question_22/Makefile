CFLAGS=-Wall

clean:
	rm *.o


run: clean
	cc -c -o q22.o q22.c
	cc main.c q22.o -o main.o
	./main.o
