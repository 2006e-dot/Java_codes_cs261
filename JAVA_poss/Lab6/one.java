package Lab6;

class Fraction {
    private int numerator;
    private int denominator;

    Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        simplify();
    }

    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    private void simplify() {
        int g = gcd(Math.abs(numerator), Math.abs(denominator));
        numerator /= g;
        denominator /= g;
    }

    Fraction add(Fraction f) {
        int num = numerator * f.denominator + f.numerator * denominator;
        int den = denominator * f.denominator;
        return new Fraction(num, den);
    }

    Fraction subtract(Fraction f) {
        int num = numerator * f.denominator - f.numerator * denominator;
        int den = denominator * f.denominator;
        return new Fraction(num, den);
    }

    Fraction multiply(Fraction f) {
        int num = numerator * f.numerator;
        int den = denominator * f.denominator;
        return new Fraction(num, den);
    }

    Fraction divide(Fraction f) {
        int num = numerator * f.denominator;
        int den = denominator * f.numerator;
        return new Fraction(num, den);
    }

    void display() {
        System.out.println(numerator + "/" + denominator);
    }
}

public class one {
    public static void main(String[] args) {
        Fraction f1 = new Fraction(2, 4);
        Fraction f2 = new Fraction(3, 5);

        System.out.print("f1 = "); f1.display();
        System.out.print("f2 = "); f2.display();

        Fraction sum = f1.add(f2);
        Fraction diff = f1.subtract(f2);
        Fraction prod = f1.multiply(f2);
        Fraction div = f1.divide(f2);

        System.out.println("\nAddition: "); sum.display();
        System.out.println("Subtraction: "); diff.display();
        System.out.println("Multiplication: "); prod.display();
        System.out.println("Division: "); div.display();
    }
}
