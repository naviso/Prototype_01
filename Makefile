# Variables to use rather than typing the same length 
pi = -l bcm2835

all: LEDEXE

# Listing All object that LED project needs
LEDEXE: main.o test.o
	gcc main.o test.o -o LEDEXE $(pi)

# Listing object dependancies	
main.o: main.c
	gcc -c main.c 
	
test.o: test.c
	gcc -c test.c 
	
# Clean *o removes object files, and inserting exe name removes executable
clean:
	rm rf *o *LEDEXE
