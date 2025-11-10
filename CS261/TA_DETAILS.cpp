#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name="unknown";
    int age=0;
    Person(string n,int a){
        name=n;
        age=a;
    }
    void setPerson(string n,int a){
        name=n;
        age=a;
    }
    void displayPerson(){
        cout<<"Name: "<<name<<", Age: "<<age<<endl;
    }
};
class Student:virtual public Person{
    public:
    int rollno;
    string course;
    Student(string n,int a,int r,string course):Person(n,a){
        rollno=r;
        this->course=course;
    }
    void setStudent(string n,int a,int r,string course){
        setPerson(n,a);
        rollno=r;
        this->course=course;
    }
    void displayStudent(){
        displayPerson();
        cout<<"Roll No: "<<rollno<<", Course: "<<course<<endl;
    }

};
class Faculty:virtual public Person{
    public:
    string department;
    int facultyid;
    Faculty(string n,int a,string d,int f):Person(n,a){
        department=d;
        facultyid=f;
    }
    void setFaculty(string n,int a,string d,int f){
        setPerson(n,a);
        department=d;
        facultyid=f;
    }
    void displayFaculty(){
        displayPerson();
        cout<<"Faculty ID: "<<facultyid<<", Department: "<<department<<endl;
    }
};
class TA:public Student,public Faculty{
    public:
    int workinghours;
    TA(string n,int a,int r,string course,string d,int f,int workinghours):Student(n,a,r,course),Faculty(n,a,d,f),Person(n,a){
        this->workinghours=0;
    }
    void setTA(string n,int a,int r,string course,string d,int f){
        setPerson(n,a);
        Student::setStudent(n,a,r,course);
        Faculty::setFaculty(n,a,d,f);
    }
    void displayTA(){
        Person::displayPerson();
        cout<<"Roll No: "<<rollno<<", Course: "<<course<<endl;
        cout<<"Faculty ID: "<<facultyid<<", Department: "<<department<<endl;
    }
};
int main(){
    TA ta("Ayush",18,202451029,"CSE","CSE",1029,20);
    ta.displayTA();
    ta.setTA("Ritik",19,202451030,"CSE","CSE",1030);
    ta.displayTA();
    return 0;   
}