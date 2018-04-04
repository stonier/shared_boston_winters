CXX=g++
CXXFLAGS=-g -Wall -Wextra -std=c++14

all: main

main: test.o
	$(CXX) $(CXXFLAGS) -o main test.o -ldl

clean:
	rm -f *~ *.o main
