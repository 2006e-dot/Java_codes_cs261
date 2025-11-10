#include <iostream>
using namespace std;

class Time {
    int hr, min, sec;
public:
    void setTime(int h, int m, int s) { 
        hr=h; 
        min=m; 
        sec=s; 
    }
    void display() { 
        cout<<hr<< ":"<<min<< ":"<<sec<<endl; 
    }
    Time add(Time t) {
        Time temp;
        temp.sec=sec+t.sec;
        temp.min=min+t.min+temp.sec/60;
        temp.sec%=60;
        temp.hr=hr+t.hr+temp.min/60;
        temp.min%=60;
        return temp;
    }
};

int main() {
    Time t1, t2, t3;
    t1.setTime(2, 45, 50);
    t2.setTime(3, 30, 20);
    t3 = t1.add(t2);
    cout << "Time 1: "; 
    t1.display();
    cout << "Time 2: "; 
    t2.display();
    cout << "Sum: ";    
    t3.display();
    return 0;
}