package Lab1;

class Person {
    protected String name;

    void setName(String n) {
        name = n;
    }

    void displayName() {
        System.out.println("Name: " + name);
    }
}

class Employee extends Person {
    private double salary;

    void setSalary(double s) {
        salary = s;
    }

    void displaySalary() {
        System.out.println("Salary: " + salary);
    }
}

public class one {
    public static void main(String[] args) {
        Employee e = new Employee();
        e.setName("Ayush");
        e.setSalary(50000);

        e.displayName();
        e.displaySalary();
    }
}
