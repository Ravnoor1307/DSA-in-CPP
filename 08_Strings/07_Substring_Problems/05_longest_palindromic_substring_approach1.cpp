/*
═══════════════════════════════════════════════
 LONGEST PALINDROMIC SUBSTRING — APPROACH 1 (BRUTE FORCE)
 ⏱️ TIME COMPLEXITY: O(n³) — O(n²) substrings each checked with an O(n) palindrome scan, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a mirror-word game, find the longest mirror segment inside a sentence. The brute
 force generates every substring and checks whether it is a palindrome.

 📖 THEORY:
 - Choose every start index i.
 - Choose every end index j.
 - Check whether the substring s[i..j] is a palindrome.
 - If it is a palindrome and longer than the current best, update the answer.
 - Simple but O(n³): O(n²) substrings times an O(n) palindrome check.

 ASCII VISUAL / WINDOW STATE:
 s="babad"
 substrings checked:
 b, ba, bab, baba, babad
 a, ab, aba, abad
 ...
 palindromes include "bab" and "aba"
 answer can be "bab".

 🧠 LOGIC — STEP BY STEP:
 Step 1: Loop i over every start index.
    WHY: every substring starts somewhere.
 Step 2: Loop j over every end index from i.
    WHY: together i,j enumerate all substrings.
 Step 3: Check if s[i..j] is a palindrome.
    WHY: only palindromic ranges are candidates.
 Step 4: If longer than best, store this substring.
    WHY: the task asks for the longest one.

 DRY RUN:
 i=0,j=2 substring bab -> palindrome len3 best=bab
 i=1,j=3 substring aba -> palindrome len3, same length
 no longer palindrome -> return bab

 FLOW OF EXECUTION:
 input string -> enumerate all substrings -> palindrome check each -> keep longest -> print result

 TIME COMPLEXITY CALCULATION:
 - Number of substrings = n(n+1)/2 = O(n²).
 - Palindrome check for each substring can scan up to n chars.
 - Total = O(n²*n) = O(n³).

 SPACE COMPLEXITY CALCULATION:
 - Temporary substring/check variables; answer stores up to n chars.
 -> Extra Space Complexity = O(n).
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

bool isPalRange(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

string longestPalindromeBrute(const string& s) {
    string best;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            if (len > (int)best.size() && isPalRange(s, i, j)) best = s.substr(i, len);
        }
    }
    return best;
}

int main() {
    cout << "Longest palindromic substring = " << longestPalindromeBrute("babad") << "\n";
    return 0;
}

/*
OUTPUT:
Longest palindromic substring = bab
*/

