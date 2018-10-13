CC = gcc
CFLAGS = -Wall

all:
	mkdir -p programs/bin
	$(CC) $(CFLAGS) src/vm.c programs/loop.c -o programs/bin/loop

run:
	./programs/bin/loop


clean:
	rm -rf programs/bin/