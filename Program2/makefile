all:
	gcc -g program2.c -o project2

defuseTheBomb: bomb.o defuseMe.o hidden.o
	gcc bomb.o defuseMe.o hidden.o -o defuseTheBomb

bomb.o: bomb.c
	gcc -c bomb.c

defuseMe.o: defuseMe.c
	gcc -c defuseMe.c

checkmem:
	gcc program2.c -o program2.o
	chmod a+x ./program2.o
	valgrind -v ./program2.o

clean:
	find ./ -name "*.o" -not -name "hidden.o" -delete
	find defuseTheBomb -delete
	find project2 -delete
