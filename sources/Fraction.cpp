#include "Fraction.hpp"

#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace ariel;
using namespace std;
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
}
Fraction::Fraction(float num, float denom): numerator(num), denominator(denom) {
}

Fraction::Fraction(float num) {
}

Fraction Fraction::operator+(const Fraction &other) {
  return Fraction(1, 1);
}

Fraction Fraction::operator-(const Fraction &other) {
  return Fraction(1, 1);
}

Fraction Fraction::operator*(const Fraction &other) {
  return Fraction(1, 1);
}

Fraction Fraction::operator/(const Fraction &other) {
  return Fraction(1, 1);
}

bool Fraction::operator==(const Fraction &other) const {
   return true;
}

bool Fraction::operator!=(const Fraction &other) const {
  return true;
}

bool Fraction::operator>(const Fraction &other) const {
  return true;
}

bool Fraction::operator<(const Fraction &other) const {
  return true;
}

bool Fraction::operator>=(const Fraction &other) const {
  return true;
}

bool Fraction::operator<=(const Fraction &other) const {
  return true;
}

Fraction &Fraction::operator++() { // taken from gpt
  return *this;
}

Fraction Fraction::operator++(int) {// taken from gpt
  Fraction temp(*this);
  return temp;
}
Fraction &Fraction::operator--() {// taken from gpt
  return *this;
}
Fraction Fraction::operator--(int) {// taken from gpt
  Fraction temp(*this);
  return temp;
}

void Fraction::reduce() {
}

int Fraction::gcd(int a, int b) { //taken feom gpt
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int Fraction::getNumerator() { return 1; }
int Fraction::getDenominator() { return 2;}

int Fraction::lcm(int a, int b) {//taken feom gpt
  return ((a * b) / gcd(a, b));
};

Fraction Fraction::floatToFraction(float num) { // taken from gpt
  int decimal_places = 0;
  float temp = num;

  // Count the number of decimal places
  while (temp != floor(temp)) {
    decimal_places++;
    temp *= 10;
  }

  // Multiply numerator and denominator by 10^decimal_places
  int numerat = num * pow(10, decimal_places);
  int denominat = pow(10, decimal_places);

  // Simplify the fraction
  int gcd_ = gcd(numerat, denominat);
  numerat /= gcd_;
  denominat /= gcd_;

  return Fraction(numerat, denominat);
}

