package Lab2;

class Circle {
    protected double radius;

    void setRadius(double r) {
        radius = r;
    }

    double areaCircle() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Circle {
    private double breadth;

    void setRectangle(double l, double b) {
        radius = l;
        breadth = b;
    }

    double areaRectangle() {
        return radius * breadth;
    }
}

public class one {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle();
        rect.setRadius(5);
        System.out.println("Area of Circle: " + rect.areaCircle());
        rect.setRectangle(5, 10);
        System.out.println("Area of Rectangle: " + rect.areaRectangle());
    }
}
