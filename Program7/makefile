all: program7

program7: program7.o bst.o
	gcc program7.o bst.o -o program7

program7.o: program7.c bst.h
	gcc -c program7.c -o program7.o

bst.o: bst.c bst.h
	gcc -c bst.c -o bst.o

run: all
	./program7

checkmem: all
	valgrind -v ./program7

clean:
	rm -f *.o program7
