#include <iostream>
#include <string>
using namespace std;

struct Student2 {
    string name;
    int rollNo;
    int marks[3];
    int total() {                    // struct ke andar hi function
        return marks[0] + marks[1] + marks[2];
    }
};




// ---------------- TASK 7: member function ----------------
void sol_task7() {
    Student2 s[3] = {
        {"Aman",   1, {88, 91, 79}},
        {"Bina",   2, {95, 82, 89}},
        {"Chirag", 3, {67, 74, 70}}
    };
    int best = 0;
    for (int i = 1; i < 3; i++) {
        if (s[i].total() > s[best].total()) best = i;  // member function call
    }
    cout << "   Topper (via s[i].total()) = " << s[best].name
         << ", total = " << s[best].total() << "\n";
}





int main() {
    cout << "TASK 7:\n"; sol_task7();
    return 0;
}