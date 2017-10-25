all: program5

program5: program5.o vector.o
	gcc program5.o vector.o -o program5

program5.o: program5.c vector.h
	gcc -c program5.c -o program5.o

vector.o: vector.c vector.h
	gcc -c vector.c -o vector.o

run: all
	./program5

checkmem: all
	valgrind -v ./program5

clean:
	rm -f *.o program5
