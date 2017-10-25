all: program8

program8: program8.o heap.o
	gcc program8.o heap.o -o program8

program8.o: program8.c heap.h
	gcc -c program8.c -o program8.o

heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o

run: all
	./program8

checkmem: all
	valgrind -v ./program8

clean:
	rm -f *.o program8
