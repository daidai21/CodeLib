CC=gcc
GCC_VERSION=c11
CFLAGS=-c -Wall -O3


all: udp \
	 tcp_select

test:
	# TODO

tcp_select:
	# $(CC) tcp_select_server.c -o tcp_select_server.out -std=$(GCC_VERSION) $(CFLAGS)
	# $(CC) tcp_select_client.c -o tcp_select_client.out -std=$(GCC_VERSION) $(CFLAGS)
	# for debug
	gcc tcp_select_server.c -o tcp_select_server.out
	gcc tcp_select_client.c -o tcp_select_client.out


udp:
	$(CC) udp_client.c -o udp_client.out -std=$(GCC_VERSION) $(CFLAGS)
	$(CC) udp_server.c -o udp_server.out -std=$(GCC_VERSION) $(CFLAGS)

tcp:
	# $(CC) tcp_client.c -o tcp_client.out -std=$(GCC_VERSION) $(CFLAGS)
	# $(CC) tcp_server.c -o tcp_server.out -std=$(GCC_VERSION) $(CFLAGS)
	# for debug
	gcc tcp_server.c -o tcp_server.out
	gcc tcp_client.c -o tcp_client.out


tcp_multi_thread:
	# for debug
	gcc tcp_multi_thread_client.c -o tcp_multi_thread_client.out
	gcc tcp_multi_thread_server.c -o tcp_multi_thread_server.out

tcp_poll:
	# for debug
	gcc tcp_poll_client.c -o tcp_poll_client.out
	gcc tcp_poll_server.c -o tcp_poll_server.out


tcp_epoll:
	# for debug
	gcc tcp_epoll_client.c -o tcp_epoll_client.out
	gcc tcp_epoll_server.c -o tcp_epoll_server.out

clean:
	rm *.out
