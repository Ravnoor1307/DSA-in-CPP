/*
═══════════════════════════════════════════════
 TASK SET — STD::PRIORITY_QUEUE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
A hospital ER serves the most critical patient first, not the first
arrival. A KPI dashboard wants the top 3 selling products in a day.
An electrician wants to join cables of minimum length so total
joins cost the least. All of these reduce to "always grab the
biggest (or smallest) thing next" — exactly what std::priority_queue
(a heap) does in O(log n) per push/pop.

🧠 HOW TO SOLVE:
Default priority_queue is a MAX-heap (top = largest). Use
`greater<int>` to flip it to a MIN-heap. For "k largest", keep a
MIN-heap of size k: push bigger elements, evict the smallest. For
"kth smallest", keep a MAX-heap of size k instead. For cost
problems, keep popping the two tops and push back their sum.

 6-6 tasks EASY → HARD:
──────────────────────────────────────────────
 TASK 1 — k largest elements
 Statement: nums = {5, 10, 3, 7, 1, 9}, k = 3 → top 3 largest
            = {10, 9, 7} (order not important).
 💡 HINT: Min-heap of size k: if heap has k+1 elements, pop the
          smallest. Heap left with k largest.
 ✏️ STARTER CODE:
 // priority_queue<int, vector<int>, greater<int>> minH;
 // for (int x : nums) { minH.push(x);
 //   if (minH.size() > k) minH.pop(); }
 // // ab minH me k largest hain
──────────────────────────────────────────────
 TASK 2 — kth smallest element
 Statement: nums = {7, 10, 4, 3, 20, 15}, k = 3 → 3rd smallest = 7.
 💡 HINT: MAX-heap of size k. Top of heap = kth smallest.
 ✏️ STARTER CODE:
 // priority_queue<int> maxH;   // default max-heap
 // for (int x : nums) { maxH.push(x);
 //   if (maxH.size() > k) maxH.pop(); }
 // // answer = maxH.top()
──────────────────────────────────────────────
 TASK 3 — Connect ropes with minimum cost
 Statement: ropes {4, 3, 2, 6}. Joining two ropes costs their sum
            (that sum becomes a new rope). Minimum total cost = 29.
 💡 HINT: Always join the two SMALLEST ropes (greedy). Sum them,
          push the sum back, repeadd until one rope left.
 ✏️ STARTER CODE:
 // priority_queue<int, vector<int>, greater<int>> minH(ropes.begin(), ropes.end());
 // int cost = 0;
 // while (minH.size() > 1) {
 //   int a = minH.top(); minH.pop();
 //   int b = minH.top(); minH.pop();
 //   cost += a + b; minH.push(a + b);
 // }
──────────────────────────────────────────────
 TASK 4 — Sort by frequency using heap
 Statement: nums = {4, 1, 1, 1, 2, 2, 3} → output values sorted by
            decreasing frequency: 1 1 1 2 2 4 3.
 💡 HINT: Count in a map. Push (freq, value) into a max-heap
          (custom comparator), then pop and print value freq times.
 ✏️ STARTER CODE:
 // // map<int,int> freq; for (int x:nums) freq[x]++;
 // // pair (freq, value) ke liye max-heap — frequency zyada pehle
 // priority_queue<pair<int,int>> h; // default sorts by first (freq)
 // for (auto& p : freq) h.push(make_pair(p.second, p.first));
 // while (!h.empty()) { print h.top().second, h.top().first times; h.pop(); }
──────────────────────────────────────────────
 TASK 5 — Merge k sorted arrays (intro)
 Statement: Merge {1,4,7}, {2,5}, {3,6,8} → {1,2,3,4,5,6,7,8}.
 💡 HINT: Min-heap stores (value, whichArray, indexInArray). Pop
          smallest, push the NEXT element from the same array.
 ✏️ STARTER CODE:
 // // tuple(value, arrIdx, idx)
 // priority_queue<tuple<int,int,int>, vector<...>, greater<...>> minH;
 // for (i in 0..k) minH.push({a[i][0], i, 0});
 // while (!minH.empty()) { pop (v, r, c); ans.push_back(v);
 //   if (c+1 < a[r].size()) minH.push({a[r][c+1], r, c+1}); }
──────────────────────────────────────────────
 TASK 6 — Median of a stream (intro to two-heaps pattern)
 Statement: Insert 5, 15, 1, 3 → medians after each insert:
            5, 10, 5, 4.
 💡 HINT: TWO heaps — max-heap for smaller half, min-heap for
          larger half. Balance sizes so maxH is never more than
          minH by 2. Median = top of the bigger heap (or avg).
 ✏️ STARTER CODE:
 // priority_queue<int> lo;                       // smaller half (max-heap)
 // priority_queue<int, vector<int>, greater<int>> hi; // larger half (min-heap)
 // add(x): if lo empty or x <= lo.top() → lo else hi; then balance sizes.
 // median = lo.size() > hi.size() ? lo.top() : avg(lo.top(), hi.top());
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;

// ---------- TASK 1: k largest elements ----------
vector<int> kLargest(vector<int> nums, int k) {
    // chhota upe chadhega — to humesha smallest pop hoga, bade bach jayenge
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int x : nums) {
        minH.push(x);
        if ((int)minH.size() > k) minH.pop(); // size k rakh lo
    }
    vector<int> res;
    while (!minH.empty()) { res.push_back(minH.top()); minH.pop(); }
    return res;
}

void task1() {
    cout << "\n=== TASK 1: k largest elements (k=3) ===\n";
    vector<int> nums = {5, 10, 3, 7, 1, 9};
    vector<int> res = kLargest(nums, 3);
    cout << "Top 3 largest: ";
    for (int v : res) cout << v << " ";
    cout << endl;
}

// ---------- TASK 2: kth smallest element ----------
int kthSmallest(vector<int> nums, int k) {
    priority_queue<int> maxH;                // sabse bada top pe hoga
    for (int x : nums) {
        maxH.push(x);
        if ((int)maxH.size() > k) maxH.pop(); // size k — top = kth smallest
    }
    return maxH.top();
}

void task2() {
    cout << "\n=== TASK 2: kth smallest element (k=3) ===\n";
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    cout << "3rd smallest = " << kthSmallest(nums, 3) << "  (sorted: 3,4,7,10,15,20)\n";
}

// ---------- TASK 3: connect ropes minimum cost ----------
int connectRopesCost(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> minH(ropes.begin(), ropes.end());
    int cost = 0;
    while (minH.size() > 1) {
        int a = minH.top(); minH.pop();      // do sabse chhoti rope lo
        int b = minH.top(); minH.pop();
        cost += a + b;                       // join cost = sum
        minH.push(a + b);                    // nayi rope wapas daalo
    }
    return cost;
}

void task3() {
    cout << "\n=== TASK 3: Connect ropes minimum cost ===\n";
    vector<int> ropes = {4, 3, 2, 6};
    cout << "Minimum cost = " << connectRopesCost(ropes) << endl; // expect 29
}

// ---------- TASK 4: sort by frequency ----------
void sortByFrequency(vector<int> nums) {
    map<int, int> freq;
    for (int x : nums) freq[x]++;

    // pair(freq, value) — default pair compare pehle first se karta hai
    priority_queue<pair<int, int>> h;
    for (auto& p : freq) h.push(make_pair(p.second, p.first));

    cout << "Sorted by frequency: ";
    while (!h.empty()) {
        int val = h.top().second;
        int f   = h.top().first;
        h.pop();
        while (f--) cout << val << " ";
    }
    cout << endl;
}

void task4() {
    cout << "\n=== TASK 4: Sort by frequency ===\n";
    vector<int> nums = {4, 1, 1, 1, 2, 2, 3};
    sortByFrequency(nums); // expect 1 1 1 2 2 4 3
}

// ---------- TASK 5: merge k sorted arrays ----------
vector<int> mergeKSorted(vector<vector<int>>& arrays) {
    // (value, arrayIdx, indexInsideArray) — min-heap
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> minH;

    for (int i = 0; i < (int)arrays.size(); ++i)
        if (!arrays[i].empty())
            minH.push(make_tuple(arrays[i][0], i, 0));

    vector<int> ans;
    while (!minH.empty()) {
        int v, r, c;
        tie(v, r, c) = minH.top(); minH.pop();
        ans.push_back(v);
        if (c + 1 < (int)arrays[r].size())          // usi array ka agla element
            minH.push(make_tuple(arrays[r][c + 1], r, c + 1));
    }
    return ans;
}

void task5() {
    cout << "\n=== TASK 5: Merge k sorted arrays ===\n";
    vector<vector<int>> arrays = {{1, 4, 7}, {2, 5}, {3, 6, 8}};
    vector<int> merged = mergeKSorted(arrays);
    for (int v : merged) cout << v << " ";
    cout << endl; // expect 1 2 3 4 5 6 7 8
}

// ---------- TASK 6: median of a stream (two heaps) ----------
class MedianFinder {
private:
    priority_queue<int> lo;                                                // smaller half (max-heap)
    priority_queue<int, vector<int>, greater<int>> hi;                     // larger half (min-heap)

public:
    void addNum(int x) {
        if (lo.empty() || x <= lo.top()) lo.push(x);   // smaller half me daala
        else hi.push(x);                               // ya larger half me

        // balance: lo sirf 1 zyada ho sakta hai; kabhi 2 nahi
        if (lo.size() > hi.size() + 1) { hi.push(lo.top()); lo.pop(); }
        else if (hi.size() > lo.size()) { lo.push(hi.top()); hi.pop(); }
    }

    double median() {
        if (lo.size() > hi.size()) return lo.top();     // odd elements
        return (lo.top() + hi.top()) / 2.0;             // even elements
    }
};

void task6() {
    cout << "\n=== TASK 6: Median of a stream (two heaps) ===\n";
    MedianFinder mf;
    vector<int> stream = {5, 15, 1, 3};
    for (int x : stream) {
        mf.addNum(x);
        cout << "  after inserting " << x << " -> median = " << mf.median() << endl;
    }
    // expect 5, 10, 5, 4
}

int main() {
    cout << "========== STD::PRIORITY_QUEUE TASK SET ==========\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    cout << "\n========== ALL TASKS COMPLETE ==========\n";
    return 0;
}