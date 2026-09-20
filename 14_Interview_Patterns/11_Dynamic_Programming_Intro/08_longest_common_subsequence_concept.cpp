/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_longest_common_subsequence_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Two strings me longest common order sequence find karna hai. Characters match karein to diagonal +1, warna top/left ka best lo.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ text1 = abcde
│ text2 = ace
│ LCS = ace length 3
│
│ 2D DP table idea:
│ dp[i][j] = LCS length of first i chars of text1 and first j chars of text2
│
│ If text1[i-1] == text2[j-1]:
│   dp[i][j] = 1 + dp[i-1][j-1]
│ Else:
│   dp[i][j] = max(dp[i-1][j], dp[i][j-1])
│
│ Grid rows = text1 chars, cols = text2 chars.

│
│ STEP-BY-STEP DRY RUN:
│ Compare a with a -> match dp[1][1]=1.
│ b with c/e no match, carry best.
│ c with c -> dp[3][2]=2.
│ e with e -> dp[5][3]=3.

│
│ COMPLEXITY CALCULATION:
│ Let lengths n and m.
│ 2D table has (n+1)*(m+1) cells.
│ Each cell constant comparison/max.
│ Time = O(n*m).
│ Space = O(n*m).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    cout << "LCS length = " << longestCommonSubsequence("abcde", "ace") << "\n";
    return 0;
}

/*
OUTPUT:
LCS length = 3
*/

