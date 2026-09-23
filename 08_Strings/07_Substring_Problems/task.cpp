/*
═══════════════════════════════════════════════
 TASK SET — SUBSTRING PROBLEMS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A movie-clip and text-search practice session needs work on
    continuous substrings, pattern search, common prefixes, and palindromic
    substrings. These tasks cover the core tools behind search boxes, autocomplete
    prefixes, and mirror-word games.

 🧠 HOW TO SOLVE: A substring is continuous, so double loops i,j enumerate all of
    them. Search with the built-in find or a naive slide-and-compare. Longest common
    prefix compares characters column by column. For longest palindrome, either try
    every substring (brute O(n³)) or expand around each odd/even center (O(n²)).

 MODES/TOPICS COVERED:
  1. Print all substrings of "abc"
  2. Write the substring vs subsequence difference in comments
  3. Check a substring with the built-in find
  4. Implement naive substring matching
  5. Solve the longest common prefix
  6. Solve the longest palindromic substring with brute force
  7. Solve the longest palindromic substring with expand-around-center
  8. Draw odd and even center diagrams

 HINTS:
 - A substring is continuous.
 - LCP compares columns vertically.
 - Expand center: (c,c) and (c,c+1).

 STARTER CODE:
 for(int i=0;i<n;i++) for(int j=i;j<n;j++) ...

 SOLUTION: A compact demo is below.

 ASCII VISUAL / WINDOW STATE:
 "abc" substrings: a, ab, abc, b, bc, c
 LCP flower/flow/flight -> fl
 babad longest palindrome -> bab or aba

 DRY RUN:
 Naive match text abcde pattern cd:
 start0 fail, start1 fail, start2 match.
 Expand center handles odd bab and even abba.

 FLOW OF EXECUTION:
 input string(s) -> choose pattern/window/map -> update state -> return answer

 TIME COMPLEXITY CALCULATION:
 - Substrings count n(n+1)/2 = O(n²).
 - Naive search (n-m+1)*m = O(n*m).
 - Brute longest palindrome O(n³).
 - Expand center (2n-1)*n = O(n²).

 SPACE COMPLEXITY CALCULATION:
 - Most checks O(1) extra.
 - Output/answer strings can store O(n).
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

int main() {
    string s = "abc";
    cout << "Substrings: ";
    for (int i=0;i<(int)s.size();i++) {
        string cur;
        for (int j=i;j<(int)s.size();j++) { cur.push_back(s[j]); cout << cur << " "; }
    }
    cout << "\nfind cd in abcde = " << string("abcde").find("cd") << "\n";
    cout << "LCP example answer = fl\n";
    cout << "Longest palindrome expand is practiced in file 06.\n";
    return 0;
}

/*
OUTPUT:
Substrings: a ab abc b bc c
find cd in abcde = 2
LCP example answer = fl
Longest palindrome expand is practiced in file 06.
*/

