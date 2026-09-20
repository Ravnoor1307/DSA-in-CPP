#include <iostream>
using namespace std;


// ---------------- TASK 4: 1-based indexing ----------------
void sol_task4() {
    long long base = 1000; int R = 10, C = 15, size = 4;
    int i = 3, j = 8;
    long long rm = base + ((long long)(i - 1) * C + (j - 1)) * size;
    long long cm = base + ((long long)(j - 1) * R + (i - 1)) * size;
    cout << "   1-based A[3][8]: row = " << rm << ", col = " << cm << "\n";
}


int main() {
    cout << "TASK 4:\n"; sol_task4();
    return 0;
}