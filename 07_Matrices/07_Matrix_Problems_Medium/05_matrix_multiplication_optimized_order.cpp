/*
═══════════════════════════════════════════════
 MATRIX CHAIN MULTIPLICATION — OPTIMIZED ORDER
 ⏱️ TIME COMPLEXITY: O(n³) — length × i × split loops
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A factory must run three machines in a multiplication order. Any
 order yields the same final matrix, but a wrong order costs far
 more operations. Matrix Chain Multiplication picks the order with
 the minimum scalar multiplications.

 📖 THEORY:
 - Multiplying a p×q and a q×r matrix costs p*q*r scalar
   multiplications.
 - Multiplication is associative but NOT cost-neutral:
   (A1A2)A3 and A1(A2A3) give the same matrix with different costs.
 - DP (preview): dp[i][j] = minimum cost to multiply matrices
   i..j. Formula: dp[i][j] = min over k of dp[i][k] + dp[k+1][j]
   + dims[i]*dims[k+1]*dims[j+1].
 - This preview motivates dynamic programming, which is studied
   later in detail.

 ASCII DIAGRAM:
 Dimensions: [10, 30, 5, 60]
 A1 = 10x30
 A2 = 30x5
 A3 = 5x60

 Option 1: (A1A2)A3
  cost A1A2      = 10*30*5 = 1500
  cost result*A3 = 10*5*60 = 3000
  total = 4500

 Option 2: A1(A2A3)
  cost A2A3      = 30*5*60 = 9000
  cost A1*result = 10*30*60 = 18000
  total = 27000

 Best = 4500

 🧠 LOGIC — STEP BY STEP:
 Step 1: Base case dp[i][i] = 0.
    WHY: Multiplying a single matrix costs nothing.
 Step 2: Loop over segment length len = 2..n.
    WHY: Longer products are built from shorter, already-solved
    segments.
 Step 3: For each start i, compute j = i + len - 1.
 Step 4: Try every split k from i to j-1.
    WHY: The last multiplication joins the left product (i..k) and
    the right product (k+1..j), costing
    dims[i]*dims[k+1]*dims[j+1].
 Step 5: Keep dp[i][j] = min over all splits.
    WHY: The cheapest way to multiply i..j is the cheapest split
    plus its joining cost.
 Step 6: Answer = dp[0][n-1].

 DRY RUN:
 dp[0][0]=dp[1][1]=dp[2][2]=0
 length 2:
  dp[0][1] = 10*30*5 = 1500
  dp[1][2] = 30*5*60 = 9000
 length 3:
  split k=0: 0 + 9000 + 10*30*60 = 27000
  split k=1: 1500 + 0 + 10*5*60 = 4500
  dp[0][2] = 4500

 FLOW OF EXECUTION:
 dimension array -> base dp[i][i]=0 -> segment length loop -> split k loop -> min cost -> answer dp[0][n-1]

 TIME COMPLEXITY CALCULATION:
 - Let the number of matrices = n.
 - DP length loop runs n choices.
 - i loop runs up to n choices.
 - Split k loop runs up to n choices.
 - Total approximately n*n*n = n³.
 -> Time Complexity = O(n³)

 SPACE COMPLEXITY CALCULATION:
 - dp table stores n*n costs.
 -> Space Complexity = O(n²)
═══════════════════════════════════════════════
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

