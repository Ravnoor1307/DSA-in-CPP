/*
Topic: static, const, and friend
File: 03_variation.cpp

Purpose:
Explore:
- static data shared across objects
- static local lifetime
- const/non-const member overloads
- const reference lifetime considerations
- friend classes
- friendship direction

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: SHARED STATIC CONFIGURATION ==========

class Connection {
private:
    inline static int timeoutSeconds = 30;

    int id;

public:
    explicit Connection(int id)
        : id(id) {
    }

    static void setTimeout(int seconds) {
        if (seconds > 0) {
            timeoutSeconds = seconds;
        }
    }

    static int getTimeout() {
        return timeoutSeconds;
    }

    void display() const {
        cout << "Connection "
             << id
             << ": timeout="
             << timeoutSeconds
             << '\n';
    }
};

// ========== SECTION 2: STATIC LOCAL ==========

int nextSequence() {
    static int sequence = 100;

    return sequence++;
}

// ========== SECTION 3: CONST OVERLOAD ==========

class Box {
private:
    int value;

public:
    explicit Box(int value)
        : value(value) {
    }

    int& access() {
        cout << "Mutable access\n";
        return value;
    }

    const int& access() const {
        cout << "Read-only access\n";
        return value;
    }
};

// ========== SECTION 4: CONST REFERENCE ==========

class Book {
private:
    string title;

public:
    explicit Book(const string& title)
        : title(title) {
    }

    const string& getTitle() const {
        return title;
    }
};

// ========== SECTION 5: FRIEND CLASS ==========

class Account;

class Auditor {
public:
    void inspect(const Account& account) const;
};

class Account {
private:
    int balance;

public:
    explicit Account(int balance)
        : balance(balance >= 0 ? balance : 0) {
    }

    friend class Auditor;
};

void Auditor::inspect(const Account& account) const {
    cout << "Audited balance = "
         << account.balance << '\n';
}

// ========== SECTION 6: FRIENDSHIP IS DIRECTIONAL ==========

class B;

class A {
private:
    int secretA = 10;

    friend class B;
};

class B {
private:
    int secretB = 20;

public:
    void inspectA(const A& a) const {
        // B is a friend of A.
        cout << "A secret = "
             << a.secretA << '\n';
    }

    int getSecretB() const {
        return secretB;
    }
};

int main() {
    cout << "=== VARIATION 1: SHARED STATIC STATE ===\n";

    Connection a(1);
    Connection b(2);

    a.display();
    b.display();

    Connection::setTimeout(60);

    a.display();
    b.display();

    cout << "\n=== VARIATION 2: STATIC LOCAL ===\n";

    cout << nextSequence() << '\n';
    cout << nextSequence() << '\n';
    cout << nextSequence() << '\n';

    cout << "\n=== VARIATION 3: CONST OVERLOAD ===\n";

    Box normal(10);

    normal.access() = 25;

    cout << "Value = "
         << normal.access() << '\n';

    const Box fixed(50);

    cout << "Const value = "
         << fixed.access() << '\n';

    cout << "\n=== VARIATION 4: CONST REFERENCE ===\n";

    Book book("Algorithms");

    const string& title = book.getTitle();

    cout << "Title = "
         << title << '\n';

    cout << "\n=== VARIATION 5: FRIEND CLASS ===\n";

    Account account(900);
    Auditor auditor;

    auditor.inspect(account);

    cout << "\n=== VARIATION 6: FRIENDSHIP DIRECTION ===\n";

    A objectA;
    B objectB;

    objectB.inspectA(objectA);

    // A was not declared a friend of B.
    // Therefore A would not gain direct access to B::secretB.
    cout << "B through public interface = "
         << objectB.getSecretB() << '\n';

    cout << "\nNext: 24_OPERATOR_OVERLOADING\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: SHARED STATIC STATE ===
Connection 1: timeout=30
Connection 2: timeout=30
Connection 1: timeout=60
Connection 2: timeout=60

=== VARIATION 2: STATIC LOCAL ===
100
101
102

=== VARIATION 3: CONST OVERLOAD ===
Mutable access
Value = Mutable access
25
Const value = Read-only access
50

=== VARIATION 4: CONST REFERENCE ===
Title = Algorithms

=== VARIATION 5: FRIEND CLASS ===
Audited balance = 900

=== VARIATION 6: FRIENDSHIP DIRECTION ===
A secret = 10
B through public interface = 20

Next: 24_OPERATOR_OVERLOADING
*/
