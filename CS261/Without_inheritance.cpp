#include <bits/stdc++.h>
using namespace std;
class Person {
    string name,city;
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
class Employee{
    double salary;
    string name;
public:
    void setSalary(double s,string a) { 
        salary=s;
        name=a;
    }
    void displaySalary() { 
        cout<<"Salary: ₹ "<<fixed<<setprecision(0)<<salary<<endl; 
    }
};
int main() {
    cout<<"Employee Details:"<<endl;
    Person p;
    p.setName("Ayush","Rajkot");
    p.displayName();
    Employee e;
    e.setSalary(1000000,"Lokesh");
    e.displaySalary();
    return 0;
}