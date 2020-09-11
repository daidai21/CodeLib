CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -O3


sources = $(shell find . -name "*.cpp")


all: compile execute

compile:
	echo source files:
	echo $(sources)
	$(foreach file_path, $(sources), \
		echo $(file_path); \
		$(CXX) $(CXXFLAGS) $(file_path) -o $(addsuffix .out, $(basename $(file_path))); \
	)

execute:
	find . -name "*.out" | xargs -I {} sh -c ./{}

check:
	$(foreach file_path, $(sources), \
		echo $(file_path); \
		valgrind --tool=memcheck \
				 --leak-check=full \
				 --show-leak-kinds=all \
				 ./$(addsuffix .out, $(basename $(file_path))); \
	)

clean:
	find . -name "*.out" | xargs rm

