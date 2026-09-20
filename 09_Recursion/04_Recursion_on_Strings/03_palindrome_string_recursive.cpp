/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_palindrome_string_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror-word RACECAR ko dono ends se check karo. Agar outer letters match, inner word ko recursively check karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function isPal(s,left,right).
│ 2. Base case: left >= right return true.
│ 3. If s[left] != s[right], return false.
│ 4. Else recurse left+1,right-1.
│ 5. This is recursive two-pointer palindrome.
│
│ ASCII VISUAL / STRING STATE:
│ RACECAR:
│ [R][A][C][E][C][A][R]
│  L                 R -> R==R
│     L           R    -> A==A
│        L     R       -> C==C
│           L          -> base true
│
│ DRY RUN:
│ racecar:
│ compare r/r, a/a, c/c, center e.
│ all match -> YES
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - Each call compares one pair.
│ - Number of pair comparisons floor(n/2).
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth floor(n/2)+1.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalRec(const string& s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalRec(s, left + 1, right - 1);
}

int main() {
    string s = "racecar";
    cout << s << " palindrome? " << (isPalRec(s, 0, (int)s.size()-1) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
racecar palindrome? YES
*/

