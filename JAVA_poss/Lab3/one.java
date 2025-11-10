package Lab3;

interface Person {
    void setPerson(String name, int age);
    void displayPerson();
}

interface Student extends Person {
    void setStudent(int rollNo, String course);
    void displayStudent();
}

interface Faculty extends Person {
    void setFaculty(int facultyId, String department);
    void displayFaculty();
}

class TeachingAssistant implements Student, Faculty {
    String name;
    int age;
    int rollNo;
    String course;
    int facultyId;
    String department;
    int hoursPerWeek;

    TeachingAssistant() {
        name = "Unknown";
        age = 0;
        rollNo = 0;
        course = "None";
        facultyId = 0;
        department = "None";
        hoursPerWeek = 0;
    }

    public void setPerson(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayPerson() {
        System.out.println("Name: " + name + ", Age: " + age);
    }

    public void setStudent(int rollNo, String course) {
        this.rollNo = rollNo;
        this.course = course;
    }

    public void displayStudent() {
        System.out.println("Roll No: " + rollNo + ", Course: " + course);
    }

    public void setFaculty(int facultyId, String department) {
        this.facultyId = facultyId;
        this.department = department;
    }

    public void displayFaculty() {
        System.out.println("Faculty ID: " + facultyId + ", Department: " + department);
    }

    void setTA(String name, int age, int rollNo, String course, int facultyId, String dept, int hours) {
        setPerson(name, age);
        setStudent(rollNo, course);
        setFaculty(facultyId, dept);
        hoursPerWeek = hours;
    }

    void displayTA() {
        displayPerson();
        displayStudent();
        displayFaculty();
        System.out.println("Hours per Week: " + hoursPerWeek);
    }
}

public class one {
    public static void main(String[] args) {
        TeachingAssistant ta = new TeachingAssistant();
        ta.setTA("Ayush", 21, 101, "B.Tech CSE", 501, "Computer Science", 12);
        ta.displayTA();
    }
}
