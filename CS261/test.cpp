#include <iostream>
using namespace std;

class Fraction {
    int num, den;   // numerator, denominator
public:
    Fraction(int n=0, int d=1) {
        num = n;
        den = d;
    }

    void show() {
        cout << num << "/" << den << endl;
    }

    // + operator
    Fraction operator+(Fraction f) {
        Fraction temp;
        temp.num = num * f.den + f.num * den;
        temp.den = den * f.den;
        return temp;
    }

    // - operator
    Fraction operator-(Fraction f) {
        Fraction temp;
        temp.num = num * f.den - f.num * den;
        temp.den = den * f.den;
        return temp;
    }

    // * operator
    Fraction operator*(Fraction f) {
        Fraction temp;
        temp.num = num * f.num;
        temp.den = den * f.den;
        return temp;
    }

    // / operator
    Fraction operator/(Fraction f) {
        Fraction temp;
        temp.num = num * f.den;
        temp.den = den * f.num;
        return temp;
    }
};

int main() {
    Fraction f1(3,4), f2(1,2);

    cout << "Sum: "; (f1 + f2).show();
    cout << "Diff: "; (f1 - f2).show();
    cout << "Mul: "; (f1 * f2).show();
    cout << "Div: "; (f1 / f2).show();

    return 0;
}