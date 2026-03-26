#pragma once
#include <string>

class fraction {
 public:
  fraction();
  fraction(int numerator, int denominator);
  fraction(fraction& frac);
  ~fraction() = default;

  int get_numerator() const;
  int get_denominator() const;
  std::string get_string_frac() const;

  bool set_numerator(int numerator);
  bool set_denominator(int denominator);
  bool flip_fraction();
  fraction operator+(const fraction& frac) const;
  float frac_to_decimal();

 private:
  int numerator, denom;

  bool shorten_frac();

  fraction& operator=(const fraction& frac);

  int gcd(int a, int b);
};
