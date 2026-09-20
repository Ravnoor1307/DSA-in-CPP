
#include <iostream>
using namespace std;


// ---------------- TASK 3: total sum ----------------
void sol_task3() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            total += mat[i][j];  // har cell sum me
        }
    }
    cout << "   Total = " << total << "\n";
}


int main() {
    cout << "TASK 3:\n"; sol_task3();
    return 0;
}