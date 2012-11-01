
CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: canalyze


canalyze: canalyze.o fgetname.o 
	cc -o $@ $^

fgetname: fgetname.o 
	$(CC) $(CFLAGS) -o $@ $^





clean:
	rm -f *.o


