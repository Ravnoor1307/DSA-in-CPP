/*
═══════════════════════════════════════════════
 TASK SET — REVERSE & ROTATE ARRAY
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A sushi belt rotates plates cyclically and a train
yard reorders wagons; reversing and rotating arrays is exactly how these
circular shifts are coded in interviews.

🧠 HOW TO SOLVE: Always reduce k with k %= n first. Reversing uses the
two-pointer lo/hi swap. Rotation's best trick is the reversal algorithm —
reverse blocks, then reverse the whole array — for O(n) time, O(1) space.

7 tasks EASY → HARD:

TASK 1 — REVERSE WITH EXTRA ARRAY
💡 HINT: copy a[n-1-i] into b[i] for every i.
✏️ STARTER: vector<int> reverseExtra(const vector<int>& a) { // b[i] = a[n-1-i] }

TASK 2 — REVERSE IN-PLACE (TWO POINTER)
💡 HINT: lo=0, hi=n-1; while(lo<hi){ swap(a[lo],a[hi]); lo++; hi--; }
✏️ STARTER: void reverseInPlace(vector<int>& a) { // lo<hi while swap }

TASK 3 — ROTATE LEFT BY 1
💡 HINT: save a[0], shift everything one slot left, put the saved value at the end.
✏️ STARTER: void rotateLeftBy1(vector<int>& a) { // first to end }

TASK 4 — ROTATE LEFT BY k (NAIVE + k%n HANDLING)
💡 HINT: k %= n first, then call rotateLeftBy1 exactly k times.
✏️ STARTER: void rotateLeftNaive(vector<int>& a, int k) { // k %= n; loop }

TASK 5 — ROTATE RIGHT BY k VIA REVERSAL
💡 HINT: reverse whole, reverse first k, reverse the rest.
✏️ STARTER: void rotateRightRev(vector<int>& a, int k) { // 3 reverses }

TASK 6 — PALINDROME CHECK USING REVERSE-COMPARE
💡 HINT: make a reversed copy, then compare element by element.
✏️ STARTER: bool isPalindrome(const vector<int>& a) { // cmp a vs reverse }

TASK 7 — ROTATE LEFT BY k VIA REVERSAL (BEST)
💡 HINT: reverse first k, reverse the rest, reverse the whole.
✏️ STARTER: void rotateLeftRev(vector<int>& a, int k) { // reverse blocks }
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>

using namespace std;

void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

// TASK 1: extra array se reverse — O(n) time, O(n) space
// Idea: n-1-i index ulta padhta hai isliye reverse order milta hai.
vector<int> reverseExtra(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = a[n - 1 - i];          // last se first tak ulta bharo
    return b;
}

// TASK 2: two-pointer in-place reverse — O(n) time, O(1) space
// lo aur hi dono ends par; swap karke andar aa jao.
void reverseInPlace(vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        swap(a[lo], a[hi]);           // ends ka swap
        ++lo; --hi;                   // narrowing: dono ek step andar
    }
}

// TASK 3: rotate left by 1 — pehla element end par daalo
// WHY O(n): har element ek baar left shift hota hai.
void rotateLeftBy1(vector<int>& a) {
    if (a.empty()) return;            // empty ka kuch nahi karna
    int temp = a[0];                  // pehla element bachao
    for (int i = 1; i < (int)a.size(); ++i)
        a[i - 1] = a[i];              // har element left shift
    a[(int)a.size() - 1] = temp;      // saved value end par
}

// TASK 4: naive rotate left by k — O(n*k) time, O(1) space
// k %= n pehle karo taaki k>n aur k==n dono safe rahein.
void rotateLeftNaive(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;                           // k > n, k == n handle
    for (int step = 0; step < k; ++step)
        rotateLeftBy1(a);             // har bar one full shift pass
}

// helper: [l..r] inclusive range ka reverse
void reverseRange(vector<int>& a, int l, int r) {
    while (l < r) {
        swap(a[l], a[r]);
        ++l; --r;
    }
}

// TASK 5: rotate RIGHT by k via reversal — O(n) time, O(1) space
// right k == left (n-k), isliye reverse order: whole, first k, rest.
void rotateRightRev(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;
    reverseRange(a, 0, n - 1);   // whole reverse
    reverseRange(a, 0, k - 1);   // pehle k reverse
    reverseRange(a, k, n - 1);   // baaki reverse
}

// TASK 6: palindrome check — reverse copy banaake compare
// WHY O(n): ek reverse pass + ek compare pass = 2n steps.
bool isPalindrome(const vector<int>& a) {
    vector<int> rev = reverseExtra(a);    // TASK 1 ka funstion reuse
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != rev[i]) return false; // mismatch => palindrome nahi
    return true;
}

// TASK 7: rotate LEFT by k via reversal (best) — O(n) time, O(1) space
// 3 reverses total ~n swaps, koi extra memory nahi.
void rotateLeftRev(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;
    reverseRange(a, 0, k - 1);   // pehle k elements reverse
    reverseRange(a, k, n - 1);   // baaki reverse
    reverseRange(a, 0, n - 1);   // whole reverse
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    cout << "T1 extra reverse    : "; printVec(reverseExtra(a));      // 5 4 3 2 1

    vector<int> t2 = a;
    reverseInPlace(t2);
    cout << "T2 in-place rev     : "; printVec(t2);                   // 5 4 3 2 1

    vector<int> t3 = a;
    rotateLeftBy1(t3);
    cout << "T3 left by 1        : "; printVec(t3);                   // 2 3 4 5 1

    vector<int> t4 = a;
    rotateLeftNaive(t4, 7);
    cout << "T4 naive left k=7   : "; printVec(t4);                   // 3 4 5 1 2 (7%5=2)

    vector<int> t5 = a;
    rotateRightRev(t5, 2);
    cout << "T5 right rev k=2    : "; printVec(t5);                   // 4 5 1 2 3

    cout << "T6 palindrome       : ";
    cout << isPalindrome({1, 2, 3, 2, 1}) << " "                      // 1 (true)
         << isPalindrome({1, 2, 3, 4}) << "\n";                       // 0 (false)

    vector<int> t7 = a;
    rotateLeftRev(t7, 2);
    cout << "T7 left rev k=2     : "; printVec(t7);                   // 3 4 5 1 2

    return 0;
}