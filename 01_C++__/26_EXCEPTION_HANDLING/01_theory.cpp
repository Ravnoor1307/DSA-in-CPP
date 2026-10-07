/*
Topic: Exception Handling

Covers:
- try, throw, catch
- standard exceptions
- multiple handlers
- propagation
- stack unwinding
- custom exceptions
- catch-all
- rethrowing
- noexcept
- constructor failure and RAII foundations

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ========== SECTION 1: THROWING A STANDARD EXCEPTION ==========

int divideExact(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument(
            "denominator cannot be zero"
        );
    }

    return numerator / denominator;
}

// ========== SECTION 2: MULTIPLE EXCEPTION TYPES ==========

int valueAt(const int values[], int size, int index) {
    if (size < 0) {
        throw invalid_argument(
            "size cannot be negative"
        );
    }

    if (index < 0 || index >= size) {
        throw out_of_range(
            "index outside valid range"
        );
    }

    return values[index];
}

// ========== SECTION 3: PROPAGATION ==========

void level3() {
    throw runtime_error("failure from level3");
}

void level2() {
    level3();
}

void level1() {
    level2();
}

// ========== SECTION 4: STACK UNWINDING ==========

class Trace {
private:
    string name;

public:
    explicit Trace(const string& name)
        : name(name) {
        cout << "Construct "
             << name << '\n';
    }

    ~Trace() {
        cout << "Destroy "
             << name << '\n';
    }
};

void innerWork() {
    Trace inner("inner");

    cout << "innerWork throws\n";

    throw runtime_error(
        "problem during innerWork"
    );
}

void outerWork() {
    Trace outer("outer");

    innerWork();

    cout << "This line is never reached\n";
}

// ========== SECTION 5: CUSTOM EXCEPTION ==========

class InsufficientFunds : public runtime_error {
public:
    explicit InsufficientFunds(
        const string& message
    )
        : runtime_error(message) {
    }
};

class Account {
private:
    int balance;

public:
    explicit Account(int balance)
        : balance(balance >= 0 ? balance : 0) {
    }

    void withdraw(int amount) {
        if (amount <= 0) {
            throw invalid_argument(
                "withdrawal must be positive"
            );
        }

        if (amount > balance) {
            throw InsufficientFunds(
                "insufficient account balance"
            );
        }

        balance -= amount;
    }

    int getBalance() const noexcept {
        return balance;
    }
};

// ========== SECTION 6: RETHROWING ==========

void lowLevelOperation() {
    throw runtime_error(
        "low-level operation failed"
    );
}

void middleLayer() {
    try {
        lowLevelOperation();
    }
    catch (const exception& error) {
        cout << "Middle layer logged: "
             << error.what() << '\n';

        // Preserve the currently handled exception.
        throw;
    }
}

// ========== SECTION 7: noexcept ==========

int add(int a, int b) noexcept {
    return a + b;
}

// ========== SECTION 8: THROWING CONSTRUCTOR ==========

class Percentage {
private:
    int value;

public:
    explicit Percentage(int value)
        : value(value) {
        if (value < 0 || value > 100) {
            throw invalid_argument(
                "percentage must be between 0 and 100"
            );
        }
    }

    int get() const noexcept {
        return value;
    }
};

int main() {
    cout << "=== DEMO 1: BASIC TRY / THROW / CATCH ===\n";

    try {
        cout << "Before division\n";

        int result = divideExact(10, 0);

        cout << "Result = "
             << result << '\n';

        cout << "This does not execute\n";
    }
    catch (const invalid_argument& error) {
        cout << "Caught: "
             << error.what() << '\n';
    }

    cout << "Execution continues after catch\n";

    cout << "\n=== DEMO 2: SUCCESSFUL PATH ===\n";

    try {
        cout << "10 / 2 = "
             << divideExact(10, 2)
             << '\n';
    }
    catch (const exception& error) {
        cout << error.what() << '\n';
    }

    cout << "\n=== DEMO 3: MULTIPLE HANDLERS ===\n";

    int values[] = {10, 20, 30};

    try {
        cout << valueAt(values, 3, 5)
             << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Invalid argument: "
             << error.what() << '\n';
    }
    catch (const out_of_range& error) {
        cout << "Out of range: "
             << error.what() << '\n';
    }
    catch (const exception& error) {
        cout << "Other exception: "
             << error.what() << '\n';
    }

    cout << "\n=== DEMO 4: PROPAGATION ===\n";

    try {
        level1();
    }
    catch (const runtime_error& error) {
        cout << "Caught outside level1: "
             << error.what() << '\n';
    }

    cout << "\n=== DEMO 5: STACK UNWINDING ===\n";

    try {
        outerWork();
    }
    catch (const runtime_error& error) {
        cout << "Handler received: "
             << error.what() << '\n';
    }

    cout << "\n=== DEMO 6: CUSTOM EXCEPTION ===\n";

    Account account(500);

    try {
        account.withdraw(700);
    }
    catch (const InsufficientFunds& error) {
        cout << "Account error: "
             << error.what() << '\n';
    }

    cout << "Balance = "
         << account.getBalance() << '\n';

    cout << "\n=== DEMO 7: RETHROW ===\n";

    try {
        middleLayer();
    }
    catch (const exception& error) {
        cout << "Outer layer caught: "
             << error.what() << '\n';
    }

    cout << "\n=== DEMO 8: noexcept ===\n";

    cout << "add(3, 4) = "
         << add(3, 4) << '\n';

    cout << boolalpha;

    cout << "add(...) is noexcept? "
         << noexcept(add(3, 4))
         << '\n';

    cout << "\n=== DEMO 9: CONSTRUCTOR EXCEPTION ===\n";

    try {
        Percentage percentage(150);

        cout << percentage.get() << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Construction failed: "
             << error.what() << '\n';
    }

    cout << "\n=== DEMO 10: CATCH-ALL ===\n";

    try {
        throw 42;
    }
    catch (...) {
        cout << "Caught an exception of unknown type\n";
    }

    cout << "\nNext: 27_NAMESPACES_AND_HEADER_FILES\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: BASIC TRY / THROW / CATCH ===
Before division
Caught: denominator cannot be zero
Execution continues after catch

=== DEMO 2: SUCCESSFUL PATH ===
10 / 2 = 5

=== DEMO 3: MULTIPLE HANDLERS ===
Out of range: index outside valid range

=== DEMO 4: PROPAGATION ===
Caught outside level1: failure from level3

=== DEMO 5: STACK UNWINDING ===
Construct outer
Construct inner
innerWork throws
Destroy inner
Destroy outer
Handler received: problem during innerWork

=== DEMO 6: CUSTOM EXCEPTION ===
Account error: insufficient account balance
Balance = 500

=== DEMO 7: RETHROW ===
Middle layer logged: low-level operation failed
Outer layer caught: low-level operation failed

=== DEMO 8: noexcept ===
add(3, 4) = 7
add(...) is noexcept? true

=== DEMO 9: CONSTRUCTOR EXCEPTION ===
Construction failed: percentage must be between 0 and 100

=== DEMO 10: CATCH-ALL ===
Caught an exception of unknown type

Next: 27_NAMESPACES_AND_HEADER_FILES
*/
