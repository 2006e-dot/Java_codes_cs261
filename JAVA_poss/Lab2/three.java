package Lab2;

import java.util.Scanner;

class Shape {
    protected double dim1;
    protected double dim2;

    void getData(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }
}

class Triangle extends Shape {
    void displayArea() {
        double area = 0.5 * dim1 * dim2;
        System.out.println("Area of Triangle: " + area);
    }
}

class Rectangle extends Shape {
    void displayArea() {
        double area = dim1 * dim2;
        System.out.println("Area of Rectangle: " + area);
    }
}

public class three {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Choose shape (1 - Triangle, 2 - Rectangle): ");
        int choice = sc.nextInt();
        if (choice == 1) {
            Triangle t = new Triangle();
            System.out.print("Enter base and height: ");
            double b = sc.nextDouble();
            double h = sc.nextDouble();
            t.getData(b, h);
            t.displayArea();
        } else if (choice == 2) {
            Rectangle r = new Rectangle();
            System.out.print("Enter length and breadth: ");
            double l = sc.nextDouble();
            double b = sc.nextDouble();
            r.getData(l, b);
            r.displayArea();
        } else {
            System.out.println("Invalid choice");
        }
        sc.close();
    }
}
