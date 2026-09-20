/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_palindrome_check_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Number plate 12321 dono side se same read hoti hai. Number ko string form me dekh kar two-pointer recursion se outer digits compare karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Number/string ke left and right pointers set karo.
│ 2. Base case: left >= right means all pairs matched.
│ 3. If s[left] != s[right], false.
│ 4. Else recursive call on inner substring left+1,right-1.
│ 5. Ye two-pointer palindrome ka recursive version hai.
│
│ ASCII VISUAL / NUMBER STATE:
│ s="12321"
│ [1][2][3][2][1]
│  L           R -> 1==1, recurse
│     L     R    -> 2==2, recurse
│        L       -> base true
│
│ s="1234": 1!=4 -> false
│
│ DRY RUN:
│ check(0,4): 1==1
│ check(1,3): 2==2
│ check(2,2): base true
│ final YES
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Each call compares one outer pair.
│ - Pair count = floor(d/2), where d digits/chars.
│ -> Time Complexity = O(d).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth floor(d/2).
│ - String conversion stores d chars.
│ -> Space Complexity = O(d).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindromeRec(const string& s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalindromeRec(s, left + 1, right - 1);
}

int main() {
    int num = 12321;
    string s = to_string(num);
    cout << num << " palindrome? " << (isPalindromeRec(s, 0, (int)s.size() - 1) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
12321 palindrome? YES
*/

