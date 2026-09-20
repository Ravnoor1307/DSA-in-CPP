/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_longest_palindromic_substring_approach1.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror-word game me sentence ke andar sabse lamba mirror segment dhundhna hai. Brute force har substring generate karke palindrome check karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har start index i choose karo.
│ 2. Har end index j choose karo.
│ 3. Substring s[i..j] palindrome hai ya nahi check karo.
│ 4. Agar palindrome and length best se badi, update answer.
│ 5. Simple but O(n³) because O(n²) substrings and O(n) check.
│
│ ASCII VISUAL / WINDOW STATE:
│ s="babad"
│ substrings checked:
│ b, ba, bab, baba, babad
│ a, ab, aba, abad
│ ...
│ palindromes include "bab" and "aba"
│ answer can be "bab".
│
│ DRY RUN:
│ i=0,j=2 substring bab -> palindrome len3 best=bab
│ i=1,j=3 substring aba -> palindrome len3, same length
│ no longer palindrome -> return bab
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Number of substrings = n(n+1)/2 = O(n²).
│ - Palindrome check for each substring can scan up to n chars.
│ - Total = O(n²*n) = O(n³).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Temporary substring/check variables; answer stores up to n chars.
│ -> Extra Space Complexity = O(n).
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

