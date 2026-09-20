#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[3];
};

// ---------------- TASK 2: array of struct ----------------
void sol_task2() {
    Student s[3] = {
        {"Aman",   1, {88, 91, 79}},
        {"Bina",   2, {95, 82, 89}},
        {"Chirag", 3, {67, 74, 70}}
    };
    for (int i = 0; i < 3; i++) {
        cout << "   " << s[i].name << " -> roll " << s[i].rollNo
             << " | marks " << s[i].marks[0] << "," << s[i].marks[1]
             << "," << s[i].marks[2] << "\n";
    }
}


int main() {
    cout << "TASK 2:\n"; sol_task2();
    return 0;
}