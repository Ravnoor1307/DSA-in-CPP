/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_check_two_arrays_equal_freq.cpp
│
│ REAL-WORLD SCENARIO:
│ Do inventory boxes same items same quantities me hain ya nahi check karna hai. Frequency map add/subtract karke equality verify kar sakte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Length different ho to arrays equal nahi.
│ 2. First array ke elements freq++.
│ 3. Second array ke elements freq--.
│ 4. End me every frequency 0 honi chahiye.
│ 5. Order matter nahi karta, quantity matter karti hai.
│
│ ASCII VISUAL / HASH STATE:
│ A=[1,2,2,3]
│ B=[2,1,3,2]
│
│ freq after A:
│ 1:1, 2:2, 3:1
│ after subtract B:
│ 2:1, 1:0, 3:0, 2:0
│ all zero -> equal as multisets
│
│ DRY RUN:
│ scan A: freq 1:+1,2:+2,3:+1
│ scan B: 2 decreases,1 decreases,3 decreases,2 decreases
│ all 0 -> YES
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - First loop n increments.
│ - Second loop n decrements.
│ - Final loop d distinct keys checks.
│ - Total 2n+d, d<=n.
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Frequency map stores d distinct keys.
│ -> Space Complexity = O(d), worst O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool equalByFrequency(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return false;
    unordered_map<int,int> freq;
    for (int x : A) freq[x]++;
    for (int x : B) freq[x]--;
    for (const auto& p : freq) if (p.second != 0) return false;
    return true;
}

int main() {
    vector<int> A = {1,2,2,3};
    vector<int> B = {2,1,3,2};
    cout << "Arrays equal by frequency? " << (equalByFrequency(A,B) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Arrays equal by frequency? YES
*/

