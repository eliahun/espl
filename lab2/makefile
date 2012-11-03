%.o: %.c
	gcc -c -o $@ $<
 
all: fortune clean
 
clean:
	rm -f *.o
 
invert: fortune.o
	cc -o $@ $^ 
 
