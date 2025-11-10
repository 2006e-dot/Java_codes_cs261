#include <bits/stdc++.h>
using namespace std;
class Shape {
private:
    double radius;
    double side;

public:
    void setRadius(double r){
        radius = r;
    }
    void setSide(double s){
        side = s;
    }

    double getRadius(){
        return radius;
    }
    double getSide(){
        return side;
    }
    virtual double area() = 0;

    void show() {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:
    
    void setDimension(double r) {
        setRadius(r);
    }

    
    double area() override {
        return M_PI * pow(getRadius(), 2);
    }
};

class Square : public Shape {
public:
    
    void setDimension(double s) {
        setSide(s);
    }

    double area() override {
        return pow(getSide(), 2);
    }
};

int main() {
    Circle c;
    c.setDimension(5);
    c.show();
    cout << "Area of Circle: " << c.area() << endl;

    Square s;
    s.setDimension(4);
    s.show();
    cout << "Area of Square: " << s.area() << endl;

    return 0;
}