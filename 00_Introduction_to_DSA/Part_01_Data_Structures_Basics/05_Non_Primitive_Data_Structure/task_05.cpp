#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[3];
};

// ---------------- TASK 5: pass/ fail count ----------------
void sol_task5() {
    Student s[3] = {
        {"Aman",   1, {88, 91, 79}},   // total 258 -> PASS
        {"Bina",   2, {95, 82, 89}},   // total 266 -> PASS
        {"Chirag", 3, {40, 45, 50}}    // total 135 -> FAIL
    };
    int pass = 0, fail = 0;
    for (int i = 0; i < 3; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) total += s[i].marks[j];
        if (total >= 150) pass++;
        else              fail++;
    }
    cout << "   PASS = " << pass << ", FAIL = " << fail << "\n";
}


int main() {
    cout << "TASK 5:\n"; sol_task5();
    return 0;
}