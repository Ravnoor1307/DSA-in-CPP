/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_Hashing_Classic_Problems task.cpp
│
│ REAL-WORLD SCENARIO:
│ Classic hashing interview lab me Two Sum, distinct count, union/intersection, equality, first repeat/unique solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Two Sum brute force likho.
│ 2. Two Sum hashmap complement approach likho.
│ 3. Count distinct using sorting.
│ 4. Count distinct using unordered_set.
│ 5. Union and intersection using sets.
│ 6. Check two arrays equal using frequency map.
│ 7. First repeating element using frequency.
│ 8. First non-repeating element using frequency.
│
│ HINTS:
│ - Two Sum: need = target - x.
│ - Distinct: set size.
│ - Equality: freq++ and freq--.
│ - First repeat/non-repeat: second pass original order.
│
│ STARTER CODE:
│ unordered_map<int,int> mp;
│ if(mp.count(need)) return ...;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / HASH STATE:
│ Two Sum [2,7,11,15], target9:
│ i0 x2 need7 map{}
│ store 2:0
│ i1 x7 need2 map has 2 -> answer 0,1
│
│ DRY RUN:
│ distinct [4,2,4,3,2] -> 3.
│ first repeating [10,5,3,4,3,5,6] -> 5.
│ first non-repeating [4,5,1,2,1,4,5] -> 2.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Two Sum brute pair count n(n-1)/2 -> O(n²).
│ - Hashmap/set solutions n average O(1) operations -> O(n).
│ - Sorting uses n log n; n/2^k=1 -> k=log₂n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Hash solutions store up to n keys.
│ -> Space Complexity = O(n).
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

pair<int,int> twoSum(const vector<int>& a,int target){
    unordered_map<int,int> mp;
    for(int i=0;i<(int)a.size();i++){
        int need=target-a[i];
        if(mp.count(need)) return {mp[need],i};
        mp[a[i]]=i;
    }
    return {-1,-1};
}

int main(){
    vector<int> a={2,7,11,15};
    pair<int,int> ans=twoSum(a,9);
    cout << "two sum indices=" << ans.first << "," << ans.second << "\n";
    unordered_set<int> st({4,2,4,3,2});
    cout << "distinct count=" << st.size() << "\n";
    return 0;
}

/*
OUTPUT:
two sum indices=0,1
distinct count=3
*/

