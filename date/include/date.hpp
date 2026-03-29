#pragma once
#include <ostream>

class Date {
 private:
  struct Dates {
    unsigned int day;
    unsigned int month;
    unsigned int year;
  };
  Dates current_date;

  bool is_date_valid(Dates date);
  bool is_leap_year(unsigned int year) const;
  unsigned int days_in_month(unsigned int month, unsigned int year) const;
  Dates get_system_date() const;
  unsigned int date_to_days(Dates date) const;

  static const int MAX_YEAR = 2050;
  static const int MIN_YEAR = 1970;

 public:
  Date();
  Date(unsigned int day, unsigned int month, unsigned int year);
  Date(Date& date);
  ~Date() = default;

  //   Dates get_date(unsigned int day, unsigned int month, unsigned int
  //   year);
  unsigned int get_day() const;
  unsigned int get_month() const;
  unsigned int get_year() const;

  bool set_date(unsigned int day, unsigned int month, unsigned int year);
  bool set_day(unsigned int day);
  bool set_month(unsigned int month);
  bool set_year(unsigned int year);

  unsigned int days_since_epoch() const;  // Epoch: 1. 1. 1970 - Thursday
  unsigned int weekday_order() const;
  Date::Dates days_to_date(unsigned int days) const;
  void add_days_to_date(unsigned int days_to_add);
  bool set_days_from_epoch_day(unsigned int days_to_add);

  Date& operator=(const Date& date);
  bool operator==(const Date& date);

  friend std::ostream& operator<<(std::ostream& os, const Date& date);
};
