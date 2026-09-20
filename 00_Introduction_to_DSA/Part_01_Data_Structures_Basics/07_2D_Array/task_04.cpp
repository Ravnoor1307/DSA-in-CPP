
#include <iostream>
using namespace std;


// ---------------- TASK 4: row-wise sum ----------------
void sol_task4() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += mat[i][j];
        }
        cout << "   Row " << i << " sum = " << rowSum << "\n";
    }
}

int main() {
    cout << "TASK 4:\n"; sol_task4();
    return 0;
}