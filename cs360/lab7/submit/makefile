CFLAGS = -g -Wall -m32

test: test.o mymalloc.o
	gcc $(CFLAGS) mymalloc.o test.o -o test

test.o: test.c
	gcc $(CFLAGS) -c test.c

mymalloc.o: mymalloc.c mymalloc.h
	gcc $(CFLAGS) -c mymalloc.c

clean:
	rm *.o test
