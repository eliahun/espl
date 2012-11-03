
CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: c_canalyze


c_canalyze: c_analyze.o fgetname.o 
	cc -o $@ $^

fgetname: fgetname.o 
	$(CC) $(CFLAGS) -o $@ $^





clean:
	rm -f *.o


