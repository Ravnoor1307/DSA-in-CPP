#include <iostream>
using namespace std;

// ---------------- TASK 5: reverse (offset -> i, j) ----------------
void sol_task5() {
    long long base = 1000; int size = 4, C = 15;
    long long addr = 1212;
    int elementNo = (addr - base) / size;        // kitna waam tak chale
    int i = elementNo / C;                       // rows count
    int j = elementNo % C;                       // remaining columns
    cout << "   Address " << addr << " (row-major) = A[" << i << "][" << j << "]\n";
}

int main() {
    cout << "TASK 5:\n"; sol_task5();
    return 0;
}