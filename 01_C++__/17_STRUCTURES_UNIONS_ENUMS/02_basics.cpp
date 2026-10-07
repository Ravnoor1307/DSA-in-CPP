/*
TOPIC: Structures, Unions, and Enums
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>
#include <string>

using namespace std;


struct Student {
    string name;
    int age;
    double score;
};


struct Point {
    int x = 0;
    int y = 0;
};


enum class Status {
    Pending,
    Running,
    Done
};


void printStudent(
    const Student& student
) {
    cout << student.name
         << ' '
         << student.age
         << ' '
         << student.score
         << '\n';
}


int main() {

    // ========================================================
    // BASIC 1: STRUCT OBJECT
    // ========================================================

    Student student{
        "Grace",
        21,
        91.5
    };

    cout << "=== BASIC 1: Student ===\n";

    printStudent(student);

    cout << '\n';


    // ========================================================
    // BASIC 2: MODIFY MEMBERS
    // ========================================================

    student.score = 95.0;

    cout << "=== BASIC 2: Modify ===\n";

    cout << student.score
         << "\n\n";


    // ========================================================
    // BASIC 3: DEFAULT MEMBERS
    // ========================================================

    Point p;

    cout << "=== BASIC 3: Defaults ===\n";

    cout << p.x
         << ' '
         << p.y
         << "\n\n";


    // ========================================================
    // BASIC 4: COPY
    // ========================================================

    Point original{
        10,
        20
    };

    Point copy =
        original;

    copy.x = 99;

    cout << "=== BASIC 4: Copy ===\n";

    cout << "original = "
         << original.x
         << ' '
         << original.y
         << '\n';

    cout << "copy = "
         << copy.x
         << ' '
         << copy.y
         << "\n\n";


    // ========================================================
    // BASIC 5: ENUM CLASS
    // ========================================================

    Status status =
        Status::Running;

    cout << "=== BASIC 5: enum class ===\n";

    if (status == Status::Running) {
        cout << "Running\n";
    }

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: Student ===
Grace 21 91.5

=== BASIC 2: Modify ===
95

=== BASIC 3: Defaults ===
0 0

=== BASIC 4: Copy ===
original = 10 20
copy = 99 20

=== BASIC 5: enum class ===
Running

WHAT'S NEXT:
01_C++__/18_OOP_CLASSES_AND_OBJECTS/
*/
