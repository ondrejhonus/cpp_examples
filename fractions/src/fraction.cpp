#include "fraction.hpp"

#include <numeric>
#include <string>

fraction::fraction() {
  set_numerator(1);
  set_denominator(1);
}

fraction::fraction(int numerator, int denominator) {
  set_numerator(numerator);
  if (!set_denominator(denominator)) {
    set_denominator(1);
  }
}

fraction::fraction(fraction& frac) {
  set_numerator(frac.get_numerator());
  set_denominator(frac.get_denominator());
}

int fraction::get_numerator() const { return this->numerator; }

int fraction::get_denominator() const { return this->denom; }

std::string fraction::get_string_frac() const {
  return std::to_string(this->numerator) + "/" + std::to_string(this->denom);
}

bool fraction::set_numerator(int nume) {
  this->numerator = nume;
  return true;
}
bool fraction::set_denominator(int denominator) {
  if (denominator != 0) {
    this->denom = denominator;
    return true;
  }
  return false;
}

bool fraction::shorten_frac() {
  int greatest_common = gcd(this->numerator, this->denom);
  this->numerator /= greatest_common;
  this->denom /= greatest_common;
  return true;
}

float fraction::frac_to_decimal() {
  return float(this->numerator) / float(this->denom);
}

bool fraction::flip_fraction() {
  if (this->numerator != 0) {
    int temp = this->numerator;
    this->numerator = this->denom;
    this->denom = temp;
    return true;
  }
  return false;
}

fraction& fraction::operator=(const fraction& frac) {
  set_numerator(frac.get_numerator());
  set_denominator(frac.get_denominator());
  return *this;
}

fraction fraction::operator+(const fraction& frac) const {
  fraction new_frac;
  new_frac.numerator =
      this->numerator * frac.denom + frac.numerator * this->denom;

  new_frac.denom = this->denom * frac.denom;
  new_frac.shorten_frac();
  return new_frac;
}

int fraction::gcd(int a, int b) { return std::gcd(a, b); }
