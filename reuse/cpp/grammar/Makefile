CC=gcc
CXX=g++
CFLAGS=-std=c11 -g -O3 -Wall
LDFLAGS=-pthread
CXXFLAGS=-std=c++11 -g -O3 -Wall


raw_string:
	$(CXX) $(CXXFLAGS) raw_string.cpp -o raw_string.out
	./raw_string.out

CRTP:
	$(CXX) $(CXXFLAGS) CRTP.cpp -o CRTP.out
	./CRTP.out

pointer_circular_reference_example:
	$(CXX) $(CXXFLAGS) pointer_circular_reference_example.cpp -o pointer_circular_reference_example.out
	./pointer_circular_reference_example.out

null_object_pattern_get_binary_tree_size:
	$(CXX) $(CXXFLAGS) null_object_pattern_get_binary_tree_size.cpp -o null_object_pattern_get_binary_tree_size.out
	./null_object_pattern_get_binary_tree_size.out

literal_operator_example:
	g++ literal_operator_example.cpp -std=c++11 -o literal_operator_example.out
	./literal_operator_example.out 
