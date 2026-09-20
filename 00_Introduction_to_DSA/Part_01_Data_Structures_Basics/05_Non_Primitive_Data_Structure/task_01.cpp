#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[3];
};

// ---------------- TASK 1: struct basics ----------------
void sol_task1() {
    Student s1;
    s1.name = "Aman";
    s1.rollNo = 1;
    s1.marks[0] = 88; s1.marks[1] = 91; s1.marks[2] = 79;

    cout << "   " << s1.name << " (roll " << s1.rollNo << ")\n";
    for (int i = 0; i < 3; i++) {
        cout << "      marks[" << i << "] = " << s1.marks[i] << "\n";
    }
}

int main() {
    cout << "TASK 1:\n"; sol_task1();
    return 0;
}