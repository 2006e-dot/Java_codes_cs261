import java.io.*;
import java.util.*;

// -------- CUSTOM EXCEPTIONS -------- //

class InsufficientBalanceException extends Exception {
    InsufficientBalanceException(String msg) { super(msg); }
}

class NegativeAmountException extends Exception {
    NegativeAmountException(String msg) { super(msg); }
}

// -------- INTERFACE 1 -------- //
interface BasicBankOps {
    void deposit(int amt) throws NegativeAmountException;
    void withdraw(int amt) throws NegativeAmountException, InsufficientBalanceException;
}

// -------- INTERFACE 2 -------- //
interface CustomerInfo {
    String getCustomerName();
}

// -------- SUPERCLASS (used for single inheritance) -------- //
class BankCore {
    protected int balance;

    BankCore(int balance) {
        this.balance = balance;
    }

    void saveToFile() throws IOException {
        FileWriter fw = new FileWriter("balance.txt");
        fw.write("Final Balance = " + balance);
        fw.close();
    }
}

// -------- HYBRID CHILD CLASS -------- //
class BankAccount extends BankCore implements BasicBankOps, CustomerInfo {

    private String name;

    BankAccount(String name, int balance) {
        super(balance);   // calling superclass
        this.name = name;
    }

    public String getCustomerName() {
        return name;
    }

    public void deposit(int amt) throws NegativeAmountException {
        if (amt < 0)
            throw new NegativeAmountException("Amount cannot be negative!");

        balance += amt;
        System.out.println("Deposit successful. Current Balance = " + balance);
    }

    public void withdraw(int amt) throws NegativeAmountException, InsufficientBalanceException {

        if (amt < 0)
            throw new NegativeAmountException("Amount cannot be negative!");

        if (amt > balance)
            throw new InsufficientBalanceException("Insufficient Funds!");

        balance -= amt;
        System.out.println("Withdrawal successful. Current Balance = " + balance);
    }

    int getBalance() {
        return balance;
    }
}

// -------- INPUT METHOD (SAFE SCANNER) -------- //
public class Examfinal {

    static int safeInt() {
        Scanner sc = new Scanner(System.in);
        try {
            return sc.nextInt();
        }
        catch (InputMismatchException e) {
            System.out.println("Invalid number! Try again:");
            sc.nextLine();
            return safeInt();
        }
    }

    // -------- MAIN -------- //
    public static void main(String args[]) {

        BankAccount acc = new BankAccount("Ayush", 1000);

        System.out.println("Welcome " + acc.getCustomerName());
        System.out.println("1. Deposit");
        System.out.println("2. Withdraw");
        System.out.print("Enter choice: ");

        int ch = safeInt();

        try {
            if (ch == 1) {
                System.out.print("Enter deposit amount: ");
                int amt = safeInt();
                acc.deposit(amt);
            }
            else if (ch == 2) {
                System.out.print("Enter withdraw amount: ");
                int amt = safeInt();
                acc.withdraw(amt);
            }
            else {
                throw new ArithmeticException("Invalid Menu Choice!");
            }

            acc.saveToFile(); // from superclass BankCore
            System.out.println("Balance saved to file.");

        }
        catch (NegativeAmountException e) {
            System.out.println("Error: " + e.getMessage());
        }
        catch (InsufficientBalanceException e) {
            System.out.println("Error: " + e.getMessage());
        }
        catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
        catch (ArithmeticException e) {
            System.out.println("Invalid option selected!");
        }
        catch (Exception e) {
            System.out.println("Unknown Error: " + e);
        }
        finally {
            System.out.println("Thank you for using the Bank!");
        }

        System.out.println("Final Balance = " + acc.getBalance());
    }
}
