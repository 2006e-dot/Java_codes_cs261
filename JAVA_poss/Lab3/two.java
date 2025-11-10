package Lab3;

interface Account {
    void displayAccount();
}

interface SavingsAccount extends Account {
    void displaySavings();
}

interface CurrentAccount extends Account {
    void displayCurrent();
}

class PremiumAccount implements SavingsAccount, CurrentAccount {
    private int accNo;
    private double balance;
    private double interestRate;
    private double overdraftLimit;
    private int rewardsPoints;

    public PremiumAccount(int accNo, double balance, double interestRate, double overdraftLimit, int rewardsPoints) {
        this.accNo = accNo;
        this.balance = balance;
        this.interestRate = interestRate;
        this.overdraftLimit = overdraftLimit;
        this.rewardsPoints = rewardsPoints;
    }

    public void displayAccount() {
        System.out.println("Account No: " + accNo + ", Balance: " + balance);
    }

    public void displaySavings() {
        System.out.println("Interest Rate: " + interestRate);
    }

    public void displayCurrent() {
        System.out.println("Overdraft Limit: " + overdraftLimit);
    }

    void displayPremium() {
        displayAccount();
        displaySavings();
        displayCurrent();
        System.out.println("Rewards Points: " + rewardsPoints);
    }
}

public class two {
    public static void main(String[] args) {
        PremiumAccount p = new PremiumAccount(12345, 50000, 4.5, 20000, 120);
        p.displayPremium();
    }
}
