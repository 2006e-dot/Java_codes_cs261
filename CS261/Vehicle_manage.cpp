#include<bits/stdc++.h>
using namespace std;
class Vehicle {
protected:
    string vehicleName;

public:
    Vehicle(string name) : vehicleName(name) {}
    virtual double calculateFare() = 0;
    virtual void display() {
        cout << "Vehicle: " << vehicleName << endl;
    }
};

class Bus : public Vehicle {
    double distance;
    double farePerKm;

public:
    Bus(string name, double dist, double fare) 
        : Vehicle(name), distance(dist), farePerKm(fare) {}

    double calculateFare() override{
        return distance * farePerKm;
    }

    //double operator+(Bus &other) {
    //    return this->calculateFare() + other.calculateFare();
    //}

    void display() override{
        cout << "Bus: " << vehicleName <<endl;
        cout<< "Distance: " << distance <<endl;
        cout<< " Fare per km: " << farePerKm <<endl;
        cout<< " Total Fare: " << calculateFare() << endl;
    }
};

class Taxi : public Vehicle {
    double hours;
    double ratePerHour;

public:
    Taxi(string name, double hrs, double rate) 
        : Vehicle(name), hours(hrs), ratePerHour(rate) {}

    double calculateFare() override {
        return hours * ratePerHour;
    }

    void display() override {
        cout << "Taxi: " << vehicleName <<endl;
        cout  << "Hours: " << hours <<endl;
        cout << "Rate per hour: " << ratePerHour <<endl;
        cout << "Total Fare: " << calculateFare() << endl;
    }
};

double operator+(Bus lhs, Bus rhs) {
    // Accesses public calculateFare() method of each object
    return lhs.calculateFare() + rhs.calculateFare();
}

int main() {
    Vehicle* v1 = new Bus("Volvo", 120, 5);
    Vehicle* v2 = new Taxi("Ola", 3, 200);
   Vehicle *v3= new Taxi("Uber",3,200);

    v1->display();
    v2->display();
    v3->display();
    Bus b1("LuxuryBus", 100, 6);
    Bus b2("MiniBus", 80, 5);

    b1.display();
    b2.display();

    double totalFare = b1 + b2;
    cout<< totalFare <<endl;

    return 0;
}