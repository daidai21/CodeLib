CC=gcc
GCC_VERSION=c11
CFLAGS=-c -Wall -O3


all: udp \
	 tcp_select

test:
	# TODO

tcp_select:
	$(CC) tcp_select_server.c -o tcp_select_server.out -std=$(GCC_VERSION) $(CFLAGS)
	$(CC) tcp_select_client.c -o tcp_select_client.out -std=$(GCC_VERSION) $(CFLAGS)

udp:
	$(CC) udp_client.c -o udp_client.out -std=$(GCC_VERSION) $(CFLAGS)
	$(CC) udp_server.c -o udp_server.out -std=$(GCC_VERSION) $(CFLAGS)

clean:
	rm *.out

