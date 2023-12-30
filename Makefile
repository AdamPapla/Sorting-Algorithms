CC=g++
CFLAGS=-Wall -Wextra 

HFILES=sorting.hh
SFILES=sorting.o

all:sort

sort:$(HFILES) $(SFILES) main.cc 
	$(CC) $(CFLAGS) -o sort $(SFILES) main.cc

clean: 
	rm *.o sort