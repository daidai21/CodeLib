all: encapsulation


# compile
encapsulation:
	gcc implement_class_encapsulation_example.c -o implement_class_encapsulation_example

# util
check:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./implement_class_encapsulation_example

clean:
	rm implement_class_encapsulation_example

