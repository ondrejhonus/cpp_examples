#include <strings.h>

#include <iostream>
#include <limits>
#include <ostream>

#include "date.hpp"

int main(int, char**) {
  Date d;
  std::cout << "Constructor" << std::endl;
  std::cout << d << std::endl;
  Date d1(26, 3, 2026);
  std::cout << "Paremeter Constructor" << std::endl;
  std::cout << d1 << std::endl;
  Date d2(d1);
  std::cout << "Copying Constructor" << std::endl;
  std::cout << d2 << std::endl;

  std::string choice = "y";
  while (choice == "y" || choice == "Y") {
    Date d3;
    do {
      unsigned int day, mon, y;
      std::cout << "Enter a new date d3:" << std::endl;
      std::cout << "Day:";
      std::cin >> day;
      std::cout << "Month:";
      std::cin >> mon;
      std::cout << "Year:";
      std::cin >> y;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      if (d3.set_date(day, mon, y))
        break;
      else
        std::cout << "Incorrect date, try again:" << std::endl;
    } while (1);

    std::cout << "D3 after change:" << std::endl;
    std::cout << d3 << std::endl;

    unsigned int days_since_epoch;
    std::cout << "Enter days since unix epoch to d3:" << std::endl;
    std::cin >> days_since_epoch;
    d3.set_days_from_epoch_day(days_since_epoch);
    std::cout << "D3 after epoch addition:" << std::endl;
    std::cout << d3 << std::endl;

    std::cout << "d1 a d3 si " << (d1 == d3 ? "jsou rovny" : "nejsou rovny")
              << std::endl;

    unsigned int days_to_add;
    std::cout << "How many days do you wanna add to d3:" << std::endl;
    std::cin >> days_to_add;
    std::cout << "D3 after adding " << days_to_add << " days" << std::endl;
    std::cout << d3 << std::endl;

    std::cout << "Continue? [y/n]: ";
    std::cin >> choice;
  }
  return 0;
}
