/*
═══════════════════════════════════════════════
 LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS — APPROACH 1 (BRUTE FORCE)
 ⏱️ TIME COMPLEXITY: O(n³) — O(n²) substrings each checked with an up-to-O(n) uniqueness scan, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A music playlist needs a continuous segment in which no song repeats. The brute
 force checks every substring for uniqueness.

 📖 THEORY:
 - Choose every start i.
 - Choose every end j.
 - Check whether s[i..j] has all unique characters.
 - If the unique substring is longer than the best, update the answer.
 - Three levels of work: start, end, uniqueness scan -> O(n³).

 ASCII VISUAL / WINDOW STATE:
 s="abcabcbb"
 substrings:
 a, ab, abc valid length3
 abca invalid repeat a
 start1 bca valid length3
 longer unique not found
 answer=3

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i over every start index.
    WHY: every candidate substring starts somewhere.
 Step 2: Loop j over every end index from i.
    WHY: together i,j enumerate all substrings.
 Step 3: Check uniqueness of s[i..j] with a seen array.
    WHY: only all-unique ranges are valid.
 Step 4: If valid, update best = max(best, j-i+1).
    WHY: the answer is the longest such range.

 DRY RUN:
 i=0:
 j=0 a valid len1
 j=1 ab valid len2
 j=2 abc valid len3
 j=3 abca has repeated a invalid

 FLOW OF EXECUTION:
 input string -> enumerate substrings -> check uniqueness -> keep longest -> print result

 TIME COMPLEXITY CALCULATION:
 - Number of substrings = n(n+1)/2 = O(n²).
 - Checking uniqueness can scan substring up to n chars.
 - Total = O(n²*n) = O(n³).

 SPACE COMPLEXITY CALCULATION:
 - seen array 256 inside check fixed size.
 -> Extra Space Complexity = O(1).
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

bool allUnique(const string& s, int l, int r) {
    vector<bool> seen(256, false);
    for (int i = l; i <= r; i++) {
        unsigned char ch = s[i];
        if (seen[ch]) return false;
        seen[ch] = true;
    }
    return true;
}

int longestUniqueBrute(const string& s) {
    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i; j < (int)s.size(); j++) {
            if (allUnique(s, i, j)) best = max(best, j - i + 1);
        }
    }
    return best;
}

int main() {
    cout << "Longest unique substring length brute = " << longestUniqueBrute("abcabcbb") << "\n";
    return 0;
}

/*
OUTPUT:
Longest unique substring length brute = 3
*/

