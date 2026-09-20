/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_substring_vs_subsequence_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Movie clip me continuous scene substring hota hai, lekin highlights me beech ke scenes skip ho sakte hain — woh subsequence hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Substring = continuous characters.
│ 2. Subsequence = order maintained, characters skip allowed.
│ 3. "abc" substrings: a,b,c,ab,bc,abc.
│ 4. "abc" subsequences: "", a,b,c,ab,ac,bc,abc.
│ 5. Every substring is subsequence, but every subsequence substring nahi hota.
│
│ ASCII VISUAL / WINDOW STATE:
│ s="abc"
│
│ Substrings continuous:
│ a, b, c, ab, bc, abc
│ ac is NOT substring because b skipped.
│
│ Subsequence tree:
│                ""
│             /       \
│          take a    skip a
│          /   \       /   \
│       ab     a     b     ""
│      ... choices for c ...
│ subsequences include ac because b skip allowed.
│
│ DRY RUN:
│ For "abc":
│ substring loops:
│ start0 -> a, ab, abc
│ start1 -> b, bc
│ start2 -> c
│ subsequence choice each char take/skip gives 2^3 = 8.
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Number of substrings: n choices start and up to n choices end = n(n+1)/2.
│ -> Listing substrings count is O(n²), printing chars can make O(n³).
│ - Number of subsequences: each char has 2 choices, so 2*2*... n times = 2^n.
│ -> Listing subsequences = O(2^n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Storing all substrings/subsequences can take large space.
│ - Demo lists only small examples.
│ -> Extra Space Complexity depends on output size.
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

int main() {
    string s = "abc";
    cout << "Substrings of abc: ";
    for (int i = 0; i < (int)s.size(); i++) {
        string cur;
        for (int j = i; j < (int)s.size(); j++) {
            cur.push_back(s[j]);
            cout << cur << " ";
        }
    }
    cout << "\nSubsequence example: ac is valid subsequence but not substring.\n";
    return 0;
}

/*
OUTPUT:
Substrings of abc: a ab abc b bc c
Subsequence example: ac is valid subsequence but not substring.
*/

