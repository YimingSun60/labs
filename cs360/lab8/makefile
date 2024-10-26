

CC = gcc 

INCLUDES = -I/home/plank/cs360/include

CFLAGS = -g $(INCLUDES)

LIBDIR = /home/plank/cs360/objs

LIBS = $(LIBDIR)/libfdr.a 

EXECUTABLES: jsh jsh2

all: $(EXECUTABLES)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

jsh: jsh.o
	$(CC) $(CFLAGS) -o jsh jsh.o $(LIBS)

jsh2: jsh2.o
	$(CC) $(CFLAGS) -o jsh2 jsh2.o $(LIBS)

#make clean will rid your directory of the executable,
#object files, and any core dumps you've caused
clean:
	rm core $(EXECUTABLES) *.o


