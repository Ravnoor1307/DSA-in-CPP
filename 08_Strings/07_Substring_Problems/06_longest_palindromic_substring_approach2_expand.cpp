/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_longest_palindromic_substring_approach2_expand.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror segment ka center pakdo aur dono taraf expand karo. Har possible center se expand karke longest palindrome substring mil sakta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Palindrome center ke around symmetric hota hai.
│ 2. Odd length center: one index c,c.
│ 3. Even length center: gap c,c+1.
│ 4. Expand while left/right valid and chars equal.
│ 5. Best length update karo.
│ 6. Total centers about 2n-1, each expand O(n) worst -> O(n²).
│
│ ASCII VISUAL / WINDOW STATE:
│ s="babad"
│
│ Odd center at a(index1):
│ b a b
│ L C R -> b==b expand gives "bab"
│
│ Odd center at b(index2):
│ a b a -> gives "aba"
│
│ Even centers handle strings like "abba":
│ a b b a
│   L R   b==b, then a==a -> "abba"
│
│ DRY RUN:
│ center 1 odd:
│ l=1,r=1 -> a match
│ l=0,r=2 -> b==b -> palindrome bab
│ l=-1 stop, best=bab
│ even center 1,2 -> a vs b mismatch
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - There are n odd centers and n-1 even centers, total 2n-1 centers.
│ - Each expansion can move left/right at most n steps in worst case.
│ - Total worst work = (2n-1)*n.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only indices and bestStart/bestLen used.
│ - Returned substring stores best length up to n.
│ -> Extra Space Complexity = O(1) ignoring returned answer, O(n) including answer.
│ APPROACH COMPARISON TABLE:
│ Brute force = try every mirror strip, O(n³) time/O(n) answer space.
│ Expand around center = stand at mirror center and grow, O(n²) time/O(1) extra.
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

pair<int,int> expand(const string& s, int l, int r) {
    while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
        l--; r++;
    }
    return {l + 1, r - l - 1}; // start, length
}

string longestPalindromeExpand(const string& s) {
    int bestStart = 0, bestLen = 0;
    for (int c = 0; c < (int)s.size(); c++) {
        pair<int,int> odd = expand(s, c, c);
        pair<int,int> even = expand(s, c, c + 1);
        if (odd.second > bestLen) { bestStart = odd.first; bestLen = odd.second; }
        if (even.second > bestLen) { bestStart = even.first; bestLen = even.second; }
    }
    return s.substr(bestStart, bestLen);
}

int main() {
    cout << "Longest palindromic substring = " << longestPalindromeExpand("babad") << "\n";
    cout << "Even center example abba -> " << longestPalindromeExpand("abba") << "\n";
    cout << "Comparison: brute O(n^3), expand-center O(n^2).\n";
    return 0;
}

/*
OUTPUT:
Longest palindromic substring = bab
Even center example abba -> abba
Comparison: brute O(n^3), expand-center O(n^2).
*/

