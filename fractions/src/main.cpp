#include <iostream>

#include "fraction.hpp"

int main(int, char**) {
  fraction f1;
  std::cout << "f1 constructor:" << std::endl;
  std::cout << f1.get_string_frac() << ", " << f1.frac_to_decimal()
            << std::endl;
  fraction f2(3, 2);
  std::cout << "f2 parameter constructor:" << std::endl;
  std::cout << f2.get_string_frac() << ", " << f2.frac_to_decimal()
            << std::endl;
  fraction f3(f2);
  std::cout << "f3(copy f2) constructor:" << std::endl;
  std::cout << f3.get_string_frac() << ", " << f3.frac_to_decimal()
            << std::endl;
  fraction f4(0, 2);
  std::cout << "f4 parameter constructor:" << std::endl;
  std::cout << f4.get_string_frac() << ", " << f4.frac_to_decimal()
            << std::endl;

  if (f2.flip_fraction()) {
    std::cout << "f2 flipped:" << std::endl;
    std::cout << f2.get_string_frac() << std::endl;
  } else {
    std::cout << "Couldnt flip fraction" << std::endl;
  }
  if (f4.flip_fraction()) {
    std::cout << "f4 flipped:" << std::endl;
    std::cout << f4.get_string_frac() << std::endl;
  } else {
    std::cout << "Couldnt flip fraction f4" << std::endl;
  }

  int new_num, new_denom;
  std::cout << "change f1:" << std::endl;
  std::cout << "change numerator:" << std::endl;
  std::cin >> new_num;
  std::cout << "change denominator:" << std::endl;
  std::cin >> new_denom;
  if (f1.set_denominator(new_denom)) {
    f1.set_numerator(new_num);
    std::cout << "f1 after change:" << std::endl;
    std::cout << f1.get_string_frac() << std::endl;
  } else {
    std::cout << "Invalid fraction." << std::endl;
  }

  std::cout << "f3 = f1 + f2 = " << f1.get_string_frac() << " + "
            << f2.get_string_frac() << " = " << (f1 + f2).get_string_frac()
            << std::endl;
  ;
}
