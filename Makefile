breadboard: main.o breadboard.o
	gcc main.o breadboard.o -o breadboard

main.o: main.c
	gcc -c main.c

breadboard.0: breadboard.c breadboard.h
	gcc -c bredboard.c

clean:
	rm *.o output
