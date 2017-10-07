CFLAGS=-Wall -g
clean:
	rm -rf *.dSYM
	rm -f test
	rm -f test1
	rm -f test2
	rm -f test3
	rm -f client
all: 
	make test
	make test1
	make test2
	make test3
# $@ gives you the name of the target, in this case, it is client
# $? is the the dependecy what is more recent than target 
# so if test1.c get changed after we have test build, it will rebuild
# otherwise, it will not
client: test1.c
	$(CC) $? -o $@

# gives you all the dependencies
viewsources: test1.c test2.c test3.c
	cat $^
