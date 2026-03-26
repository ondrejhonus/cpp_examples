#include "date.hpp"

#include <chrono>
#include <ctime>
#include <iostream>

bool Date::is_date_valid(Dates date) {
  if (date.year < min_year || date.year > max_year) {
    return false;
  } else if (date.month < 1 || date.month > 12) {
    return false;
  } else if (date.day > days_in_month(date.month, date.year) || date.day <= 0) {
    return false;
  }
  return true;
}

bool Date::is_leap_year(unsigned int year) const {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
  return false;
}

unsigned int Date::days_in_month(unsigned int month, unsigned int year) const {
  switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
    case 2:
      return is_leap_year(year) ? 29 : 28;
    default:
      return 31;
      break;
  }
}

Date::Dates Date::get_system_date() const {
  Dates system_date;
  time_t timestamp = time(&timestamp);
  struct tm datetime = *localtime(&timestamp);

  system_date.day = datetime.tm_mday;
  system_date.month = datetime.tm_mon + 1;
  system_date.year = datetime.tm_year + 1900;

  return system_date;
}

Date::Date() { this->current_date = get_system_date(); }

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
  if (is_date_valid({day, month, year})) {
    current_date = {day, month, year};
  } else {
    current_date = get_system_date();
  }
}

Date::Date(Date& date) {
  current_date.day = date.current_date.day;
  current_date.month = date.current_date.month;
  current_date.year = date.current_date.year;
}

unsigned int Date::get_day() const { return current_date.day; }
unsigned int Date::get_month() const { return current_date.month; }
unsigned int Date::get_year() const { return current_date.year; }

std::ostream& operator<<(std::ostream& os, const Date& date) {
  std::string day_word;
  switch (date.weekday_order()) {
    case 0:
      day_word = "Monday";
      break;
    case 1:
      day_word = "Tuesday";
      break;
    case 2:
      day_word = "Wednesday";
      break;
    case 3:
      day_word = "Thursday";
      break;
    case 4:
      day_word = "Friday";
      break;
    case 5:
      day_word = "Saturday";
      break;
    case 6:
      day_word = "Sunday";
      break;
    default:
      break;
  }
  os << date.current_date.day << ". " << date.current_date.month << ". "
     << date.current_date.year << " is: " << day_word << std::endl
     << "Days since unix epoch: " << date.days_since_epoch() << std::endl;
  return os;
}

bool Date::set_date(unsigned int day, unsigned int month, unsigned int year) {
  Dates temp;
  temp = {day, month, year};
  if (is_date_valid(temp)) {
    current_date.day = day;
    current_date.month = month;
    current_date.year = year;
    return true;
  }
  return false;
}

bool Date::set_day(unsigned int day) {
  Dates temp;
  temp = {day, current_date.month, current_date.year};
  if (is_date_valid(temp)) {
    current_date.day = day;
    return true;
  }
  return false;
}

bool Date::set_month(unsigned int month) {
  Dates temp;
  temp = {current_date.day, month, current_date.year};
  if (is_date_valid(temp)) {
    current_date.month = month;
    return true;
  }
  return false;
}

bool Date::set_year(unsigned int year) {
  Dates temp;
  temp.day = current_date.day;
  temp.month = current_date.month;
  temp.year = year;
  if (is_date_valid(temp)) {
    current_date.year = year;
    return true;
  }
  return false;
}

unsigned int Date::date_to_days(Dates date) const {
  unsigned int days = 0;
  for (size_t i = min_year; i < date.year; i++) {
    is_leap_year(i) ? days += 366 : days += 365;
  }
  for (size_t i = 1; i < date.month; i++) {
    days += days_in_month(i, date.year);
  }
  days += date.day;

  return days;
}

Date::Dates Date::days_to_date(unsigned int days) const {
  Dates temp_date = {1, 1, 1970};
  unsigned int total_days = days - 1;

  while (total_days >= (is_leap_year(temp_date.year) ? 366 : 365)) {
    if (is_leap_year(temp_date.year)) {
      temp_date.year++;
      total_days -= 366;
    } else {
      temp_date.year++;
      total_days -= 365;
    }
  }
  while (total_days >= days_in_month(temp_date.month, temp_date.year)) {
    total_days -= days_in_month(temp_date.month, temp_date.year);
    temp_date.month++;
  }

  temp_date.day += total_days;
  return temp_date;
}

void Date::add_days_to_date(unsigned int days_to_add) {
  current_date = days_to_date(date_to_days(current_date) + days_to_add);
}

bool Date::set_days_from_epoch_day(unsigned int days_to_add) {
  current_date =
      days_to_date(1 + days_to_add);  // +1 coz its how many days passed
  return true;
}

unsigned int Date::days_since_epoch() const {
  Dates epoch = {1, 1, 1970};
  return (date_to_days(this->current_date) - date_to_days(epoch));
}

unsigned int Date::weekday_order() const {
  unsigned int epoch_day = 4;
  unsigned int offset = days_since_epoch() % 7;  // thursday
  if (offset <= 3) {
    return offset + 3;
  } else {
    return offset - 4;
  }
}

Date& Date::operator=(const Date& date) {
  current_date = {date.get_day(), date.get_month(), date.get_year()};
  return *this;
}

bool Date::operator==(const Date& date) {
  return (current_date.day == date.current_date.day &&
          current_date.month == date.current_date.month &&
          current_date.year == date.current_date.year);
}
