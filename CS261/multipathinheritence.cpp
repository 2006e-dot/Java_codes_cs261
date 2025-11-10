#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int roll;
    Student(string n,int r){
        name=n;
        roll=r;
    }
};
class Sports:virtual public Student{
    public:
    int sgrade;
    Sports(string n,int r,int sg):Student(n,r), sgrade(sg){}
};
class Exam:virtual public Student{
    public:
    int agrade;
    Exam(string n,int r,int ag):Student(n,r){
        agrade=ag;
    }
};
class Result:public Sports,public Exam{
    public:
    string finalgrade;
    Result(string n,int r,int sg,int ag,string fr):Student(n,r),Sports(n,r,sg),Exam(n,r,ag){
        finalgrade=fr;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<roll<<endl;
        cout<<"Sports Grade: "<<sgrade<<endl;
        cout<<"Academic Grade: "<<agrade<<endl;
        cout<<"Final Grade: "<<finalgrade<<endl;
        cout<<endl;
    }
};
int main(){
    Result r("Jatan Bhatt",21,9,10,"A+");
    Result r1("Ayush Bagdai",22,8,9,"A");
    r.display();
    r1.display();
    return 0;
}