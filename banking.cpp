#include <iostream>
using namespace std;

// ---------- SIMPLE CUSTOM EXCEPTIONS (EMPTY CLASSES) ---------- //

class NegativeAmount {};
class InsufficientBalance {};
class InvalidChoice {};

// ---------- INTERFACE 1 (abstract class) ---------- //

class DepositOps {
public:
    virtual void deposit(int amt) = 0;
};

// ---------- INTERFACE 2 (abstract class) ---------- //

class WithdrawOps {
public:
    virtual void withdraw(int amt) = 0;
};

// ---------- BASE CLASS (single inheritance part) ---------- //

class BankCore {
protected:
    int balance;
public:
    BankCore(int b) : balance(b) {}
};

// ---------- HYBRID DERIVED CLASS ---------- //

class BankAccount : public BankCore, public DepositOps, public WithdrawOps {

public:
    BankAccount(int b) : BankCore(b) {}

    void deposit(int amt) override {
        if (amt < 0)
            throw NegativeAmount();

        balance += amt;
        cout << "Deposit successful. Balance = " << balance << endl;
    }

    void withdraw(int amt) override {
        if (amt < 0)
            throw NegativeAmount();

        if (amt > balance)
            throw InsufficientBalance();

        balance -= amt;
        cout << "Withdrawal successful. Balance = " << balance << endl;
    }

    int getBalance() { return balance; }
};

// ---------- SAFE INPUT FUNCTION ---------- //

int safeInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Invalid input! Enter again: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return x;
}

// ---------- MAIN FUNCTION ---------- //

int main() {

    BankAccount acc(1000);

    cout << "1. Deposit\n2. Withdraw\nEnter choice: ";
    int ch = safeInt();

    cout << "Enter amount: ";
    int amt = safeInt();

    try {
        if (ch == 1)
            acc.deposit(amt);

        else if (ch == 2)
            acc.withdraw(amt);

        else
            throw InvalidChoice();
    }

    catch (NegativeAmount e) {
        cout << "Amount cannot be negative!";
    }
    catch (InsufficientBalance e) {
        cout << "Insufficient Balance!";
    }
    catch (InvalidChoice e) {
        cout << "Invalid menu choice!";
    }

    cout << "\nFinal Balance: " << acc.getBalance();
    return 0;
}
