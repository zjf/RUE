CC=gcc
CFLAGS = -Wall -lm -g

rue: main.o vector.o
	$(CC) $(CFLAGS) -o rue main.o vector.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h khash.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	rm -f *.o
	rm rue