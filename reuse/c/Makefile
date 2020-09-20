

exec_file_zero_copy_example:
	mkfile -n 1g read_big_file.dat
	mkfile -n 1g write_big_file.dat

	gcc file_zero_copy_example.c -o file_zero_copy_example.out
	time file_zero_copy_example.out ./read_big_file.dat ./write_big_file.dat zero_copy
	time file_zero_copy_example.out ./read_big_file.dat ./write_big_file.dat copy

	rm read_big_file.dat
	rm write_big_file.dat
