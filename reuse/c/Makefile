CXX=g++
CC=gcc

exec_file_zero_copy_example:
	mkfile -n 1g read_big_file.dat
	mkfile -n 1g write_big_file.dat

	gcc file_zero_copy_example.c -o file_zero_copy_example.out
	time file_zero_copy_example.out ./read_big_file.dat ./write_big_file.dat zero_copy
	time file_zero_copy_example.out ./read_big_file.dat ./write_big_file.dat copy

	rm read_big_file.dat
	rm write_big_file.dat

gc_example:  gc_example_test.c
	$(CC) -std=c99 -O3 -o gc_example_test.out gc_example_test.c


# https://github.com/sogou/workflow/blob/13a343b439/src/kernel/msgqueue.h
msg_que_example:
	$(CC) -std=c99 -O3 -pthread msg_que_example.c msg_que.c \
		-o msg_que_example.out
	./msg_que_example.out
