CC = gcc 

INCLUDES = -I/home/plank/cs360/include

CFLAGS = -g $(INCLUDES)

LIBDIR = /home/plank/cs360/objs

LIBS = $(LIBDIR)/libfdr.a 
EXECUTABLES: chat_server

all: $(EXECUTABLES)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

chat_server: chat_server.o $(LIBDIR)/sockettome.o
	$(CC) $(CFLAGS) -o chat_server chat_server.o $(LIBDIR)/sockettome.o $(LIBS) -lpthread

#make clean will rid your directory of the executable,
#object files, and any core dumps you've caused
clean:
	rm core $(EXECUTABLES) *.o


