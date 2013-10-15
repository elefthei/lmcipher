CC=g++
CFLAGS=-Wall -O2 -o lmcipher
all:
	$(CC) src/main.cpp $(CFLAGS)
install:
	$(CC) src/main.cpp $(CFLAGS)
	chmod 750 lmcipher
	chmod 750 src/partyvan
	cp lmcipher /usr/sbin/lmcipher
	cp src/partyvan /usr/sbin/partyvan
clean:
	rm -f lmcipher
remove:
	rm -f /usr/sbin/lmcipher
	rm -f /usr/sbin/partyvan
