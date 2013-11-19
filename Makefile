CC=gcc
CFLAGS = -Wall -lm -g

rue: main.o vector.o matrix.o
	$(CC) $(CFLAGS) -o rue main.o vector.o matrix.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h khash.h
	$(CC) $(CFLAGS) -c vector.c

matrix.o: matrix.c matrix.h khash.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm -f *.o
	rm rue
