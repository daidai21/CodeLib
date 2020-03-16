all: thread_pool_example

thread_pool_example: thread_pool.c thread_pool_example.c
	gcc -pthread thread_pool.c thread_pool_example.c -o thread_pool_example

clean:
	rm thread_pool_example
