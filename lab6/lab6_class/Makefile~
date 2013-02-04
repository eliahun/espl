%.o: %.asm
	nasm -g -O1 -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -c -o $@ $<

all: bcmp_asm

bcmp_asm: bcmp_asm.o bcmp.o  cmp_files.o
	gcc -m32  -o $@ $^

clean:
	rm -f *.o $(EXECS)
 
bcmp: bcmp.o cmp_files.o
	$(CC) -o $@ $^


bcmp.o: bcmp.c 

bcmp_asm.o: bcmp_asm.asm

cmp_files.o: cmp_files.c 

