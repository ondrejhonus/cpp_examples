#pragma once

#include <iostream>
#include <ostream>
#include <string>

class Person {
 public:
  Person();
  Person(std::string);
  Person(const Person& p);

  ~Person() = default;

  std::string get_security_num() const;
  int get_age() const;
  std::string get_birth() const;

  bool set_security_num(std::string sec_num);

  friend std::ostream& operator<<(std::ostream& os, const Person& person);

 private:
  std::string security_num;

  bool is_security_num_valid(std::string sn) const;
};
