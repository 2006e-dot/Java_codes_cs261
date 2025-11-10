#include <bits/stdc++.h>
using namespace std;

class Person {
    string name;
    string city;
public:
    void setName(string s,string c) { 
        name=s; 
        city=c;

    }
    void displayName() { 
        cout<<"Name:"<<name<<endl;
        cout<<"City:"<<city<<endl; 
    }
};
class Employee:public Person {
    double salary;
public:
    void setSalary(double s) { 
        salary = s; 
    }
    void displaySalary() { 
        cout<<"Salary: ₹"<<salary<<endl; 
    }
};
int main() {
    Employee e;
    cout<<"Employee Details: "<<endl;
    e.setName("Ayush","Rajkot");
    e.setSalary(50000);
    e.displayName();
    e.displaySalary();
    return 0;
}