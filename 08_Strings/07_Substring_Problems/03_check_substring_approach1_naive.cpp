/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_check_substring_approach1_naive.cpp
│
│ REAL-WORLD SCENARIO:
│ Printed paragraph me word dhundhne ke liye ruler ko har possible position par slide karke compare kar sakte ho. Ye naive string matching hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Pattern length m, text length n.
│ 2. Pattern start position i from 0 to n-m try karo.
│ 3. For each i, pattern chars j=0..m-1 compare karo.
│ 4. All m match hue to substring found.
│ 5. Mismatch par next i try karo.
│
│ ASCII VISUAL / WINDOW STATE:
│ text="abcde", pattern="cd"
│
│ i=0: a b c d e
│      c d        mismatch at first
│ i=1: a b c d e
│        c d      mismatch at first
│ i=2: a b c d e
│          c d    match
│
│ Sliding pattern visual: pattern window moves right one step each time.
│
│ DRY RUN:
│ n=5,m=2
│ i=0 compare text[0]=a with c -> mismatch
│ i=1 compare text[1]=b with c -> mismatch
│ i=2 compare c==c and d==d -> found index2
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Start positions = n-m+1.
│ - For each position, up to m comparisons.
│ - Worst comparisons = (n-m+1)*m.
│ -> Time Complexity = O(n*m).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only loop variables used.
│ -> Extra Space Complexity = O(1).
│ APPROACH COMPARISON TABLE:
│ find() = text editor built-in search, concise, worst depends on implementation.
│ Naive = ruler slide at each index, O(n*m) time/O(1) space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

int naiveFind(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        cout << "try start " << i << ", matched chars=" << j << "\n";
        if (j == m) return i;
    }
    return -1;
}

int main() {
    cout << "Found index = " << naiveFind("abcde", "cd") << "\n";
    return 0;
}

/*
OUTPUT:
try start 0, matched chars=0
try start 1, matched chars=0
try start 2, matched chars=2
Found index = 2
*/

