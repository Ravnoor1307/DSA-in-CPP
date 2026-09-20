/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_longest_substring_without_repeat_approach1.cpp
│
│ REAL-WORLD SCENARIO:
│ Music playlist me continuous segment chahiye jisme koi song repeat na ho. Brute force har substring check karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har start i choose karo.
│ 2. Har end j choose karo.
│ 3. s[i..j] unique hai ya nahi check karo.
│ 4. Unique substring length best se badi ho to update.
│ 5. Three-level work: start, end, uniqueness scan -> O(n³).
│
│ ASCII VISUAL / WINDOW STATE:
│ s="abcabcbb"
│ substrings:
│ a, ab, abc valid length3
│ abca invalid repeat a
│ start1 bca valid length3
│ longer unique not found
│ answer=3
│
│ DRY RUN:
│ i=0:
│ j=0 a valid len1
│ j=1 ab valid len2
│ j=2 abc valid len3
│ j=3 abca has repeated a invalid
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Number of substrings = n(n+1)/2 = O(n²).
│ - Checking uniqueness can scan substring up to n chars.
│ - Total = O(n²*n) = O(n³).
│
│ SPACE COMPLEXITY CALCULATION:
│ - seen array 256 inside check fixed size.
│ -> Extra Space Complexity = O(1).
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

bool allUnique(const string& s, int l, int r) {
    vector<bool> seen(256, false);
    for (int i = l; i <= r; i++) {
        unsigned char ch = s[i];
        if (seen[ch]) return false;
        seen[ch] = true;
    }
    return true;
}

int longestUniqueBrute(const string& s) {
    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i; j < (int)s.size(); j++) {
            if (allUnique(s, i, j)) best = max(best, j - i + 1);
        }
    }
    return best;
}

int main() {
    cout << "Longest unique substring length brute = " << longestUniqueBrute("abcabcbb") << "\n";
    return 0;
}

/*
OUTPUT:
Longest unique substring length brute = 3
*/

