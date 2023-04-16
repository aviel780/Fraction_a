#ifndef Fraction_hpp
#define Fraction_hpp
#include <iostream>

using namespace std;
namespace ariel{
    class Fraction{
        int numerator;
        int denominator;
        

        public:

        Fraction (int numerator, int denominator);
        // Fraction(double number);
        

        

        Fraction operator+(const Fraction& other) const;

        // friend Fraction operator+(const Fraction &other, const double &number);

        Fraction operator-(const Fraction& other) const;

        // friend Fraction operator-(const Fraction &other, const double &number);

        Fraction operator*(const Fraction& other) const; 

        // friend Fraction operator*(const double &number, const Fraction &other);

        Fraction operator/(const Fraction& other) const;
        
        bool operator==(const Fraction& other) const;

        bool operator>(const Fraction& other) const;

        bool operator>(const double &number) const;

        bool operator<(const Fraction& other) const;

        bool operator>=(const Fraction& other) const;

        bool operator<=(const Fraction& other) const;

        bool operator!=(const Fraction &other) const;

        Fraction& operator++(); // prefix

        Fraction& operator--(); // prefix

        Fraction operator++(int incer); // postfix

        Fraction operator--(int dcer); // postfix

        friend ostream& operator<<(ostream& os, const Fraction& f); // taken from gpt

        friend ostream& operator>>(ostream& os, const Fraction& f);// taken from gpt

        


    };
}



#endif