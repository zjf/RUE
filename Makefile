CC=gcc
CFLAGS = -Wall -lm -g

rue: main.o vector.o matrix.o linear_regression.o
	$(CC) $(CFLAGS) -o rue main.o vector.o matrix.o linear_regression.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h khash.h
	$(CC) $(CFLAGS) -c vector.c

matrix.o: matrix.c matrix.h khash.h
	$(CC) $(CFLAGS) -c matrix.c

linear_regression: linear_regression.c linear_regression.h
	$(CC) $(CFLAGS) -c linear_regression.c

clean:
	rm -f *.o
	rm rue
