
CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: bcmp bfix


bcmp: bcmp.o 
	cc -o $@ $^

bfix: bfix.o diff.o 
	cc -o $@ $^

fgetname: diff.o 
	$(CC) $(CFLAGS) -o $@ $^



clean:
	rm -f *.o


