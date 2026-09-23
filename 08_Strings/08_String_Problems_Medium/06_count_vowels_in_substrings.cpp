/*
═══════════════════════════════════════════════
 COUNT VOWELS IN SUBSTRINGS (PREFIX SUM)
 ⏱️ TIME COMPLEXITY: build O(n), each query O(1) — for q queries total O(n+q), extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A text-analytics dashboard needs vowel counts over repeated substring ranges. A
 prefix sum answers every query instantly.

 📖 THEORY:
 - prefix[i+1] = prefix[i] + isVowel(s[i]).
 - prefix[k] stores the number of vowels in the first k characters.
 - The vowel count of a query l..r = prefix[r+1] - prefix[l].
 - Build once in O(n), then each query is O(1).
 - This is prefix sum applied to strings.

 ASCII VISUAL / WINDOW STATE:
 s="leetcode"
 index: 0 1 2 3 4 5 6 7
 char:  l e e t c o d e
 vowel: 0 1 1 0 0 1 0 1
 prefix:0 0 1 2 2 2 3 3 4

 query [1,3] = "eet"
 vowels = prefix[4]-prefix[1] = 2-0 = 2

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create prefix of size n+1, all zero.
    WHY: prefix[k] represents the first k characters.
 Step 2: For each i, prefix[i+1] = prefix[i] + (isVowel ? 1 : 0).
    WHY: each character adds 1 if it is a vowel.
 Step 3: Answer a query l..r as prefix[r+1] - prefix[l].
    WHY: subtracting the prefix before l isolates the range.
 Step 4: Note the build is O(n) and each query O(1).
    WHY: this is why prefix sums are used for repeated range queries.

 DRY RUN:
 Build prefix:
 i0 l -> prefix1=0
 i1 e -> prefix2=1
 i2 e -> prefix3=2
 i3 t -> prefix4=2
 query 1,3 -> prefix4-prefix1=2

 FLOW OF EXECUTION:
 input string -> build vowel prefix -> answer range query by subtraction -> print count

 TIME COMPLEXITY CALCULATION:
 - Build prefix scans n chars once.
 - Each query uses two array accesses and one subtraction.
 -> Build Time = O(n), Query Time = O(1).
 - For q queries total = O(n+q).

 SPACE COMPLEXITY CALCULATION:
 - Prefix array stores n+1 integers.
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
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

