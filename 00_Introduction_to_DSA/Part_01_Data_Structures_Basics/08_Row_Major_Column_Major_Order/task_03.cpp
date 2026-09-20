#include <iostream>
using namespace std;


// ---------------- TASK 3: both + compare ----------------
void sol_task3() {
    long long base = 1000; int R = 10, C = 15;
    int i = 3, j = 8, size = 4;
    long long rm = base + ((long long)i * C + j) * size;
    long long cm = base + ((long long)j * R + i) * size;
    cout << "   A[3][8] row-major    = " << rm << "\n";
    cout << "   A[3][8] column-major = " << cm << "\n";
    cout << "   Chhota address aata hai: "
         << (rm < cm ? "ROW-major" : "COLUMN-major") << "\n";
    cout << "   Farak = " << (rm > cm ? rm - cm : cm - rm) << " bytes\n";
}

int main() {
    cout << "TASK 3:\n"; sol_task3();
    return 0;
}