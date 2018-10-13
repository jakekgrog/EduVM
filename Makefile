CC = gcc
CFLAGS = -pedantic -Wall

all:
	mkdir -p programs/bin
	$(CC) $(CFLAGS) src/eduvm.c programs/loop.c -o ./programs/bin/loop

run:
	./programs/bin/loop

clean:
	rm -rf programs/bin/