#pragma once 

#include <iostream>

class Fraction {
private:
    long long numerator;                //numerator
    unsigned long long denominator;     //denominator
    
    double _eps = 1e-6;                 //Accuracity of Fraction == double operator
public:
    /*                  CONSTRUCTORS OVERLOADING                    */
    Fraction(int n, int d);     // Create fraction with numerator = n, denominator = d
    Fraction(int n);            // Create fraction with numerator = n, denominator = 1
    Fraction();                 // Create fraction with numerator = 0, denominator = 1


    /*                  SIMPLIFICATION                              */
    void simplification();      // Simplificate fraction

    /*                  GETTERS AND SETTERS                         */
    void _set_eps(double eps);

    /*                  OPERATORS OVERLOADING                       */
    // Fraction with fraction
    Fraction    operator + (const Fraction what);   // +
    Fraction    operator - (const Fraction what);   // -
    Fraction    operator * (const Fraction what);   // *
    Fraction    operator / (const Fraction what);   // /
    Fraction    operator = (const Fraction what);   // =
    void        operator += (const Fraction what);  // += 
    void        operator -= (const Fraction what);  // -=
    void        operator /= (const Fraction what);  // /=
    bool        operator < (Fraction what);         // <
    bool        operator > (Fraction what);         // >
    bool        operator == (Fraction what);        // ==

    // Fraction with int long and long long
    Fraction    operator = (long long what);        // =
    bool        operator < (long long what);        // <
    bool        operator > (long long what);        // >
    bool        operator == (long long what);       // ==
    
    
    // Fraction with double and float
    bool        operator < (double what);           // <
    bool        operator > (double what);           // >
    bool        operator == (double what);          // == NEED TO SET UP EPS!


    /*                  OS AND IS STREAM OVERLOADING             */
    friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
    friend std::istream& operator>>(std::istream& is, Fraction& obj);

    // Abs
    friend Fraction abs(const Fraction& num);
};