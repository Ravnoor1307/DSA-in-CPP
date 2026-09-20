/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_count_vowels_in_substrings.cpp
│
│ REAL-WORLD SCENARIO:
│ Text analytics dashboard ko repeated substring ranges me vowels count karne hain. Prefix sum se har query instant answer de sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. prefix[i+1] = prefix[i] + isVowel(s[i]).
│ 2. prefix[k] stores vowels in first k characters.
│ 3. Query l..r ka vowel count = prefix[r+1] - prefix[l].
│ 4. Build once O(n), each query O(1).
│ 5. This is prefix sum on strings.
│
│ ASCII VISUAL / WINDOW STATE:
│ s="leetcode"
│ index: 0 1 2 3 4 5 6 7
│ char:  l e e t c o d e
│ vowel: 0 1 1 0 0 1 0 1
│ prefix:0 0 1 2 2 2 3 3 4
│
│ query [1,3] = "eet"
│ vowels = prefix[4]-prefix[1] = 2-0 = 2
│
│ DRY RUN:
│ Build prefix:
│ i0 l -> prefix1=0
│ i1 e -> prefix2=1
│ i2 e -> prefix3=2
│ i3 t -> prefix4=2
│ query 1,3 -> prefix4-prefix1=2
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Build prefix scans n chars once.
│ - Each query uses two array accesses and one subtraction.
│ -> Build Time = O(n), Query Time = O(1).
│ - For q queries total = O(n+q).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Prefix array stores n+1 integers.
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

bool isVowelChar(char ch) {
    ch = (char)tolower((unsigned char)ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

int main() {
    string s = "leetcode";
    vector<int> prefix(s.size() + 1, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        prefix[i + 1] = prefix[i] + (isVowelChar(s[i]) ? 1 : 0);
    }
    int l = 1, r = 3;
    int count = prefix[r + 1] - prefix[l];
    cout << "Vowels in substring s[1..3] = " << count << "\n";
    cout << "Build O(n), each query O(1).\n";
    return 0;
}

/*
OUTPUT:
Vowels in substring s[1..3] = 2
Build O(n), each query O(1).
*/

