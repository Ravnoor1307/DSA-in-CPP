/*
═══════════════════════════════════════════════
 CHECK SUBSTRING — APPROACH 1 (NAIVE MATCHING)
 ⏱️ TIME COMPLEXITY: O(n*m) — start positions n-m+1, up to m comparisons each, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 To find a word in a printed paragraph, slide a ruler over every possible position
 and compare. This is naive string matching.

 📖 THEORY:
 - Pattern length is m, text length is n.
 - Try every start position i from 0 to n-m.
 - For each i, compare pattern chars j=0..m-1.
 - If all m chars match, the substring is found.
 - On a mismatch, try the next i.

 ASCII VISUAL / WINDOW STATE:
 text="abcde", pattern="cd"

 i=0: a b c d e
      c d        mismatch at first
 i=1: a b c d e
        c d      mismatch at first
 i=2: a b c d e
          c d    match

 Sliding pattern visual: pattern window moves right one step each time.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Let n = text length and m = pattern length.
    WHY: the loop bounds depend on both lengths.
 Step 2: For i from 0 to n-m, try each start.
    WHY: a pattern of length m can start at most at n-m.
 Step 3: Compare pattern[j] with text[i+j] for j=0..m-1.
    WHY: a full run of m matches means the pattern occurs at i.
 Step 4: On the first mismatch, break and try the next i.
    WHY: one mismatch invalidates that start position.
 Step 5: Return i on a full match, else -1.
    WHY: the index is the answer; -1 means not found.

 DRY RUN:
 n=5,m=2
 i=0 compare text[0]=a with c -> mismatch
 i=1 compare text[1]=b with c -> mismatch
 i=2 compare c==c and d==d -> found index2

 FLOW OF EXECUTION:
 input strings -> slide pattern over text -> compare m chars per start -> return first matching index

 TIME COMPLEXITY CALCULATION:
 - Start positions = n-m+1.
 - For each position, up to m comparisons.
 - Worst comparisons = (n-m+1)*m.
 -> Time Complexity = O(n*m).

 SPACE COMPLEXITY CALCULATION:
 - Only loop variables used.
 -> Extra Space Complexity = O(1).
 APPROACH COMPARISON TABLE:
 find() = text editor built-in search, concise, worst depends on implementation.
 Naive = ruler slide at each index, O(n*m) time/O(1) space.
═══════════════════════════════════════════════
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

