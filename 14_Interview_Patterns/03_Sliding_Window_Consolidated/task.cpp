/*
REAL-WORLD SCENARIO:
CCTV camera contiguous road segment analyze kar raha hai.

TASKS easy -> hard:
1. Fixed window max sum implement karo.
2. Longest substring with k distinct implement karo.
3. Fruits into baskets solve karo.
4. Max consecutive ones III solve karo.
5. Min window substring concept implement karo.
6. Universal template comments me likho.

HINTS:
- right expand karta hai.
- invalid condition par left shrink karta hai.
- Map frequency zero hone par erase karo.

STARTER CODE:
for (int right=0; right<n; right++) { }

SOLUTIONS below.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestKDistinct(const string& s, int k) {
    unordered_map<char,int> freq;
    int left=0, best=0;
    for (int right=0; right<(int)s.size(); right++) {
        freq[s[right]]++;
        while ((int)freq.size() > k) {
            char ch=s[left++];
            if (--freq[ch] == 0) freq.erase(ch);
        }
        best=max(best, right-left+1);
    }
    return best;
}

int main() {
    cout << longestKDistinct("eceba", 2) << "\n";
    return 0;
}

/*
OUTPUT:
3
*/
