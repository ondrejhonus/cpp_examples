#include <iostream>

#include "system.hpp"

int main(int, char**) {
  System s1;
  std::cout << "S1: " << std::endl;
  std::cout << s1;

  std::cout << "S2: " << std::endl;
  System s2("1010101", 2);
  std::cout << s2;

  std::cout << "Im not doing the whole main" << std::endl;
  return 0;
}
