/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_min_platforms_needed.cpp
│
│ REAL-WORLD SCENARIO:
│ Railway station par trains overlap kar rahi hain. Minimum platforms count karne ke liye arrivals and departures sorted, two pointers se active trains track karo.
│
│ ASCII VISUAL / DECISION STATE:
│ arrivals   = [900, 940, 950, 1100, 1500, 1800]
│ departures= [910,1200,1120,1130,1900,2000]
│ sorted dep = [910,1120,1130,1200,1900,2000]
│
│ Timeline:
│ 900 arrive -> platforms1
│ 910 depart -> platforms0
│ 940 arrive -> 1
│ 950 arrive -> 2
│ 1100 arrive -> 3 max
│ 1120 depart -> 2
│
│ Answer = 3

│
│ STEP-BY-STEP DRY RUN:
│ If next arrival <= next departure, train needs platform, i++.
│ Else one train departed, platform freed, j++.
│ Track max active platforms.

│
│ COMPLEXITY CALCULATION:
│ Sort arrivals O(n log n), sort departures O(n log n).
│ Two pointers i,j each move at most n -> O(n).
│ Total = O(n log n).
│ Extra space O(1) excluding sort stack.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int minPlatforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0, platforms = 0, best = 0, n = arr.size();
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            best = max(best, platforms);
            cout << "arrival " << arr[i] << " platforms=" << platforms << "\n";
            i++;
        } else {
            platforms--;
            cout << "departure " << dep[j] << " platforms=" << platforms << "\n";
            j++;
        }
    }
    return best;
}

int main() {
    vector<int> arr = {900,940,950,1100,1500,1800};
    vector<int> dep = {910,1200,1120,1130,1900,2000};
    cout << "Min platforms = " << minPlatforms(arr, dep) << "\n";
    return 0;
}

/*
OUTPUT:
arrival 900 platforms=1
departure 910 platforms=0
arrival 940 platforms=1
arrival 950 platforms=2
arrival 1100 platforms=3
departure 1120 platforms=2
departure 1130 platforms=1
departure 1200 platforms=0
arrival 1500 platforms=1
arrival 1800 platforms=2
Min platforms = 3
*/

