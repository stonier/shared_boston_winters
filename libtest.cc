#include <iostream>

class Test {
public:
  Test()  { std::cerr << "In Test()..." << std::endl; }
  ~Test() { std::cerr << "In ~Test()..." << std::endl; }
};

Test mytest;
