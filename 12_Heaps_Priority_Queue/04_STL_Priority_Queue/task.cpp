/*
REAL-WORLD SCENARIO:
Hospital triage simulation STL priority_queue se implement karni hai.

TASKS easy -> hard:
1. Max priority queue me 10,20,30 push karke priority order print karo.
2. Min priority queue using greater<int> banao.
3. Patient object ke liye comparator likho.
4. Same severity par earlier arrival ko priority do.
5. stack, queue, priority_queue outputs compare karo.
6. Har operation ki complexity comments me calculate karo.

HINTS:
- `priority_queue<int>` max heap hai.
- `priority_queue<int, vector<int>, greater<int>>` min heap hai.
- Comparator me true ka matlab a has lower priority than b.

STARTER CODE:
struct Patient { string name; int severity; int arrival; };
struct Compare { bool operator()(const Patient& a, const Patient& b) const { return false; } };

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
using namespace std;

struct Patient { string name; int severity; int arrival; };
struct Compare {
    bool operator()(const Patient& a, const Patient& b) const {
        if (a.severity != b.severity) return a.severity < b.severity; // high severity pehle
        return a.arrival > b.arrival; // same severity: early arrival pehle
    }
};

int main() {
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    for (int x : {10, 20, 30}) { maxPQ.push(x); minPQ.push(x); }
    cout << "max top=" << maxPQ.top() << ", min top=" << minPQ.top() << "\n";

    priority_queue<Patient, vector<Patient>, Compare> patients;
    patients.push({"A", 4, 1});
    patients.push({"B", 9, 2});
    patients.push({"C", 9, 3});
    cout << "first patient=" << patients.top().name << "\n";
    return 0;
}

/*
OUTPUT:
max top=30, min top=10
first patient=B
*/
