
#include <iostream>
using namespace std;


// ---------------- TASK 6: transpose ----------------
void sol_task6() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];   // rotate
            mat[j][i] = temp;
        }
    }
    cout << "   Transpose grid:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}