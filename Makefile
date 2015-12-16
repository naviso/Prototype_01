# Variables to use rather than typing the same length 
pi = -l bcm2835

# Type in commnand make compile default
all:
	gcc main.c test.c -o LEDEXE $(pi)
# Type in command make compile for special reasons....	
compile:
	gcc main.c test.c -o LEDEXE $(pi)

# If you wanted to create specific object files or exe....
#
#	

# Clean *o removes object files, and inserting exe name removes executable
clean:
	rm rf *o *LEDEXE
