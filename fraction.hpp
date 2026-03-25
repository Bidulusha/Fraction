#pragma once 

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

class FractionNumber {
private:
    long long numerator;
    unsigned long long denominator;

public:
    // Constructors
    FractionNumber(int n, int d){
        if (d == 0){
            throw invalid_argument("denominator can't be zero!");
        }
        numerator = n;
        denominator = d;

        simplification();
    }

    FractionNumber(int n){
        numerator = n;
        denominator = 1;
    }

    FractionNumber(){
        numerator = 0;
        denominator = 1;
    }

    // Simplification
    void simplification() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }

        long long a = abs(numerator);
        long long b = denominator;

        while (b != 0) {
            a %= b;
            swap(a, b);
        }
        
        if (denominator == 0) {
            cout << *this << endl;
            cout << "HOW??" << endl;
        }

        numerator /= a;
        denominator /= a;
        
    }

    // Operators
    FractionNumber operator + (const FractionNumber what){
        return FractionNumber(
            numerator * what.denominator + what.numerator * denominator,
            what.denominator * denominator
        );
    }

    void operator += (const FractionNumber what){
        numerator = numerator * what.denominator + what.numerator * denominator;
        denominator = what.denominator * denominator;

        simplification();
    }

    FractionNumber operator - (const FractionNumber what){
        return FractionNumber(
            numerator * what.denominator - what.numerator * denominator,
            what.denominator * denominator
        );
    }

    void operator -= (const FractionNumber what){
        numerator = numerator * what.denominator - what.numerator * denominator;
        denominator = what.denominator * denominator;
        
        simplification();
    }

    FractionNumber operator * (const FractionNumber what){
        return FractionNumber(
            numerator * what.numerator,
            what.denominator * denominator
        );
    }

    FractionNumber operator / (const FractionNumber what){
        if (what.numerator == 0) {
            throw invalid_argument("Division by zero fraction!");
        }
        else {
            return FractionNumber(
                numerator * what.denominator,
                denominator * abs(what.numerator)
            );
        }
        
    }

    void operator /= (const FractionNumber what){
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

    FractionNumber operator = (const FractionNumber what){
        numerator = what.numerator;
        denominator = what.denominator;
        
        return *this;
    }

    FractionNumber operator = (int what){
        numerator = what;
        denominator = 1;

        return *this;
    }


    bool operator < (FractionNumber what){
        return ((double) numerator / (double) denominator) < ((double) what.numerator / (double) what.denominator);
    }

    bool operator > (FractionNumber what){
        return ((double) numerator / (double) denominator) > ((double) what.numerator / (double) what.denominator);
    }

    bool operator < (double what){
        return ((double) numerator / (double) denominator) < what;
    }

    bool operator > (double what){
        return ((double) numerator / (double) denominator) > what;
    }

    bool operator == (FractionNumber what){
        return (numerator == what.numerator) && (denominator == what.denominator);
    }

    // Ostream operator
    friend ostream& operator<<(std::ostream& os, const FractionNumber& obj);
    friend istream& operator>>(istream& is, FractionNumber& obj);

    // Abs
    friend FractionNumber abs(const FractionNumber& num);

};

ostream &operator<<(ostream &os, const FractionNumber& obj){
    string temp;
    if (obj.denominator == 1) temp = to_string(obj.numerator);
    else if (obj.numerator == 0) temp = "0";
    else temp = to_string(obj.numerator) + "/" + to_string(obj.denominator);
    
    os << temp;

    return os;
}   

istream& operator>>(istream& is, FractionNumber& obj) {
    string temp;
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

FractionNumber abs(const FractionNumber& num){
    return FractionNumber(abs(num.numerator), num.denominator);
}