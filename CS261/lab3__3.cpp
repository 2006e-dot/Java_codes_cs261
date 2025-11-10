#include <bits/stdc++.h>
using namespace std;
class Shape {
public:
    double dim1, dim2;
public:
    void getData() {
        cout << "Enter two dimensions: ";
        cin >> dim1 >> dim2;
    }
    virtual void displayArea()=0;
};
class Triangle : public Shape {
public:
    void displayArea() override{
        cout << "Area=" << 0.5 * dim1 * dim2 << endl;
    }
};

class Rectangle : public Shape {
public:
    void displayArea() override{
        cout << "Area=" << dim1 * dim2 << endl;
    }
};

int main() {
    int choice;
    Shape *s;
    cout << "1)Triangle"<<endl;
    cout<<"2)Rectangle"<<endl;
    cout<<"Enter choice:"<<endl;
    cin >> choice;
    if (choice == 1) {
        Triangle t;
        t.getData();
        s = &t;
        s->displayArea();
    } 
    else {
        Rectangle r;
        r.getData();
        s=&r;
        s->displayArea();
    }

    return 0;
}