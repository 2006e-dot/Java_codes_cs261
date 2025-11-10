package Lab2;

import java.util.Scanner;

class Student {
    int rollNo;
    String name;
    int age;

    void setData(int r, String n, int a) {
        rollNo = r;
        name = n;
        age = a;
    }
}

class UGStudent extends Student {
    int semester;
    double fees;
    double stipend;

    void setUGData(int r, String n, int a, int sem, double f, double s) {
        setData(r, n, a);
        semester = sem;
        fees = f;
        stipend = s;
    }

    void display() {
        System.out.println("Roll No: " + rollNo + ", Name: " + name + ", Age: " + age + ", Semester: " + semester + ", Fees: " + fees + ", Stipend: " + stipend);
    }
}

public class two {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        UGStudent[] s = new UGStudent[2];
        int totalAge = 0;
        for (int i = 0; i < 2; i++) {
            s[i] = new UGStudent();
            System.out.println("Enter details of UG Student " + (i + 1) + ":");
            System.out.print("Roll No: ");
            int roll = sc.nextInt();
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Age: ");
            int age = sc.nextInt();
            System.out.print("Semester: ");
            int sem = sc.nextInt();
            System.out.print("Fees: ");
            double fees = sc.nextDouble();
            System.out.print("Stipend: ");
            double stipend = sc.nextDouble();
            s[i].setUGData(roll, name, age, sem, fees, stipend);
            totalAge += age;
        }
        double avgAge = totalAge / 2.0;
        System.out.println("\n--- UG Student Details ---");
        for (int i = 0; i < 2; i++) s[i].display();
        System.out.println("\nAverage Age of UG Students: " + avgAge);
    }
}
