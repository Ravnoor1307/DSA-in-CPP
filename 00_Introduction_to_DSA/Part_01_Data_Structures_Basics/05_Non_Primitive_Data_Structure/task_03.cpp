#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[3];
};

// ---------------- TASK 3: average of marks ----------------
void sol_task3() {
    Student s[3] = {
        {"Aman",   1, {88, 91, 79}},
        {"Bina",   2, {95, 82, 89}},
        {"Chirag", 3, {67, 74, 70}}
    };
    for (int i = 0; i < 3; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) total += s[i].marks[j];  // teeno ka sum
        double avg = total / 3.0;                            // float division
        cout << "   " << s[i].name << " ka average = " << avg << "\n";
    }
}

int main() {
    cout << "TASK 3:\n"; sol_task3();
    return 0;
}