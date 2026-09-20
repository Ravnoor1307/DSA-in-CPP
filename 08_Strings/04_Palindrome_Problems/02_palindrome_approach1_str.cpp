/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_palindrome_approach1_str.cpp
│
│ REAL-WORLD SCENARIO:
│ Security code ko reverse string build karke verify karna hai. Ye manual reverse-string build approach hai, STL reverse ke bina.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Empty reversed string banao.
│ 2. Original ke end se start tak characters append karo.
│ 3. Built reversed string ko original se compare karo.
│ 4. Ye approach logic clearly show karta hai.
│ 5. Extra string O(n) use hoti hai.
│
│ ASCII VISUAL / POINTER STATE:
│ s="racecar"
│ build reverse:
│ "" -> r -> ra -> rac -> race -> racec -> raceca -> racecar
│ original == reverse -> YES
│
│ DRY RUN:
│ i=6 r, i=5 a, i=4 c, i=3 e, i=2 c, i=1 a, i=0 r
│ reversed=racecar
│ compare true
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Reverse build loop runs n times.
│ - Compare loop internally up to n chars.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Reversed string stores n chars.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindromeManualReverse(const string& s) {
    string rev;
    for (int i = (int)s.size() - 1; i >= 0; i--) rev.push_back(s[i]);
    return s == rev;
}

int main() {
    string s = "racecar";
    cout << s << " palindrome? " << (isPalindromeManualReverse(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
racecar palindrome? YES
*/

