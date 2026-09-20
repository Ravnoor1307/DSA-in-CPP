/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_char_frequency_approach1_nested.cpp
│
│ REAL-WORLD SCENARIO:
│ Class monitor attendance me har student name ke letters count kar raha hai, but register baar-baar start se scan karta hai. Nested approach simple hai par slow.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. visited array use karo taaki same character repeat count na ho.
│ 2. Outer loop each character choose karta hai.
│ 3. Inner loop entire string me us character occurrences count karta hai.
│ 4. Already visited characters skip hote hain.
│ 5. Worst case nested loops O(n²).
│
│ ASCII VISUAL / COUNT STATE:
│ s="banana"
│ Outer b -> scan all -> count 1
│ Outer a -> scan all -> count 3
│ Outer n -> scan all -> count 2
│ Later a/n visited -> skip
│
│ Visual counts:
│ b:1, a:3, n:2
│
│ DRY RUN:
│ i=0 b: j=0..5 count=1
│ i=1 a: j=0..5 count=3
│ i=2 n: j=0..5 count=2
│ i=3 a visited skip
│ i=4 n visited skip
│ i=5 a visited skip
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Outer loop runs n times.
│ - Inner loop can run n times for each outer character.
│ - Worst comparisons = n*n = n².
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - visited array size n.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "banana";
    int n = s.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] == s[j]) {
                count++;
                visited[j] = true;
            }
        }
        cout << s[i] << " -> " << count << "\n";
    }
    return 0;
}

/*
OUTPUT:
b -> 1
a -> 3
n -> 2
*/

