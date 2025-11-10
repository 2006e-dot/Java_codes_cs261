package Lab1;

class Time {
    private int hours;
    private int minutes;

    void setTime(int h, int m) {
        hours = h;
        minutes = m;
    }

    void displayTime() {
        System.out.println(hours + " hr " + minutes + " min");
    }

    Time add(Time t2) {
        Time t3 = new Time();
        t3.minutes = this.minutes + t2.minutes;
        t3.hours = this.hours + t2.hours + (t3.minutes / 60);
        t3.minutes %= 60;
        return t3;
    }
}

public class three{
    public static void main(String[] args) {
        Time t1 = new Time();
        Time t2 = new Time();
        Time t3;
        t1.setTime(2, 45);
        t2.setTime(1, 30);
        t3 = t1.add(t2);
        System.out.print("First Time: ");
        t1.displayTime();
        System.out.print("Second Time: ");
        t2.displayTime();
        System.out.print("Sum of Times: ");
        t3.displayTime();
    }
}
