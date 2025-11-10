package Lab1;

class Person {
    private String name;
    private String city;

    void setData(String n, String c) {
        name = n;
        city = c;
    }

    void displayData() {
        System.out.println("Name: " + name);
        System.out.println("City: " + city);
    }
}

class Employee {
    private String name;
    private double salary;

    void setData(String n, double s) {
        name = n;
        salary = s;
    }

    void displayData() {
        System.out.println("Employee Name: " + name);
        System.out.println("Salary: " + salary);
    }
}

public class two {
    public static void main(String[] args) {
        Person p = new Person();
        Employee e = new Employee();
        p.setData("Ayush", "Surat");
        e.setData("Ayush", 50000);
        System.out.println("--- Person Details ---");
        p.displayData();
        System.out.println("\n--- Employee Details ---");
        e.displayData();
    }
}
