/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_Palindrome_Problems task.cpp
│
│ REAL-WORLD SCENARIO:
│ Mirror-word practice me words, phrases, and numbers ke palindromes check karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Reverse + compare palindrome check likho.
│ 2. Manual reverse string build karke check karo.
│ 3. Two-pointer O(1) space palindrome check karo.
│ 4. MADAM and RACECAR ka pointer dry run comments me banao.
│ 5. Ignore case and spaces: "Nitin" check karo.
│ 6. Ignore punctuation phrase: "A man, a plan, a canal: Panama".
│ 7. Number 121 ko string method se check karo.
│ 8. Complexity comparison table likho.
│
│ HINTS:
│ - tolower and isalnum use karo.
│ - Two pointers floor(n/2) pairs compare karte hain.
│ - Negative number palindrome nahi.
│
│ STARTER CODE:
│ bool isPal(string s){ int l=0,r=s.size()-1; }
│
│ SOLUTION: Neeche compiled demo hai.
│
│ ASCII VISUAL / POINTER STATE:
│ MADAM:
│ [M][A][D][A][M]
│  L           R -> match
│     L     R    -> match
│ center -> true
│
│ DRY RUN:
│ Nitin ignore case:
│ n vs n, i vs i, center t -> true
│ 121 -> "121" -> true
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Reverse approaches O(n) time because reverse/compare scan n chars.
│ - Two-pointer checks floor(n/2) pairs -> O(n).
│ - Ignore spaces pointer moves <= n -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Two-pointer approaches O(1) extra.
│ - Reverse and number-to-string use O(n)/O(d) extra.
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

bool isPal(const string& s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    cout << "MADAM -> " << (isPal("MADAM") ? "YES" : "NO") << "\n";
    string num = to_string(121);
    cout << "121 -> " << (isPal(num) ? "YES" : "NO") << "\n";
    cout << "Best basic approach: two pointers O(n) time and O(1) space.\n";
    return 0;
}

/*
OUTPUT:
MADAM -> YES
121 -> YES
Best basic approach: two pointers O(n) time and O(1) space.
*/

