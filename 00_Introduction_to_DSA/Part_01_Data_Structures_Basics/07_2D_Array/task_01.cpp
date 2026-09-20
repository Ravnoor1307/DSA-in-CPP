
#include <iostream>
using namespace std;

// ---------------- TASK 1: print grid ----------------
void sol_task1() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";            // har row ke baad newline
    }
}

int main() {
    cout << "TASK 1:\n"; sol_task1();
   return 0;
}