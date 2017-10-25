all: program6

program6: program6.o list.o
	gcc program6.o list.o -o program6

program6.o: program6.c list.h
	gcc -c program6.c -o program6.o

list.o: list.c list.h
	gcc -c list.c -o list.o

run: all
	./program6

checkmem: all
	valgrind -v ./program6

clean:
	rm -f *.o program6
