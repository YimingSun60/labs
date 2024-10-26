#CS 360 Lab 1 Makefile

CC = gcc 

INCLUDES = -I/home/plank/cs360/include

CFLAGS = -g $(INCLUDES)

LIBDIR = /home/plank/cs360/objs

LIBS = $(LIBDIR)/libfdr.a 

EXECUTABLES = data_uncompress

all: $(EXECUTABLES)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

data_uncompress: data_uncompress.o
	$(CC) $(CFLAGS) -o data_uncompress data_uncompress.o $(LIBS)
#make clean will rid your directory of the executable,
#object files, and any core dumps you've caused
clean:
	rm core $(EXECUTABLES) *.o


