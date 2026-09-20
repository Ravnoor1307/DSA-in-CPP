/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_palindrome_approach2_two_pointers.cpp
│
│ REAL-WORLD SCENARIO:
│ MADAM word ko dono ends se compare karo: M with M, A with A, center D tak pointers milte hain. Ye two-pointer palindrome check hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. left=0, right=n-1.
│ 2. Jab tak left<right, s[left] and s[right] compare karo.
│ 3. Mismatch hua to false.
│ 4. Match hua to left++ and right--.
│ 5. Pointers meet/cross -> palindrome true.
│ 6. Extra string nahi banti.
│
│ ASCII VISUAL / POINTER STATE:
│ MADAM:
│ [M][A][D][A][M]
│  L           R   M==M -> move
│     L     R      A==A -> move
│        L         stop -> YES
│
│ RACECAR:
│ R==R, A==A, C==C, center E -> YES
│
│ DRY RUN:
│ s=madam
│ step1 left0 right4 M==M
│ step2 left1 right3 A==A
│ step3 left2 right2 stop
│ answer YES
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - At each step two characters checked.
│ - Pointer pair checks = floor(n/2).
│ - floor(n/2) grows linearly with n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only left and right variables.
│ -> Extra Space Complexity = O(1).
│ APPROACH COMPARISON TABLE:
│ Reverse compare = mirror photo copy, O(n) time/O(n) space.
│ Manual reverse = build reverse board, O(n) time/O(n) space.
│ Two pointers = compare from both doors, O(n) time/O(1) space.
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

bool isPalindromeTwoPointers(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        cout << "compare " << s[left] << " and " << s[right] << "\n";
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "MADAM";
    cout << s << " palindrome? " << (isPalindromeTwoPointers(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
compare M and M
compare A and A
MADAM palindrome? YES
*/

