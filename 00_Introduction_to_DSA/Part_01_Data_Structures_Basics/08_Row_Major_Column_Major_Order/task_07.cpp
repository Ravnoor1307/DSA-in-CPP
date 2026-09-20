#include <iostream>
using namespace std;

// ---------------- TASK 7: find element size + base ----------------
void sol_task7() {
    long long a23 = 1048, a24 = 1052; int C = 10;
    int size = a24 - a23;                              // adjacent row-major cells ka farak
    long long base = a23 - ((long long)2 * C + 3) * size;   // reverse formula
    cout << "   Element size = " << size << " bytes\n";
    cout << "   Base address B = " << base << "\n";
}

int main() {
    cout << "TASK 7:\n"; sol_task7();
    return 0;
}