/*
REAL-WORLD SCENARIO:
Bank transaction passbook se fast range queries aur exact-period totals find karne hain.

TASKS easy -> hard:
1. Prefix array build karo.
2. sumRange(l,r) implement karo.
3. Subarray sum equals k using hashmap implement karo.
4. Product of array except self implement karo.
5. Prefix + suffix visual comments me draw karo.
6. Complexity calculations likho.

HINTS:
- prefix[0]=0.
- sumRange = prefix[r+1]-prefix[l].
- subarray sum k me freq[sum-k] count add hota hai.

STARTER CODE:
vector<int> prefix(n+1,0);

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
using namespace std;

int rangeSum(const vector<int>& a, int l, int r) {
    vector<int> prefix(a.size()+1, 0);
    for (int i=0;i<(int)a.size();i++) prefix[i+1] = prefix[i] + a[i];
    return prefix[r+1] - prefix[l];
}

int main() {
    vector<int> a = {2,4,1,3};
    cout << rangeSum(a,1,3) << "\n";
    return 0;
}

/*
OUTPUT:
8
*/
