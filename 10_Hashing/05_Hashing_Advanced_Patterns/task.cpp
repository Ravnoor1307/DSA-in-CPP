/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_Hashing_Advanced_Patterns task.cpp
│
│ REAL-WORLD SCENARIO:
│ Advanced hashing lab me prefix-sum, sliding-window, frequency-grouping, and pair-sum patterns practice karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Zero-sum subarray exists check karo using prefix set.
│ 2. Given-sum subarray indices find karo using prefix map.
│ 3. Longest zero-sum subarray length find karo.
│ 4. Largest subarray with equal 0 and 1 find karo.
│ 5. Count distinct elements in every window of size k.
│ 6. Group elements by frequency.
│ 7. Four sum pair-hash concept implement/trace karo.
│ 8. Prefix map state after every step comments me draw karo.
│
│ HINTS:
│ - prefix repeated => zero sum.
│ - prefix-target seen => target subarray.
│ - Store first index for longest.
│ - Window: remove outgoing, add incoming.
│
│ STARTER CODE:
│ unordered_map<int,int> first; first[0] = -1;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[4,2,-3,1,6]
│ prefixes: 4,6,3,4 repeat -> zero-sum exists
│
│ 0/1 transform:
│ 0 -> -1, 1 -> +1
│
│ DRY RUN:
│ window [1,2,1,3], k=4 distinct=3
│ slide to [2,1,3,4] distinct=4
│
│ longest zero-sum uses gap between same prefix sums.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Prefix/hash scans n elements, avg O(1) map operations -> O(n).
│ - Window does k build + 2(n-k) updates -> O(n).
│ - Four sum pair count n(n-1)/2 -> O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Prefix maps store O(n).
│ - Window map stores O(k).
│ - Four sum pair map stores O(n²).
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

bool zeroSum(const vector<int>& a){
    unordered_set<int> seen; seen.insert(0);
    int prefix=0;
    for(int x:a){ prefix+=x; if(seen.count(prefix)) return true; seen.insert(prefix); }
    return false;
}
int main(){
    vector<int> a={4,2,-3,1,6};
    cout << "zero-sum exists? " << (zeroSum(a) ? "YES" : "NO") << "\n";
    cout << "Prefix + hash is O(n) average because n lookups/inserts.\n";
    cout << "Window distinct and 0/1 largest are in lesson files.\n";
    return 0;
}

/*
OUTPUT:
zero-sum exists? YES
Prefix + hash is O(n) average because n lookups/inserts.
Window distinct and 0/1 largest are in lesson files.
*/

