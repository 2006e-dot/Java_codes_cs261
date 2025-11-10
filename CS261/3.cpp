#include <bits/stdc++.h>
using namespace std;

class PatternPrinter {
    int n;

public:
    PatternPrinter(int num) { n = num; }

    void printTriangle() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                cout << "* ";
            cout << endl;
        }
    }

    void printNumberPyramid() {
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= n - i; s++)
                cout << "  ";
            for (int j = 1; j <= 2 * i - 1; j++)
                cout << j <<" ";
            cout << endl;
        }
    }
};

int main() {
    int num;
    cout << "Enter the number of rows: ";
    cin >> num;

    PatternPrinter pp(num);

    int choice;
    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1. Print * Triangle\n";
        cout << "2. Print Number Pyramid\n";
        cout << "3. Print Both\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: pp.printTriangle(); break;
            case 2: pp.printNumberPyramid(); break;
            case 3: pp.printTriangle(); pp.printNumberPyramid(); break;
            case 4: cout << "Exit\n"; break;
            default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}