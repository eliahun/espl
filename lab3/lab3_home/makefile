
CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: xsum


xsum: xsum.o 
	cc -o $@ $^








clean:
	rm -f *.o


