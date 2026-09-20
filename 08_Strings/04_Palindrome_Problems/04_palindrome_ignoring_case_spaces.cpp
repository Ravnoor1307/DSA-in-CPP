/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_palindrome_ignoring_case_spaces.cpp
│
│ REAL-WORLD SCENARIO:
│ Famous phrase "A man a plan a canal Panama" spaces/case ignore karne par palindrome ban jata hai. Hume only letters/digits compare karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. left/right pointers use karo.
│ 2. Non-alphanumeric chars skip karo.
│ 3. Compare lowercase versions.
│ 4. Mismatch -> false.
│ 5. Pointers meet/cross -> true.
│ 6. Works for "Nitin" and phrase-style palindromes.
│
│ ASCII VISUAL / POINTER STATE:
│ "Nitin"
│ N vs n -> lowercase n==n
│ i vs i -> yes
│ t center -> YES
│
│ "A man a plan"
│ spaces skip:
│ A ... a compare lowercase
│ only alphanumeric characters considered.
│
│ DRY RUN:
│ s="Nitin"
│ left N, right n -> tolower both n match
│ left i, right i match
│ center t stop -> YES
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - left and right each move across string at most once.
│ - Total pointer moves <= n.
│ - Each move constant checks.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only two pointers and chars.
│ -> Extra Space Complexity = O(1).
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

bool validPalindromeClean(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) left++;
        while (left < right && !isalnum((unsigned char)s[right])) right--;
        char a = (char)tolower((unsigned char)s[left]);
        char b = (char)tolower((unsigned char)s[right]);
        cout << "compare " << a << " and " << b << "\n";
        if (a != b) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s1 = "Nitin";
    string s2 = "A man, a plan, a canal: Panama";
    cout << s1 << " -> " << (validPalindromeClean(s1) ? "YES" : "NO") << "\n";
    cout << "Phrase -> " << (validPalindromeClean(s2) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
compare n and n
compare i and i
Nitin -> YES
compare a and a
compare m and m
compare a and a
compare n and n
compare a and a
compare p and p
compare l and l
compare a and a
compare n and n
compare a and a
Phrase -> YES
*/

