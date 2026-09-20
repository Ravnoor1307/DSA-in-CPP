
#include <iostream>
using namespace std;


// ---------------- TASK 2: input + print ----------------
void sol_task2() {
    int mat[3][3];
    cout << "   9 values do (row-wise): ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];    // user input
        }
    }
    cout << "   Grid:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "TASK 2:\n"; sol_task2();
    return 0;
}