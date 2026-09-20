#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[3];
};

// ---------------- TASK 4: topper find ----------------
void sol_task4() {
    Student s[3] = {
        {"Aman",   1, {88, 91, 79}},
        {"Bina",   2, {95, 82, 89}},
        {"Chirag", 3, {67, 74, 70}}
    };
    int best = 0, bestTotal = -1;        // abhi tak koi nahi mila
    for (int i = 0; i < 3; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) total += s[i].marks[j];
        if (total > bestTotal) {         // naya topper mila?
            bestTotal = total;
            best = i;
        }
    }
    cout << "   Topper: " << s[best].name << " (roll " << s[best].rollNo
         << ") total = " << bestTotal << "\n";
}


int main() {
    cout << "TASK 4:\n"; sol_task4();
    return 0;
}