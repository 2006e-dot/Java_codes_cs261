package Lab4;

interface Student {
    void displayStudent();
}

interface Sports extends Student {
    void displaySports();
}

interface Exam extends Student {
    void displayExam();
}

class Results implements Sports, Exam {
    private String name;
    private int rollNo;
    private int sGrade;
    private int eGrade;
    private String finalResult;

    public Results(String name, int rollNo, int sGrade, int eGrade, String finalResult) {
        this.name = name;
        this.rollNo = rollNo;
        this.sGrade = sGrade;
        this.eGrade = eGrade;
        this.finalResult = finalResult;
    }

    public void displayStudent() {
        System.out.println("Name: " + name + ", Roll No: " + rollNo);
    }

    public void displaySports() {
        System.out.println("Sports Grade: " + sGrade);
    }

    public void displayExam() {
        System.out.println("Exam Grade: " + eGrade);
    }

    void display() {
        displayStudent();
        displaySports();
        displayExam();
        System.out.println("Final Result: " + finalResult);
    }
}

public class two {
    public static void main(String[] args) {
        Results r = new Results("Ayush", 101, 85, 90, "Pass");
        r.display();
    }
}
