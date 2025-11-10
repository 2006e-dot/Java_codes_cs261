#include<bits/stdc++.h>
using namespace std;
class Vehicle {
private:
	string brand;
	string model;
	int speed;

public:
	Vehicle(string brandName = "", string modelName = "", int s = 0){
        brand = brandName;
        model = modelName;
        speed = s;
    }

	string getBrand(){ 
        return brand; 
    }
	string getModel(){ 
        return model; 
    }
	int getSpeed(){ 
        return speed; 
    }

	void setBrand(string b){
        brand = b; 
    }
	void setModel(string m){ 
        model = m; 
    }
	void setSpeed(int s){ 
        speed = s; 
    }

	virtual void startEngine() = 0;
	virtual void stopEngine() = 0;
};
class Maintenance {
public:
	virtual void service() = 0;
	virtual void checkOil() = 0;
};

class Car : public Vehicle, public Maintenance {
public:
	Car(string brand = "", string model = "", int speed = 0): Vehicle(brand, model, speed)
		 {}

	void startEngine() override {
		cout << "Car " << getBrand() << " " << getModel() << ": Engine started."<<endl;
	}

	void stopEngine() override {
		cout << "Car " << getBrand() << " " << getModel() << ": Engine stopped."<<endl;
	}

	void service() override {
		cout << "Car " << getBrand() << " " << getModel() << ": Serviced (oil change, inspection)."<<endl;
	}

	void checkOil() override {
		cout << "Car " << getBrand() << " " << getModel() << ": Oil level OK."<<endl;
	}
};

class Bike : public Vehicle, public Maintenance {
public:
	Bike(string brand = "", string model = "", int speed = 0): Vehicle(brand, model, speed)
		 {}

	void startEngine() override {
		cout << "Bike " << getBrand() << " " << getModel() << ": Engine started."<<endl;
	}

	void stopEngine() override {
		cout << "Bike " << getBrand() << " " << getModel() << ": Engine stopped."<<endl;
	}

	void service() override {
		cout << "Bike " << getBrand() << " " << getModel() << ": Serviced (chain, brakes checked)."<<endl;
	}

	void checkOil() override {
		cout << "Bike " << getBrand() << " " << getModel() << ": Oil level OK (if applicable)."<<endl;
	}
};

int main() {
	Car myCar("Toyota", "Corolla", 120);
	Bike myBike("Yamaha", "MT-15", 100);
	Vehicle *vptr = &myCar;
	cout << "Using Vehicle* to refer to a Car:"<<endl;
	vptr->startEngine();   
	vptr->stopEngine(); 
	cout << endl;
	vptr = &myBike;
	cout << "Using Vehicle* to refer to a Bike:"<<endl;
	vptr->startEngine();   
	vptr->stopEngine();    
	cout << endl;
	cout << "Car brand: " << myCar.getBrand() << ", model: " << myCar.getModel() << ", speed: " << myCar.getSpeed() << "\n";
	myCar.setSpeed(130);
	cout << "Updated car speed: " << myCar.getSpeed() << " km/h"<<endl;
	Maintenance *mPtr = &myCar;
	mPtr->checkOil();
	mPtr->service();
	cout << endl;
	mPtr = &myBike;
	mPtr->checkOil();
	mPtr->service();

	return 0;
}