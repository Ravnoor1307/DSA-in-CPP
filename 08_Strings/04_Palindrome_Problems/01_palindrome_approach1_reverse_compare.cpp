/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_palindrome_approach1_reverse_compare.cpp
│
│ REAL-WORLD SCENARIO:
│ Word ko mirror me dekhne par agar same dikhe jaise MADAM, to palindrome hai. Simple approach: string reverse banao and original se compare karo.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Original string copy karo.
│ 2. Copy ko reverse karo.
│ 3. Original == reversed check karo.
│ 4. Same hua to palindrome.
│ 5. Easy but extra O(n) space use karta hai.
│
│ ASCII VISUAL / POINTER STATE:
│ s = "madam"
│ reverse = "madam"
│ same -> palindrome
│
│ s = "hello"
│ reverse = "olleh"
│ different -> not palindrome
│
│ DRY RUN:
│ madam:
│ copy madam
│ reverse copy -> madam
│ compare char by char all same -> YES
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Reverse copies/swaps n chars.
│ - Compare may check n chars.
│ - Total about 2n operations.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Reversed copy stores n characters.
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

bool isPalindromeReverseCompare(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    string s = "madam";
    cout << s << " palindrome? " << (isPalindromeReverseCompare(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
madam palindrome? YES
*/

