
#include <iostream>
using namespace std;



// ---------------- TASK 5: max + position ----------------
void sol_task5() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int maxVal = mat[0][0], maxR = 0, maxC = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] > maxVal) {
                maxVal = mat[i][j];
                maxR = i;        // record ki position bhi save
                maxC = j;
            }
        }
    }
    cout << "   Max = " << maxVal << " at (" << maxR << "," << maxC << ")\n";
}

int main() {
    cout << "TASK 5:\n"; sol_task5();
    return 0;
}