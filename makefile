all: timer.o exercices.o main.o
	gcc -std=c99 -Wall -o test timer.o exercices.o main.o -lm
	
timer.o: timer.c
	gcc -std=c99 -Wall -o timer.o -c timer.c
	
exercices.o: exercices.c timer.h
	gcc -std=c99 -Wall -o exercices.o -c exercices.c
	
main.o: main.c exercices.h 
	gcc -std=c99 -Wall -o main.o -c main.c

clean:
	rm -rf *.o
	