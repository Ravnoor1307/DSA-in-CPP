/*
 TASK 1 SOLUTION — parallel arrays
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    string name[100];
    int marks[100];
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> marks[i];   // dono arrays ek sath bharte hain
    }
    for (int i = 0; i < n; i++) {
        cout << name[i] << " -> " << marks[i] << "\n";
    }
    return 0;
}
// Explanation: ye "no data structure" wala tareeka hai — do alag arrays.
// Index i hi dono ke beech ka rishta hai (parallel arrays).
