
/*
 TASK 2 SOLUTION — array of structs
*/
#include <iostream>
#include <string>
using namespace std;
struct Student { string name; int marks; };   // ek student ka unit
int main() {
    int n; cin >> n;
    Student students[100];                     // array of structs (data structure)
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].marks;   // dot se field access
    }
    for (int i = 0; i < n; i++) {
        cout << students[i].name << " -> " << students[i].marks << "\n";
    }
    return 0;
}
// Explanation: ab student ki saari jaankari ek hi box me hai. Structure
// data ko bundle karta hai — index mismatch wale bugs automatically gayab.
