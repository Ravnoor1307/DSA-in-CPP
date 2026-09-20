#include <iostream>
using namespace std;

// ---------------- TASK 1: row-major address ----------------
void sol_task1() {
    long long base = 1000; int R = 10, C = 15;
    int i = 4, j = 6, size = 4;
    long long addr = base + ((long long)i * C + j) * size;   // row-major
    cout << "   A[4][6] row-major address = " << addr << "\n";
}

int main() {
    cout << "TASK 1:\n"; sol_task1();
    return 0;
}