#include<bits/stdc++.h>
using namespace std;
class Employee {
protected:
    string name;
    int empID;
    const string companyName;
    static int totalEmployees;
public:
    Employee(string n, int id, string cname) : name(n), empID(id), companyName(cname) { totalEmployees++; }
    virtual ~Employee() { totalEmployees--; }
    virtual double calculateSalary() const = 0;
    static void showEmployeeCount() { 
        cout << "Total Employees: " << totalEmployees << endl;
    }

};
int Employee::totalEmployees = 0;

class PermanentEmployee : public Employee {
protected:
    double basicSalary, bonus;
public:
    PermanentEmployee(string n, int id, string cname, double b, double bo)
        : Employee(n, id, cname), basicSalary(b), bonus(bo) {}
    double calculateSalary() const override { return basicSalary + bonus; }
};

class ContractEmployee : public Employee {
protected:
    double hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(string n, int id, string cname, double rate, int hours)
        : Employee(n, id, cname), hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() const override { return hourlyRate * hoursWorked; }
};

class Intern final : public Employee {
protected:
    double stipend;
public:
    Intern(string n, int id, string cname, double s)
        : Employee(n, id, cname), stipend(s) {}
    double calculateSalary() const override { return stipend; }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new PermanentEmployee("Alice", 1, "TechCorp", 50000, 5000));
    employees.push_back(new ContractEmployee("Bob", 2, "TechCorp", 200, 120));
    employees.push_back(new Intern("Charlie", 3, "TechCorp", 10000));
    employees.push_back(new PermanentEmployee("Ayush",2,"Apple",100000,40000));

    Employee::showEmployeeCount();
    for (auto e : employees) cout << e->calculateSalary() << endl;

    for (auto e : employees) delete e;
    Employee::showEmployeeCount();
    return 0;
}