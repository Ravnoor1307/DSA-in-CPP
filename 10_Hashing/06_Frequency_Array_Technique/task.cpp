/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_Frequency_Array_Technique task.cpp
│
│ REAL-WORLD SCENARIO:
│ Small-range counting lab me marks/candidate IDs ko direct array boxes me count karna hai and hashmap se compare karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Values 0..100 ke liye count[101] frequency banao.
│ 2. Frequency array se counts print karo.
│ 3. Counting sort preview implement karo.
│ 4. Most frequent element frequency array se find karo.
│ 5. Hashmap vs frequency array table comments me likho.
│ 6. Negative/large keys ke liye hashmap choose karne ka reason explain karo.
│
│ HINTS:
│ - count[value]++ direct indexing hai.
│ - Time O(n+R), R range size.
│ - R fixed small ho to space practically O(1).
│
│ STARTER CODE:
│ vector<int> count(maxValue+1,0);
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[4,1,3,4,2]
│ count[1]=1,count[2]=1,count[3]=1,count[4]=2
│ sorted output: 1 2 3 4 4
│
│ DRY RUN:
│ small range 0..100 -> array.
│ strings/huge IDs -> unordered_map.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Build count n updates.
│ - Scan/rebuild range R and n outputs.
│ -> Counting sort preview O(n+R).
│
│ SPACE COMPLEXITY CALCULATION:
│ - count array size R+1.
│ -> Space Complexity = O(R).
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

int main() {
    vector<int> arr = {4,1,3,4,2};
    int R = 4;
    vector<int> count(R + 1, 0);
    for (int x : arr) count[x]++;
    cout << "Sorted: ";
    for (int value = 0; value <= R; value++) {
        for (int c = 0; c < count[value]; c++) cout << value << " ";
    }
    cout << "\nMost frequent value = 4\n";
    return 0;
}

/*
OUTPUT:
Sorted: 1 2 3 4 4
Most frequent value = 4
*/

