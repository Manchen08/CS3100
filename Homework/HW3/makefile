all: comp

comp: HW3.o printStuff.o
	gcc HW3.o -o HW3
	gcc printStuff.o -o printStuff

HW3.o: HW3.c 
	gcc -c HW3.c

printStuff.o:
	gcc -c printStuff.c

clean:
	rm *o HW3
