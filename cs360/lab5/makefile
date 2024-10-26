#CS 360 Lab 1 Makefile

CC = gcc 

INCLUDES = -I/home/plank/cs360/include

CFLAGS = -g $(INCLUDES)

LIBDIR = /home/plank/cs360/objs

LIBS = $(LIBDIR)/libfdr.a 

EXECUTABLES: malloc

all: $(EXECUTABLES)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

malloc: malloc.o
	$(CC) $(CFLAGS) -o malloc malloc.o $(LIBS)

#make clean will rid your directory of the executable,
#object files, and any core dumps you've caused
clean:
	rm core $(EXECUTABLES) *.o


