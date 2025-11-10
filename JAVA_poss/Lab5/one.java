package Lab5;

abstract class Vehicle {
    protected String vehicleName;

    Vehicle(String vehicleName) {
        this.vehicleName = vehicleName;
    }

    abstract double calculateFare();
}

class Bus extends Vehicle {
    private double distance;
    private double farePerKm;

    Bus(String vehicleName, double distance, double farePerKm) {
        super(vehicleName);
        this.distance = distance;
        this.farePerKm = farePerKm;
    }

    double calculateFare() {
        return distance * farePerKm;
    }

    Bus addBus(Bus other) {
        double totalDistance = this.distance + other.distance;
        double totalFare = this.calculateFare() + other.calculateFare();
        Bus combined = new Bus(this.vehicleName + " + " + other.vehicleName, totalDistance, totalFare / totalDistance);
        return combined;
    }

    void display() {
        System.out.println("Bus: " + vehicleName + ", Distance: " + distance + ", Fare per km: " + farePerKm + ", Total Fare: " + calculateFare());
    }
}

class Taxi extends Vehicle {
    private double hours;
    private double ratePerHour;

    Taxi(String vehicleName, double hours, double ratePerHour) {
        super(vehicleName);
        this.hours = hours;
        this.ratePerHour = ratePerHour;
    }

    double calculateFare() {
        return hours * ratePerHour;
    }

    void display() {
        System.out.println("Taxi: " + vehicleName + ", Hours: " + hours + ", Rate per hour: " + ratePerHour + ", Total Fare: " + calculateFare());
    }
}

public class one {
    public static void main(String[] args) {
        Vehicle v1 = new Bus("City Express", 120, 10.5);
        Vehicle v2 = new Taxi("FastCab", 5, 200);

        System.out.println("--- Polymorphism Demonstration ---");
        System.out.println(v1.vehicleName + " Fare: " + v1.calculateFare());
        System.out.println(v2.vehicleName + " Fare: " + v2.calculateFare());

        System.out.println("\n--- Operator Overloading Simulation (Bus + Bus) ---");
        Bus b1 = new Bus("Bus1", 100, 8);
        Bus b2 = new Bus("Bus2", 150, 10);
        Bus b3 = b1.addBus(b2);
        b1.display();
        b2.display();
        System.out.println("After adding:");
        b3.display();
    }
}
