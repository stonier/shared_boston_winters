CXX=g++
CXXFLAGS=-g -Wall -Wextra -std=c++14

all: main libtest

main: test.o
	$(CXX) $(CXXFLAGS) -o main -fPIC test.o -ldl

libtest:
	$(CXX) $(CXXFLAGS) -shared -fPIC -o libtest.so libtest.cc

clean:
	rm -f *~ *.o main
