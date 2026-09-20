/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_pattern_recap_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank passbook me running balance maintain hota hai. Kisi date range ka total chahiye to end balance minus before-start balance kar do. Prefix sum same idea hai.
│
│ VISUAL / PATTERN STATE:
│ arr = [2,4,1,3]
│ prefix[0]=0
│ prefix[1]=2
│ prefix[2]=6
│ prefix[3]=7
│ prefix[4]=10
│
│ sum(l..r) = prefix[r+1] - prefix[l]
│ sum(1..3) = prefix[4] - prefix[1] = 10 - 2 = 8
│
│ Prefix + hash signal:
│ subarray sum equals k
│ store frequency of previous prefix sums.

│
│ STEP-BY-STEP DRY RUN:
│ Build prefix:
│ running=0
│ add2 -> 2
│ add4 -> 6
│ add1 -> 7
│ add3 -> 10
│ Query [1,3] means values 4+1+3=8.

│
│ COMPLEXITY CALCULATION:
│ Build prefix loops n elements -> n additions = O(n).
│ Each range query uses two array reads and one subtraction -> O(1).
│ Prefix array size n+1 -> O(n) space.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
    vector<int> a = {2,4,1,3};
    vector<int> prefix(a.size()+1, 0);
    for (int i=0;i<(int)a.size();i++) prefix[i+1] = prefix[i] + a[i];
    int l=1, r=3;
    cout << "Range sum [1,3] = " << prefix[r+1] - prefix[l] << "\n";
    return 0;
}

/*
OUTPUT:
Range sum [1,3] = 8
*/

