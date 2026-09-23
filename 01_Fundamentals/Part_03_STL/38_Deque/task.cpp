/*
═══════════════════════════════════════════════
 TASK SET — STD::DEQUE
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A stock trader scans share prices through a
    moving window and wants the MAX price inside that window as it slides
    — that's sliding window maximum, powered by a deque that stores
    CANDIDATE indices in decreasing order. A spell-checker also uses a
    deque to verify a word reads the same from both ends (palindrome) by
    popping front and back together.

 🧠 HOW TO SOLVE: std::deque is O(1) at BOTH ends plus O(1) random access.
    For sliding-window max, keep a monotonically DECREASING deque of
    indices: before adding index i, pop back while its value is smaller;
    then remove the front index that has left the window; the front is
    your window max. For palindrome, compare front vs back and pop both.

 MODES/TOPICS COVERED:
  1. Sliding window maximum (fixed k)
  2. Palindrome check using a deque
  3. First k elements then last k
  4. Rotate deque left by k
  5. Sum of min and max in every window
  6. Build a decreasing deque step by step
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

// ---------- TASK 1: sliding window maximum ----------
vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    deque<int> dq; // ADDERESS indices; values decreasing order me
    vector<int> ans;

    for (int i = 0; i < (int)nums.size(); ++i) {
        // chhote / equal candidates ko peeche se hatao — decreasing property
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);

        // jo index window start se purana ho gaya, nikaal do
        if (dq.front() <= i - k) dq.pop_front();

        // window bharne ke baad hi answer likho
        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

void task1() {
    cout << "\n=== TASK 1: Sliding window maximum (k=3) ===\n";
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = slidingWindowMax(nums, 3);
    for (int v : ans) cout << v << " ";
    cout << endl; // expect 3 3 5 5 6 7
}

// ---------- TASK 2: palindrome using deque ----------
bool isPalindromeDeque(const string& w) {
    deque<char> dq(w.begin(), w.end());
    while (dq.size() > 1) {
        if (dq.front() != dq.back()) return false; // dono siron pe diff
        dq.pop_front();                            // wajah dono taraf se nikaal do
        dq.pop_back();
    }
    return true;
}

void task2() {
    cout << "\n=== TASK 2: Palindrome using deque ===\n";
    cout << "\"racecar\" -> " << (isPalindromeDeque("racecar") ? "yes" : "no") << endl;
    cout << "\"hello\"   -> " << (isPalindromeDeque("hello") ? "yes" : "no") << endl;
    cout << "\"madam\"   -> " << (isPalindromeDeque("madam") ? "yes" : "no") << endl;
}

// ---------- TASK 3: first k then last k ----------
void task3() {
    cout << "\n=== TASK 3: First 3 then last 3 ===\n";
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    for (int i = 0; i < k; ++i) cout << dq[i] << " ";            // pehle k
    for (int i = (int)dq.size() - k; i < (int)dq.size(); ++i) cout << dq[i] << " ";
    cout << endl; // expect 1 2 3 5 6 7
}

// ---------- TASK 4: rotate left by k ----------
void task4() {
    cout << "\n=== TASK 4: Rotate left by 2 ===\n";
    deque<int> dq = {1, 2, 3, 4, 5};
    int k = 2;

    for (int i = 0; i < k; ++i) {   // front nikaal ke back me daalo
        int v = dq.front();
        dq.pop_front();
        dq.push_back(v);
    }

    for (int v : dq) cout << v << " ";
    cout << endl; // expect 3 4 5 1 2
}

// ---------- TASK 5: sum of min and max in every window ----------
pair<int, int> windowMinMaxSum(const vector<int>& nums, int k) {
    deque<int> maxQ; // decreasing — front = max
    deque<int> minQ; // increasing  — front = min
    int totalSum = 0;

    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!maxQ.empty() && nums[maxQ.back()] <= nums[i]) maxQ.pop_back();
        while (!minQ.empty() && nums[minQ.back()] >= nums[i]) minQ.pop_back();
        maxQ.push_back(i);
        minQ.push_back(i);

        if (maxQ.front() <= i - k) maxQ.pop_front();
        if (minQ.front() <= i - k) minQ.pop_front();

        if (i >= k - 1) {
            int sum = nums[maxQ.front()] + nums[minQ.front()]; // max + min
            cout << "  window ending at " << i << ": max=" << nums[maxQ.front()]
                 << " min=" << nums[minQ.front()] << " sum=" << sum << endl;
            totalSum += sum;
        }
    }
    return make_pair((int)maxQ.size(), totalSum);
}

void task5() {
    cout << "\n=== TASK 5: Sum of min + max per window (k=3) ===\n";
    vector<int> nums = {2, 5, -1, 7, -3};
    auto result = windowMinMaxSum(nums, 3);
    cout << "Total of all window sums = " << result.second << endl;
}

// ---------- TASK 6: decreasing deque built step by step ----------
void task6() {
    cout << "\n=== TASK 6: Build decreasing deque step-by-step ===\n";
    deque<int> dq;
    vector<int> nums = {1, 3, -1};

    for (int x : nums) {
        while (!dq.empty() && dq.back() < x) dq.pop_back(); // chhote hatao
        dq.push_back(x);

        cout << "  after pushing " << x << ": deque = ";
        for (int v : dq) cout << v << " ";
        cout << endl;
    }
    cout << "Final front (max so far) = " << dq.front() << endl;
}

int main() {
    cout << "========== STD::DEQUE TASK SET ==========\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    cout << "\n========== ALL TASKS COMPLETE ==========\n";
    return 0;
}