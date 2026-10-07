/*
Topic: Exception Handling
File: 04_practice_problems.cpp

Practice:
1. Safe division
2. Checked array access
3. Bank-account custom exception
4. Constructor validation
5. Stack unwinding demonstration

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ========== PROBLEM 1: SAFE DIVISION ==========
//
// Throw invalid_argument for a zero denominator.
//
// Normal operation: O(1)

double safeDivide(double a, double b) {
    if (b == 0.0) {
        throw invalid_argument(
            "zero denominator"
        );
    }

    return a / b;
}

// ========== PROBLEM 2: CHECKED ARRAY ==========
//
// Provide checked access to a fixed-size educational array.
//
// get: O(1)

class CheckedArray {
private:
    int values[3];

public:
    CheckedArray(int a, int b, int c)
        : values{a, b, c} {
    }

    int get(int index) const {
        if (index < 0 || index >= 3) {
            throw out_of_range(
                "CheckedArray index out of range"
            );
        }

        return values[index];
    }
};

// ========== PROBLEM 3: BANK ACCOUNT ==========

class InsufficientFunds : public runtime_error {
public:
    explicit InsufficientFunds(
        const string& message
    )
        : runtime_error(message) {
    }
};

class BankAccount {
private:
    int balance;

public:
    explicit BankAccount(int initialBalance)
        : balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument(
                "initial balance cannot be negative"
            );
        }
    }

    void deposit(int amount) {
        if (amount <= 0) {
            throw invalid_argument(
                "deposit must be positive"
            );
        }

        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= 0) {
            throw invalid_argument(
                "withdrawal must be positive"
            );
        }

        if (amount > balance) {
            throw InsufficientFunds(
                "not enough funds"
            );
        }

        balance -= amount;
    }

    int getBalance() const noexcept {
        return balance;
    }
};

// ========== PROBLEM 4: VALIDATED PERCENTAGE ==========

class Percentage {
private:
    int value;

public:
    explicit Percentage(int value)
        : value(value) {
        if (value < 0 || value > 100) {
            throw invalid_argument(
                "invalid percentage"
            );
        }
    }

    int get() const noexcept {
        return value;
    }
};

// ========== PROBLEM 5: UNWINDING ==========

class ScopeTrace {
private:
    string label;

public:
    explicit ScopeTrace(const string& label)
        : label(label) {
        cout << "Enter "
             << label << '\n';
    }

    ~ScopeTrace() {
        cout << "Leave "
             << label << '\n';
    }
};

void levelTwo() {
    ScopeTrace second("levelTwo");

    throw runtime_error(
        "failure in levelTwo"
    );
}

void levelOne() {
    ScopeTrace first("levelOne");

    levelTwo();
}

int main() {
    cout << "=== PROBLEM 1: SAFE DIVISION ===\n";

    try {
        cout << "12 / 3 = "
             << safeDivide(12, 3) << '\n';

        cout << "12 / 0 = "
             << safeDivide(12, 0) << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Error: "
             << error.what() << '\n';
    }

    cout << "\n=== PROBLEM 2: CHECKED ARRAY ===\n";

    CheckedArray array(10, 20, 30);

    try {
        cout << "array[1] = "
             << array.get(1) << '\n';

        cout << "array[5] = "
             << array.get(5) << '\n';
    }
    catch (const out_of_range& error) {
        cout << "Error: "
             << error.what() << '\n';
    }

    cout << "\n=== PROBLEM 3: BANK ACCOUNT ===\n";

    try {
        BankAccount account(500);

        account.deposit(100);

        cout << "Balance = "
             << account.getBalance() << '\n';

        account.withdraw(800);
    }
    catch (const InsufficientFunds& error) {
        cout << "Funds error: "
             << error.what() << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Argument error: "
             << error.what() << '\n';
    }

    cout << "\n=== PROBLEM 4: CONSTRUCTOR VALIDATION ===\n";

    try {
        Percentage valid(85);

        cout << "Valid = "
             << valid.get() << '\n';

        Percentage invalid(150);

        cout << invalid.get() << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Creation error: "
             << error.what() << '\n';
    }

    cout << "\n=== PROBLEM 5: STACK UNWINDING ===\n";

    try {
        levelOne();
    }
    catch (const runtime_error& error) {
        cout << "Caught: "
             << error.what() << '\n';
    }

    cout << "\nNext: 27_NAMESPACES_AND_HEADER_FILES\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: SAFE DIVISION ===
12 / 3 = 4
12 / 0 = Error: zero denominator

=== PROBLEM 2: CHECKED ARRAY ===
array[1] = 20
array[5] = Error: CheckedArray index out of range

=== PROBLEM 3: BANK ACCOUNT ===
Balance = 600
Funds error: not enough funds

=== PROBLEM 4: CONSTRUCTOR VALIDATION ===
Valid = 85
Creation error: invalid percentage

=== PROBLEM 5: STACK UNWINDING ===
Enter levelOne
Enter levelTwo
Leave levelTwo
Leave levelOne
Caught: failure in levelTwo

Next: 27_NAMESPACES_AND_HEADER_FILES
*/
