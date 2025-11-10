#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string name;
    int empid;
    double basesalary;

public:
    Employee(string n, int e, double b) {
        name = n;
        empid = e;
        basesalary = b;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empid << endl;
        cout << "Base Salary: " << basesalary << endl;
    }

    double getBaseSalary(){
        return basesalary;
    }

    virtual double calculateSalary() = 0;
};

class TaxDetails {
public:
    virtual double taxCalculation(double salary) = 0;
};

class FullTimeEmployee : virtual public Employee, virtual public TaxDetails {
private:
    double HRA;

public:
    FullTimeEmployee(string n, int e, double b, double hra)
        : Employee(n, e, b), HRA(hra) {}

    void displayDetails()  {
        Employee::displayDetails();
        cout << "HRA: " << HRA << endl;
    }

    double calculateSalary() {
        return getBaseSalary() + HRA;
    }

    double taxCalculation(double salary) override {
        return salary * 0.2;
    }
};

class PartTimeEmployee : virtual public Employee, virtual public TaxDetails {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string n, int e, double hours, double rate)
        : Employee(n, e, 0), hoursWorked(hours), hourlyRate(rate) {}

    void displayDetails()  {
        Employee::displayDetails();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
    }

    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }

    double taxCalculation(double salary) override {
        return salary * 0.1;
    }
};

class Intern : virtual public Employee {
public:
    Intern(string n, int e, double b)
        : Employee(n, e, b) {}

    void displayDetails()  {
        Employee::displayDetails();
        cout << "Role: Intern (No tax applicable)" << endl;
    }

    double calculateSalary() {
        return getBaseSalary();
    }
};

int main() {
    FullTimeEmployee ft("Ayush", 1001, 50000.0, 100.0);
    PartTimeEmployee pt("Yash", 2002, 120.0, 1500.0);
    Intern intern("Uj", 3003, 400.0);

    Employee* emp;

    cout << "Employee Details and Salary/TAX computation" << endl;

    emp = &ft;
    emp->displayDetails();
    double salary1 = emp->calculateSalary();
    cout << "Computed Salary: "  << salary1
         << ", Tax: " << ft.taxCalculation(salary1) << endl;

    emp = &pt;
    emp->displayDetails();
    double salary2 = emp->calculateSalary();
    cout << "Computed Salary: " << salary2
         << ", Tax: " << pt.taxCalculation(salary2) << endl;

    emp = &intern;
    emp->displayDetails();
    double salary3 = emp->calculateSalary();
    cout << "Computed Salary: "  << salary3
         << ", No tax information available." << endl;

    return 0;
}
