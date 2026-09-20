#include <iostream>
using namespace std;


// ---------------- TASK 2: column-major address ----------------
void sol_task2() {
    long long base = 1000; int R = 10, C = 15;
    int i = 7, j = 2, size = 4;
    long long addr = base + ((long long)j * R + i) * size;   // column-major
    cout << "   A[7][2] column-major address = " << addr << "\n";
}


int main() {
    cout << "TASK 2:\n"; sol_task2();
    return 0;
}