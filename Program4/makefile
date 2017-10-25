all: program4

program4: tournament.o program4.o
	gcc program4.o tournament.o -lm -o program4

program4.o: program4.c tournament.h
	gcc -c program4.c -lm -o program4.o

tournament.o: tournament.c tournament.h
	gcc -c tournament.c -lm -o tournament.o

run: all
	./program4

checkmem: all
	valgrind ./program4

clean:
	rm *.o program4
