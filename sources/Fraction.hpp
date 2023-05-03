#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <cmath>
using namespace std;
namespace ariel {

class Fraction {
private:
  int numerator;
  int denominator;
  

public:
  Fraction();
  Fraction(int num, int denominator);
  Fraction(float num, float denominator);
  Fraction(float num);

    // opertors
  Fraction operator+(const Fraction &other);
  Fraction operator-(const Fraction &other);
  Fraction operator*(const Fraction &other);
  Fraction operator/(const Fraction &other);

  // bool opertors
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator>(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;

  //prefix &postfix
   Fraction &operator++();   
  Fraction operator++(int);  
  Fraction &operator--();   
  Fraction operator--(int); 

// get a float number and return the float as Fraction
static Fraction floatToFraction(float num); // taken from gpt
// opertors fruncsion and oprison   
  friend Fraction operator+(const float &f_num, const Fraction &frac) {   
    Fraction temp = floatToFraction(f_num);
    float lc = lcm(temp.denominator,frac.denominator);
    float numor = (temp.numerator * (lc/temp.denominator)) + (frac.numerator * (lc/frac.denominator));
    return Fraction(numor, lc);
  }
  friend Fraction operator-(const float &f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    float lc = lcm(temp.denominator,frac.denominator);
    float numor = (temp.numerator * (lc/temp.denominator)) - (frac.numerator * (lc/frac.denominator));
    return Fraction(numor, lc);
  }
  friend Fraction operator*(float f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    float num = temp.numerator * frac.numerator;
    float denom = temp.denominator*frac.denominator;
    return Fraction(num, denom);
  }
  friend Fraction operator/(const float &f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    if (frac.numerator == 0 || temp.denominator == 0) {
      throw "Error: cannot divide by zero.";
      return frac;
    }
    float num = temp.numerator * frac.denominator;
    float denom = temp.denominator * frac.numerator;
    return Fraction(num, denom);
  }

// bool opertors 
  friend bool operator==(float f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp == frac);
  }
  friend bool operator==(const Fraction &frac, float f_num) {
   Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp == frac);
  }
  friend bool operator>(float f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp > frac);
  }
  friend bool operator>(const Fraction &frac, float f_num) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (frac > temp);
  }
  friend bool operator<(float f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp < frac);
  }
  friend bool operator<(const Fraction &frac, float f_num) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (frac < temp);
  }
  friend bool operator>=(float f_num, const Fraction &frac) {
   Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp >= frac);
  }
  friend bool operator>=(const Fraction &frac, float f_num) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (frac >= temp);
  }
  friend bool operator<=(float f_num, const Fraction &frac) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (temp <= frac);
  }
  friend bool operator<=(const Fraction &frac, float f_num) {
    Fraction temp = floatToFraction(f_num);
    temp.reduce();
    return (frac <= temp);
  }
 
 //ostream and istream
  friend ostream &operator<<(ostream &ostrea, const Fraction &frac) {
    ostrea << frac.numerator << "/" << frac.denominator;
    return ostrea;
  }

  friend istream &operator>>(istream &istrea, Fraction &frac) {
    int numurt = 0;
    int denom = 1;

    if (!(istrea >> numurt >> denom)) {
      throw runtime_error("Invalid input format");
    }

    if (denom == 0) {
      throw runtime_error("Divide by zero");
    }

    frac = Fraction(numurt, denom);
    frac.reduce();

    return istrea;
  }

  int getNumerator();
  int getDenominator();
  void reduce();
  static int gcd(int num, int denominator);
  static int lcm(int num, int denominator);

  
};
} // namespace ariel
#endif