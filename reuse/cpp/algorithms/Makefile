CXX = g++
CXXFLAGS = -Wall -std=c++11


all: snowflake_test

snowflake_test:
	$(CXX) $(CXXFLAGS) snowflake_test.cpp -o snowflake_test.out -pthread -D DEBUG

clean:
	rm -f *.out

