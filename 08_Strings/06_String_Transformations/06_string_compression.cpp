/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_string_compression.cpp
│
│ REAL-WORLD SCENARIO:
│ Warehouse inventory me same items consecutive grouped hain. "aaabbc" ko "a3b2c1" likhne se compact count format milta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Current character and count track karo.
│ 2. Jab next char same ho, count++.
│ 3. Jab char change ho, current char + count answer me append karo.
│ 4. End me last group append karna na bhoolo.
│ 5. Edge case: single char "a" -> "a1".
│
│ ASCII VISUAL / COUNT STATE:
│ s="aaabbc"
│ groups:
│ aaa -> a3
│ bb  -> b2
│ c   -> c1
│ result = a3b2c1
│
│ Pointer visual:
│ [a][a][a][b][b][c]
│  count 1 2 3 flush a3, count b...
│
│ DRY RUN:
│ i=1 a same count2
│ i=2 a same count3
│ i=3 b different -> append a3, reset b1
│ i=4 b same count2
│ i=5 c different -> append b2, reset c1
│ end append c1
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop from index 1 to n-1 runs n-1 times.
│ - Each iteration constant compare/increment/append group.
│ - Total characters processed n.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Compressed answer can store up to about 2n chars (e.g., a1b1c1).
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string compressString(const string& s) {
    if (s.empty()) return "";
    string ans;
    char current = s[0];
    int count = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == current) count++;
        else {
            ans.push_back(current);
            ans += to_string(count);
            current = s[i];
            count = 1;
        }
    }
    ans.push_back(current);
    ans += to_string(count);
    return ans;
}

int main() {
    cout << "aaabbc -> " << compressString("aaabbc") << "\n";
    cout << "a -> " << compressString("a") << "\n";
    return 0;
}

/*
OUTPUT:
aaabbc -> a3b2c1
a -> a1
*/

