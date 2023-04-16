#include "Fraction.hpp"
#include <stdexcept>

using namespace std;

namespace ariel {

    // Constructor
    Fraction::Fraction ( int numerator,int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Addition operator
    Fraction Fraction::operator+(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return Fraction(new_num1 + new_num2, lcm);
    }

    // Subtraction operator
    Fraction Fraction::operator-(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return Fraction(new_num1 - new_num2, lcm);
    }


    // Multiplication operator
    Fraction Fraction::operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Division operator
    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Equality operator
    bool Fraction::operator==(const Fraction& other) const {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    // Greater than operator
    bool Fraction::operator>(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return (new_num1 > new_num2);
    }
    //1/2 > 1/3   lcm=

    // Less than operator
    bool Fraction::operator<(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return (new_num1 < new_num2);
    }

    // Greater than or equal to operator
    bool Fraction::operator>=(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return (new_num1 >= new_num2);
    }

    // Less than or equal to operator
    bool Fraction::operator<=(const Fraction& other) const {
        int lcm = denominator * other.denominator;
        int new_num1 = numerator * other.denominator;
        int new_num2 = other.numerator * denominator;
        return (new_num1 <= new_num2);
    }

    // Prefix increment operator
    Fraction& Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    // Prefix decrement operator
    Fraction& Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    // Postfix increment operator
    Fraction Fraction::operator++(int incer) {
        Fraction temp(numerator, denominator);
        numerator += denominator;
        return temp;
    }

    // Postfix decrement operator
    Fraction Fraction::operator--(int dcer) {
        Fraction temp(numerator, denominator);
        numerator -= denominator;
        return temp;
    }

    ostream& operator<<(ostream& os, const Fraction& f){
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    ostream& operator>>(ostream& os, const Fraction& f){
        os << "Fraction: " << f.numerator << "/" << f.denominator;
        return os;
    }
};