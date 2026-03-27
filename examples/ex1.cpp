#include <iostream>
#include <fraction>

using namespace std;

int main() { //
    Fraction fr1, fr2;

    cout << "Write fractions" << endl;
    cin >> fr1 >> fr2;
    cout << fr1 + fr2 << endl;
    cout << fr1 - fr2 << endl;
    cout << fr1 * fr2 << endl;
    cout << fr1 / fr2 << endl;
    int a;

    cout << "Write int number" << endl;
    cin >> a;
    cout << fr1 + a << endl;
    cout << fr1 - a << endl;
    cout << fr1 * a << endl;
    cout << fr1 / a << endl;
    return 0;
}