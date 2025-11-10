#include<bits/stdc++.h>
using namespace std;
class Circle{
    public:
    double radius;
    void getinputradius(){
        cout<<"Enter radius of circle"<<endl;
        cin>>radius;
    }
    void circlearea(){
         cout<<(double)3.14*radius*radius<<endl;
    }
};
class Rectangle:public Circle{
    public:
    double width;
    void getwidth(){
        cout<<"Enter the width of rectangle"<<endl;
        cin>>width;
    }
    void rectanglearea(){
        cout<<(double)(width*radius)<<endl;
    }
};
int main(){
    Circle c;
    Rectangle r;
    r.getinputradius();
    r.circlearea();
    r.getwidth();
    r.rectanglearea();
}