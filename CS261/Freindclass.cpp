#include <bits/stdc++.h>
using namespace std;
class Fraction {
private:
    int num, den;   
    void simplyfy(){
        int g=__gcd(abs(num),abs(den));
        num/=g;
        den/=g;
        if(den<0){
            num=-num;
            den=-den;
        }
    }
public:
    Fraction(int n=0, int d=1) {
        num = n;
        den = d;
        simplyfy();
    }

    void show() {
        cout << num << "/" << den << endl;
    }

    Fraction operator/(Fraction f) {
        Fraction temp;
        temp.num = num * f.den;
        temp.den = den * f.num;
        temp.simplyfy();
        return temp;
    }

    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
};
Fraction operator+(Fraction a, Fraction b) {
    Fraction temp;
    temp.num = a.num * b.den + b.num * a.den;
    temp.den = a.den * b.den;
    temp.simplyfy();
    return temp;
}

Fraction operator-(Fraction a, Fraction b) {
    Fraction temp;
    temp.num = a.num * b.den - b.num * a.den;
    temp.den = a.den * b.den;
    temp.simplyfy();
    return temp;
}

Fraction operator*(Fraction a, Fraction b) {
    Fraction temp;
    temp.num = a.num * b.num;
    temp.den = a.den * b.den;
    temp.simplyfy();
    return temp;
}

int main() {
    Fraction f1(3,4), f2(1,2);

    Fraction sum = f1 + f2;
    cout<<"Sum: "; sum.show();      

    Fraction diff = f1 - f2;
    cout<<"Diff: "; diff.show();

    Fraction mul = f1 * f2;
    cout<<"Mul: "; mul.show();

    Fraction div = f1 / f2;
    cout<<"Div: "; div.show();

    return 0;
}