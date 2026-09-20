/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_stl_min_priority_queue.cpp
│
│ REAL-WORLD SCENARIO:
│ Token counter me smallest token number pehle serve hota hai. STL priority_queue default max hai, but `greater<int>` comparator se min heap ban jata hai.
│
│ VISUAL / DRY RUN:
│ Max heap default:
│ priority_queue<int> maxPQ; top = largest
│
│ Min heap trick:
│ priority_queue<int, vector<int>, greater<int>> minPQ;
│ top = smallest
│
│ Values: 50,30,70,20
│ Max PQ priority order: 70 50 30 20
│ Min PQ priority order: 20 30 50 70
│
│ `greater<int>` ka meaning:
│ Smaller value ko higher priority do.

│
│ COMPLEXITY CALCULATION:
│ Internally heap operations same hain.
│ push -> O(log n)
│ pop -> O(log n)
│ top -> O(1)
│
│ `greater<int>` comparator constant time comparison karta hai,
│ so asymptotic complexity same rehti hai.
│ Space = O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iomanip>
using namespace std;

template <typename PQ>
void printByPopping(PQ pq, const string& label) {
    cout << label << ": ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << "\n";
}

int main() {
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ; // Min heap trick.
    for (int x : {50, 30, 70, 20}) {
        maxPQ.push(x);
        minPQ.push(x);
    }
    printByPopping(maxPQ, "Max PQ");
    printByPopping(minPQ, "Min PQ");
    return 0;
}

/*
OUTPUT:
Max PQ: 70 50 30 20
Min PQ: 20 30 50 70
*/

