#include "person.hpp"

#include <time.h>

Person::Person() { this->set_security_num("0608083663"); }

Person::Person(std::string sec_num) {
  if (!set_security_num(sec_num)) this->set_security_num("1111111111");
}

std::string Person::get_security_num() const { return this->security_num; }

int Person::get_age() const {
  time_t timer;
  time(&timer);
  struct tm* now = localtime(&timer);

  int raw_year = std::stoi(this->security_num.substr(0, 2));
  int raw_month = std::stoi(this->security_num.substr(2, 2));
  int birth_day = std::stoi(this->security_num.substr(4, 2));

  int birth_year = (raw_year < 54) ? raw_year + 100 : raw_year;
  int birth_month =
      (raw_month > 50) ? raw_month - 50 - 1 : raw_month - 1;  // - 1 for index

  int age = now->tm_year - birth_year;

  if (now->tm_mon < birth_month ||
      (now->tm_mon == birth_month && now->tm_mday < birth_day)) {
    age--;
  }

  return age;
}

std::string Person::get_birth() const {
  int raw_year = std::stoi(this->security_num.substr(0, 2));
  int raw_month = std::stoi(this->security_num.substr(2, 2));
  int birth_day = std::stoi(this->security_num.substr(4, 2));

  int birth_year = (raw_year < 54) ? raw_year + 100 : raw_year;
  birth_year += 1900;
  int birth_month = (raw_month > 50) ? raw_month - 50 : raw_month;

  std::string d, m, y;
  d = std::to_string(birth_day);
  m = std::to_string(birth_month);
  y = std::to_string(birth_year);

  return d + ". " + m + ". " + y;
}

bool Person::set_security_num(std::string sec_num) {
  if (is_security_num_valid(sec_num)) {
    this->security_num = sec_num;
    return true;
  }
  return false;
}

bool Person::is_security_num_valid(std::string sn) const {
  if (sn.length() != 10) return false;
  // all numbers
  for (char c : sn) {
    if (!std::isdigit(c)) return false;
  }
  if (std::stoi(sn.substr(2, 2)) > 62) return false;

  int first_nine = std::stoi(sn.substr(0, 9));
  int last = std::stoi(sn.substr(9, 1));

  if (first_nine % 11 == last) {
    return true;
  } else if (first_nine % 11 == 10 && last == 0) {
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
  os << "Cislo: " << person.get_security_num() << std::endl
     << "Narozeni: " << person.get_birth() << std::endl
     << "Vek: " << person.get_age() << std::endl;
  return os;
}