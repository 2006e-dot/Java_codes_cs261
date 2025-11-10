#include<bits/stdc++.h>
using namespace std;
class Student {
public:
    int roll;
    string name;
    int age;
public:
    void getStudentData() {
        cout << "Enter Roll No, Name and Age: ";
        cin >> roll >> name >> age;
    }
    int getAge() { 
        return age; 
    }
};
class UGStudent : public Student {
public:
    int semester;
    float fees, stipend;
public:
    void getUGData() {
        getStudentData();
        cout << "Enter Semester, Fees and Stipend: ";
        cin >> semester >> fees >> stipend;
    }
    void display() {
        cout << "Rollnumber" << roll<<endl;
        cout<<"Name" << name<<endl;
        cout<< "Age " << age<<endl; 
        cout<< "Semester"<<semester<<endl;
        cout<< "Fees" <<fees<<endl;
        cout<< " Stipend: " << stipend << endl;
    }
};
int main() {
    int n;
    cin>>n;
    UGStudent ug[n];
    int totalAge=0;
    cout << "Enter data for " << n << " UG Students"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Student "<<i + 1 <<endl;
        ug[i].getUGData();
        totalAge += ug[i].getAge();
    }

    cout << "Student Details";
    for (int i=0;i<n;i++) {
        ug[i].display();
    }
    cout << "Average Age of UG Students = "<<(float)totalAge / n << endl;
    return 0;
}