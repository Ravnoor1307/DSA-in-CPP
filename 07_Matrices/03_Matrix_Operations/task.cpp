/*
┌────────────────────────────────────────────────────────────┐
│ FILE: task.cpp
│
│ REAL-WORLD SCENARIO:
│ Excel operation lab me same tables ko add/subtract, product table multiply, and rows-columns flip karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Same-size 2x3 matrices add karo.
│ 2. Same-size 2x2 matrices subtract karo.
│ 3. Dimension validation function banao.
│ 4. 2x2 matrix multiplication implement karo.
│ 5. Transpose for rectangular matrix implement karo.
│ 6. Square matrix in-place transpose implement karo.
│ 7. Matrix power repeated multiplication implement karo.
│ 8. Har operation ki complexity calculation comment me likho.
│
│ HINTS:
│ - Multiplication: C[i][j] += A[i][k]*B[k][j].
│ - Result dimensions A rows x B cols.
│ - Square transpose: swap only when j>i.
│
│ STARTER CODE IDEA:
│ for i rows -> for j cols -> compute cell.
│
│ SOLUTION: Neeche short compiled solution hai.
│
│ ASCII VISUAL / MEMORY DIAGRAM:
│ Multiplication dry run:
│ A=[1 2;3 4], B=[5 6;7 8]
│ C00=1*5+2*7=19
│ C01=1*6+2*8=22
│ C10=3*5+4*7=43
│ C11=3*6+4*8=50
│
│ DRY RUN:
│ Addition 2x2:
│ [1 2] + [10 20] = [11 22]
│ [3 4]   [30 40]   [33 44]
│ Transpose: [1 2 3;4 5 6] -> [1 4;2 5;3 6]
│
│ FLOW OF EXECUTION:
│ setup matrices -> validate condition -> nested loops/formula -> output matrix
│
│ COMPLEXITY CALCULATION:
│ - Add/sub/transpose visit R*C cells = O(R*C).
│ - Multiplication loops m*p*n = O(m*n*p).
│ - Repeated power k times multiply = O(k*n³).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Output matrices store result cells.
│ -> Space ranges from O(1) in-place to O(R*C).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> multiply2(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> C(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) C[i][j] += A[i][k] * B[k][j];
    return C;
}

int main() {
    vector<vector<int>> A = {{1,2},{3,4}};
    vector<vector<int>> B = {{5,6},{7,8}};
    vector<vector<int>> C = multiply2(A, B);
    cout << "2x2 multiplication result:\n";
    for (const auto& row : C) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "Condition: A columns must equal B rows.\n";
    cout << "Transpose trick: T[j][i] = A[i][j].\n";
    return 0;
}

/*
OUTPUT:
2x2 multiplication result:
19 22
43 50
Condition: A columns must equal B rows.
Transpose trick: T[j][i] = A[i][j].
*/

