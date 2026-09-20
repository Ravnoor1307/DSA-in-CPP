
#include <iostream>
using namespace std;


// ---------------- TASK 7: matrix multiplication ----------------
void sol_task7() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {};

    for (int i = 0; i < 2; i++) {          // A ki rows
        for (int j = 0; j < 2; j++) {      // B ke columns
            int sum = 0;
            for (int k = 0; k < 3; k++) {  // common dimension (A ke cols = B ke rows)
                sum += A[i][k] * B[k][j];  // row i × column j ka product-sum
            }
            C[i][j] = sum;
        }
    }
    cout << "   C = A x B (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "TASK 7:\n"; sol_task7();
    return 0;
}