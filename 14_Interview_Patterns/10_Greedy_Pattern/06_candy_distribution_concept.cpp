/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_candy_distribution_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Kids line me ratings ke hisaab se candies deni hain. Higher rating than neighbor means more candy. Left-to-right and right-to-left two-pass greedy constraints satisfy karta hai.
│
│ ASCII VISUAL / DECISION STATE:
│ ratings = [1,0,2]
│
│ Start candies [1,1,1]
│ Left-to-right:
│ rating0 > rating1? no
│ rating2 > rating1 yes -> candies[2]=2
│ candies [1,1,2]
│
│ Right-to-left:
│ rating0 > rating1 yes -> candies[0]=max(1,2)=2
│ candies [2,1,2]
│ Total = 5
│
│ Why two passes?
│ Left pass handles increasing from left.
│ Right pass handles increasing from right.

│
│ STEP-BY-STEP DRY RUN:
│ First every child gets 1.
│ If ratings[i] > ratings[i-1], candies[i]=candies[i-1]+1.
│ If ratings[i] > ratings[i+1], candies[i]=max(candies[i], candies[i+1]+1).

│
│ COMPLEXITY CALCULATION:
│ First pass n-1 comparisons.
│ Second pass n-1 comparisons.
│ Sum candies n additions.
│ Total = 3n-2 -> O(n).
│ Candies array n -> O(n).

│ APPROACH COMPARISON TABLE:
│ | Greedy problem | Sorting/pass | Local choice | Time | Space |
│ | Activity selection | sort by end | earliest finish | O(n log n) | O(1) |
│ | Min platforms | sort arrivals/deps | active overlap count | O(n log n) | O(1) |
│ | Jump game | one scan | farthest reach | O(n) | O(1) |
│ | Candy | two passes | satisfy neighbor constraints | O(n) | O(n) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
    }
    int sum = 0;
    for (int x : candies) sum += x;
    cout << "Candies: "; for (int x : candies) cout << x << ' '; cout << "\n";
    return sum;
}

int main() {
    vector<int> ratings = {1,0,2};
    cout << "Minimum candies = " << candy(ratings) << "\n";
    return 0;
}

/*
OUTPUT:
Candies: 2 1 2
Minimum candies = 5
*/

