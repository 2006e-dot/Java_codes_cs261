#include<bits/stdc++.h>
using namespace std;
class Drone {
protected:
    string droneID;
    int batteryLevel;
    static int totalDeliveries;
public:
    Drone(string id, int battery) : droneID(id), batteryLevel(battery) {}
    virtual void deliverPackage() = 0;
    void setBatteryLevel(int level) { batteryLevel = level; }
    int getBatteryLevel() { return batteryLevel; }
    static void showTotalDeliveries() {
        cout << "Total Deliveries: " << totalDeliveries << endl;
    }
protected:
    void incrementDeliveries() { totalDeliveries++; }
};
int Drone::totalDeliveries = 0;

class CityDrone : public Drone {
public:
    CityDrone(string id, int battery) : Drone(id, battery) {}
    void deliverPackage() override {
        cout << "CityDrone " << droneID << " delivered a package within city limits."<<endl;
        incrementDeliveries();
    }
};

class IntercityDrone : public Drone {
public:
    IntercityDrone(string id, int battery) : Drone(id, battery) {}
    void deliverPackage() override {
        cout << "IntercityDrone " << droneID << " delivered a package to another city."<<endl;
        incrementDeliveries();
    }
};

class Package final {
public:
    int packageID;
    string weight;
    string destination;
    Package(int id, string w, string d) : packageID(id), weight(w), destination(d) {}
};

int main() {
    Drone* drones[4];
    drones[0] = new CityDrone("Rajkot", 90);
    drones[1] = new IntercityDrone("Gondal", 80);
    drones[2] = new CityDrone("Dakor", 75);
    drones[3] = new CityDrone("Mumbai",35);

    for (int i = 0; i < 4; i++) drones[i]->deliverPackage();
    Drone::showTotalDeliveries();

    return 0;
}