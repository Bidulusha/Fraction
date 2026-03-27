#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "fraction.hpp"

/*                  CONSTRUCTORS                    */
Fraction::Fraction(int n, int d){
    if (d == 0){
        std::cout << "Denominator can't be zero!\n";
		n = 0;
		d = 1;
    }
    numerator = n;
    denominator = d;

    simplification();
}

Fraction::Fraction(int n){
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

/*                          SIMPLIFICATION                    */
void Fraction::simplification() {
    if (numerator == 0) {
        denominator = 1;
        return;
    }

    long long a = abs(numerator);
    long long b = denominator;

    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }

    numerator /= a;
    denominator /= a;
    
}

/*                      GETTERS AND SETTERS                 */
void Fraction::set_eps(double eps) {
    this->eps = eps;
}

/*              OPERATORS OVERLOADING (ONLY MATH)           */
// Fractoin with fraction
Fraction Fraction::operator + (const Fraction what){
    return Fraction(
        numerator * what.denominator + what.numerator * denominator,
        what.denominator * denominator
    );
}


Fraction Fraction::operator - (const Fraction what){
    return Fraction(
        numerator * what.denominator - what.numerator * denominator,
        what.denominator * denominator
    );
}

Fraction Fraction::operator * (const Fraction what){
    return Fraction(
        numerator * what.numerator,
        what.denominator * denominator
    );
}

Fraction Fraction::operator / (const Fraction what){
    if (what.numerator == 0) {
        std::cout << "Divizion by zero!\n";
		return *this;
    }
    else {
        return Fraction(
            numerator * what.denominator,
            denominator * abs(what.numerator)
        );
    }
    
}

void Fraction::operator += (const Fraction what){
    numerator = numerator * what.denominator + what.numerator * denominator;
    denominator = what.denominator * denominator;

    simplification();
}

void Fraction::operator -= (const Fraction what){
    numerator = numerator * what.denominator - what.numerator * denominator;
    denominator = what.denominator * denominator;
    
    simplification();
}

void Fraction::operator /= (const Fraction what){
    if (what.numerator == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        numerator = numerator * what.denominator;
        denominator = abs(what.numerator) * denominator;
    }

    simplification();
}

Fraction Fraction::operator = (const Fraction what){
    numerator = what.numerator;
    denominator = what.denominator;
    
    return *this;
}

bool Fraction::operator < (Fraction what){
    return ((double) numerator / denominator) < ((double) what.numerator / what.denominator);
}

bool Fraction::operator > (Fraction what){
    return ((double) numerator / denominator) > ((double) what.numerator / what.denominator);
}

bool Fraction::operator == (Fraction what){
    return (numerator == what.numerator) && (denominator == what.denominator);
}

// With int, long and long long
Fraction Fraction::operator = (long long what){
    numerator = what;
    denominator = 1;

    return *this;
}

bool Fraction::operator < (long long what){
    return (((double)numerator / denominator) < what);
}

bool Fraction::operator > (long long what){
    return (((double)numerator / denominator) > what);
}

bool Fraction::operator == (long long what){
    return (numerator == what) && (denominator == 1);
}

// With double
bool Fraction::operator < (double what){
    return ((double) numerator / denominator) < what;
}

bool Fraction::operator > (double what){
    return ((double) numerator / denominator) > what;
}

bool Fraction::operator == (double what) {
    return ((abs((double) numerator / denominator) - abs(what)) < eps);
}

/*                  OS AND IS STREAM OVERLOADING             */
std::istream& operator>>(std::istream& is, Fraction& obj) {
    std::string temp;
    int ind;

    is >> temp;

    ind = temp.find("/");
    if (ind == -1) {
        obj.numerator = stoi(temp);
        obj.denominator = 1;
    }
    else {
        obj.numerator = stoi(temp.substr(0, ind));
        temp.erase(0, ind + 1);
        obj.denominator = stoi(temp);
    }

    return is;
}

std::ostream& operator<<(std::ostream&os, const Fraction& obj){
    if (obj.denominator == 1) os << obj.numerator;
    else os << obj.numerator << "/" << obj.denominator;
    return os;
}

/*              OVERLOADING BASE FUNCTIONS                  */
Fraction abs(const Fraction& num){
    return Fraction(abs(num.numerator), num.denominator);
}
