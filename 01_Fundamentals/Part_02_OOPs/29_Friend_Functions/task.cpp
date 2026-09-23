/*
═══════════════════════════════════════════════
 TASK SET — FRIEND FUNCTIONS & FRIEND CLASS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: An outside auditor is granted a special access
    badge by the company, letting them open the locked private ledgers
    even though they are not employees. Similarly, a utility function
    (like adding two distances) needs the private measurements of BOTH
    objects — so the class hands it a `friend` badge.

 🧠 HOW TO SOLVE: Declare `friend returnType funcName(params);` INSIDE the
    class to give access. Define the function OUTSIDE the class WITHOUT
    the class scope (no ::). Friend functions have no this pointer — they
    take objects as parameters. Friend class: `friend class ClassName;`
    inside the giver class. Use direct member access (d1.feet) inside
    friend code — no getters needed.

 MODES/TOPICS COVERED:
  1. Peek into a private member with a friend function
  2. Swap two objects' private values
  3. Compare two objects through a friend function
  4. Distance addition with a negative guard
  5. Friend class: Teacher grades private Student scores
  6. Friend operators: == and <<
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;
#include <string>

// ═══════════════════════════════════════════════════════════
// SOLUTION 1 — Peek Into Private Room
// ═══════════════════════════════════════════════════════════
class Vault {
private:
    int code;
public:
    Vault(int c) : code(c) {}
    friend void showCode(Vault v);   // badge mila — sab access allowed
};

void showCode(Vault v) {
    cout << "  Private code (via friend) = " << v.code << endl;
}

void solveTask1() {
    cout << "\n=== SOLUTION 1: Peek Into Private Room ===" << endl;
    Vault v(7861);
    showCode(v);   // normal function call — object dot use NAHI kiya
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 2 — Swap Two Objects' Private Values
// ═══════════════════════════════════════════════════════════
class Account {
private:
    string owner;
    int balance;
public:
    Account(string o, int b) : owner(o), balance(b) {}
    friend void swapValues(Account& a, Account& b);
    void print() const {
        cout << "  " << owner << ": $" << balance;
    }
};

void swapValues(Account& a, Account& b) {
    int temp = a.balance;   // a.balance direct — friend access ✅
    a.balance = b.balance;
    b.balance = temp;
}

void solveTask2() {
    cout << "\n=== SOLUTION 2: Swap Two Objects' Private Values ===" << endl;
    Account alice("Alice", 5000);
    Account bob("Bob", 9000);

    cout << "Before swap:" << endl;
    alice.print(); cout << endl;
    bob.print();   cout << endl;

    swapValues(alice, bob);   // friend function swap

    cout << "After swap:" << endl;
    alice.print(); cout << endl;
    bob.print();   cout << endl;
    // Expected: Alice now has 9000, Bob has 5000
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 3 — Compare Two Boxes (Friend Returns Result)
// ═══════════════════════════════════════════════════════════
class Box {
private:
    int w, h, d;
public:
    Box(int w, int h, int d) : w(w), h(h), d(d) {}
    friend int compare(Box a, Box b);  // 1 = a bigger, -1 = b bigger, 0 = equal
};

int compare(Box a, Box b) {
    int volA = a.w * a.h * a.d;   // private directly — no getter needed
    int volB = b.w * b.h * b.d;
    if (volA > volB) return 1;
    if (volA < volB) return -1;
    return 0;
}

void solveTask3() {
    cout << "\n=== SOLUTION 3: Compare Two Boxes ===" << endl;
    Box small(2, 2, 2);    // vol 8
    Box big(5, 5, 5);      // vol 125
    Box twin(2, 2, 2);     // vol 8

    int r1 = compare(big, small);   // 1 → big zyada bada
    int r2 = compare(small, big);   // -1 → small chota
    int r3 = compare(small, twin);  // 0 → barabar

    cout << "  big vs small  : " << r1 << " (1 = first bigger)" << endl;
    cout << "  small vs big  : " << r2 << " (-1 = second bigger)" << endl;
    cout << "  small vs twin : " << r3 << " (0 = equal volumes)" << endl;
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 4 — Distance Addition with Negative Guard
// ═══════════════════════════════════════════════════════════
class Distance {
private:
    int feet, inch;
public:
    Distance(int f, int i) : feet(f), inch(i) {}
    friend Distance addDist(Distance a, Distance b);
    void print() const {
        cout << "  " << feet << " ft " << inch << " in" << endl;
    }
};

Distance addDist(Distance a, Distance b) {
    // EDGE CASE guard — koi negative ho to reject karo
    if (a.feet < 0 || a.inch < 0 || b.feet < 0 || b.inch < 0) {
        cout << "  ❌ Negative units detected — operation rejected." << endl;
        return Distance(0, 0);
    }

    int totalFeet = a.feet + b.feet;    // direct private read ✅
    int totalInch = a.inch + b.inch;

    int carry = totalInch / 12;          // 12 inch = 1 foot
    totalInch = totalInch % 12;
    totalFeet += carry;

    return Distance(totalFeet, totalInch);
}

void solveTask4() {
    cout << "\n=== SOLUTION 4: Distance Addition with Negative Guard ===" << endl;

    Distance d1(5, 9);
    Distance d2(2, 6);
    cout << "  5ft9in + 2ft6in =";
    addDist(d1, d2).print();
    // Expected: 8 ft 3 in

    Distance d3(-2, 4);   // negative feet — invalid
    Distance d4(3, 3);
    cout << "  (-2ft4in) + 3ft3in → rejected:";
    addDist(d3, d4).print();
    // Expected: rejection message + 0 ft 0 in
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 5 — Friend Class: Teacher ↔ Student Scores
// ═══════════════════════════════════════════════════════════
class Student {
private:
    int marks[3];   // fixed size 3 — loop count fixed → O(1) total work
public:
    Student(int m1, int m2, int m3) {
        marks[0] = m1; marks[1] = m2; marks[2] = m3;
    }
    friend class Teacher;   // puri Teacher class ko full access mila
};

class Teacher {
public:
    void gradeStudent(Student& s) {
        int sum = 0;
        cout << "  Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << s.marks[i] << " ";   // s.marks[i] — friend class access ✅
            sum += s.marks[i];
        }
        int avg = sum / 3;

        char grade;
        if (avg >= 90)      grade = 'A';
        else if (avg >= 75) grade = 'B';
        else if (avg >= 50) grade = 'C';
        else                grade = 'F';

        cout << "→ Average: " << avg << " → Grade: " << grade << endl;
    }
};

void solveTask5() {
    cout << "\n=== SOLUTION 5: Friend Class Teacher Grading ===" << endl;
    Student s1(95, 88, 60);
    Teacher t1;
    t1.gradeStudent(s1);   // average 81 → B
}

// ═══════════════════════════════════════════════════════════
// SOLUTION 6 — Friend Operators (== and <<)
// ═══════════════════════════════════════════════════════════
class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    friend bool operator==(Point a, Point b);
    friend ostream& operator<<(ostream& out, Point p);
};

bool operator==(Point a, Point b) {
    return (a.x == b.x && a.y == b.y);   // dono private read — friend ✅
}

ostream& operator<<(ostream& out, Point p) {
    out << "(" << p.x << "," << p.y << ")";   // friend access ✅
    return out;   // chaining ke liye stream wapis karo
}

void solveTask6() {
    cout << "\n=== SOLUTION 6: Friend Operators == and << ===" << endl;
    Point p1(1, 2);
    Point p2(1, 2);   // same coordinates
    Point p3(3, 4);   // different

    cout << "  " << p1 << (p1 == p2 ? " == " : " != ") << p2 << endl;
    // Expected: (1,2) == (1,2)

    cout << "  " << p1 << (p1 == p3 ? " == " : " != ") << p3 << endl;
    // Expected: (1,2) != (3,4)
}

int main() {
    cout << "═══════════════════════════════════════" << endl;
    cout << " TASK SOLUTIONS — FRIEND FUNCTIONS" << endl;
    cout << "═══════════════════════════════════════" << endl;

    solveTask1();   // Vault peek
    solveTask2();   // Swap private balances
    solveTask3();   // Compare boxes
    solveTask4();   // Distance + negative guard
    solveTask5();   // Friend class grading
    solveTask6();   // Friend operators == and <<

    return 0;
}