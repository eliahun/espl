
CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all:  bfix_7


bfix_7: bfix_7.o 
	cc -o $@ $^

bfix_7.o :bfix_7.c


clean:
	rm -f *.o


