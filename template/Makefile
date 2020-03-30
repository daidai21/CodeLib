CC=gcc
CXX=g++
CFLAGS=-std=c11 -g -O3 -Wall
LDFLAGS=-pthread
CXXFLAGS=-std=c++11 -g -O3 -Wall


all: helloworld

helloworld:
	$(CC) $(CFLAGS) helloworld.c

debug:
	$(CC) $(CFLAGS) helloworld.c -D DEBUG

check:
	$(CC) $(CFLAGS) helloworld.c
	valgrind --tool=memcheck\
			--leak-check=full\
			--show-leak-kinds=all\
			--track-origins=yes\
			--verbose\
			--log-file=valgrind-out.log\
			./a.out

clean:
	rm *.out
	rm valgrind-out.log

