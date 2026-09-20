/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_matrix_multiplication_optimized_order.cpp
│
│ REAL-WORLD SCENARIO:
│ Factory me 3 machines ko multiply order me chalana hai. Same final matrix milega, but wrong order zyada operations leta hai. Matrix Chain Multiplication optimized order choose karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Matrix dimensions chain: A1(d0*d1), A2(d1*d2), ...
│ 2. Multiplication associative hai: (A1A2)A3 or A1(A2A3) result same dimensions de sakte hain.
│ 3. Cost different hota hai: multiplying p*q and q*r costs p*q*r scalar multiplications.
│ 4. DP preview: dp[i][j] = min cost to multiply matrices i..j.
│ 5. Try split k between i and j, take minimum.
│ 6. Ye DP topic ka preview hai, matrix operations me motivation ke liye important hai.
│
│ ASCII VISUAL / STATE DIAGRAM:
│ Dimensions: [10, 30, 5, 60]
│ A1 = 10x30
│ A2 = 30x5
│ A3 = 5x60
│
│ Option 1: (A1A2)A3
│ cost A1A2 = 10*30*5 = 1500
│ cost result*A3 = 10*5*60 = 3000
│ total = 4500
│
│ Option 2: A1(A2A3)
│ cost A2A3 = 30*5*60 = 9000
│ cost A1*result = 10*30*60 = 18000
│ total = 27000
│
│ Best = 4500
│
│ DRY RUN:
│ dp[0][0]=dp[1][1]=dp[2][2]=0
│ length2:
│ dp[0][1]=10*30*5=1500
│ dp[1][2]=30*5*60=9000
│ length3:
│ split k=0: 0+9000+10*30*60=27000
│ split k=1: 1500+0+10*5*60=4500
│ dp[0][2]=4500
│
│ FLOW OF EXECUTION:
│ input matrix -> choose approach -> transform/mark/DP -> print final answer
│
│ COMPLEXITY CALCULATION:
│ - Let number of matrices = n.
│ - DP length loop runs n choices.
│ - i loop runs up to n choices.
│ - split k loop runs up to n choices.
│ - Total approx n*n*n = n³.
│ -> Time Complexity = O(n³).
│
│ SPACE COMPLEXITY CALCULATION:
│ - dp table stores n*n costs.
│ -> Space Complexity = O(n²).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

int matrixChainMinCost(const vector<int>& dims) {
    int n = (int)dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                cout << "dp[" << i << "][" << j << "] split " << k << " cost=" << cost << "\n";
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> dims = {10, 30, 5, 60};
    cout << "Minimum scalar multiplications = " << matrixChainMinCost(dims) << "\n";
    return 0;
}

/*
OUTPUT:
dp[0][1] split 0 cost=1500
dp[1][2] split 1 cost=9000
dp[0][2] split 0 cost=27000
dp[0][2] split 1 cost=4500
Minimum scalar multiplications = 4500
*/

