#include <iostream>
using namespace std;

// ---------------- TASK 6: last element both ways ----------------
void sol_task6() {
    long long base = 2000; int R = 12, C = 8, size = 8;
    int i = 11, j = 7;
    long long rm = base + ((long long)i * C + j) * size;
    long long cm = base + ((long long)j * R + i) * size;
    long long direct = base + (long long)(R * C - 1) * size;   // aakhri cell ka offset
    cout << "   Row-major    = " << rm << "\n";
    cout << "   Column-major = " << cm << "\n";
    cout << "   Last direct  = " << direct << "   (dono same hona chahiye)\n";
}

int main() {
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}