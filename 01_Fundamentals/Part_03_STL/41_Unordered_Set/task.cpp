/*
═══════════════════════════════════════════════
 TASK SET — std::unordered_set
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A gaming leaderboard must instantly say "has
    this user submitted a score today?" and a chat app must strip
    duplicate messages in milliseconds. Both only need FAST membership
    checks — order never matters — which is exactly what unordered_set's
    O(1) average hashing gives. Tasks below go from warm-up to
    interview-style.

 🧠 HOW TO SOLVE: Throw every element into the unordered_set —
    duplicates vanish in O(1) each. For two-sum style problems, check the
    complement with count() per element (O(1) each). For "first repeating",
    put only elements you have SEEN already in the set. Longest consecutive
    sequence: count(x+1)/count(x-1) checks only make sense after clearing
    duplicates. Read every statement carefully; a HINT is given, but try it
    yourself first.

 MODES/TOPICS COVERED:
  1. Print distinct values (order arbitrary)
  2. Pair with a given sum (two-sum)
  3. First repeating element
  4. Union of two arrays
  5. Longest consecutive sequence
  6. Intersection size of two arrays
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// ==================== TASK 1 (EASY) ====================
// problem: ek array me duplicates hain. UNIQUE values print karo.
void printDistinct(const vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end()); // range constructor — duplicates hat gaye
    for (int x : s) cout << x << " ";             // order ARBITRARY hai (hash order)
    cout << endl;
}

// ==================== TASK 2 (EASY) ====================
// problem: kya array me koi DO elements ka sum target ke barabar hai?
bool hasPairWithSum(const vector<int>& arr, int target) {
    unordered_set<int> seen;                    // ab tak dekhe hua elements
    for (int x : arr) {
        int need = target - x;                  // kitna complement chahiye
        if (seen.count(need)) return true;      // complement pehle mila? pair mil gaya
        seen.insert(x);                         // current element record karo (O(1))
    }
    return false;
}

// ==================== TASK 3 (MEDIUM) ====================
// problem: array me pehla DUPLICATE element kaun sa hai
// (jo do baar aaya, aur pehli baar aaya ho)? Agar na ho to -1.
int firstRepeating(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return x;            // pehle aa chuka hai → repeat
        seen.insert(x);
    }
    return -1;
}

// ==================== TASK 4 (MEDIUM) ====================
// problem: do arrays ka UNION (saare unique elements) print karo.
void unionOfTwoArrays(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> s;
    for (int x : a) s.insert(x);                // pehli array — O(1) har insert
    for (int x : b) s.insert(x);                // doosri array — duplicate ignore
    for (int x : s) cout << x << " ";
    cout << endl;
}

// ==================== TASK 5 (MEDIUM-HARD) ====================
// problem: unordered array me LONGEST CONSECUTIVE SEQUENCE ki length.
// e.g. {100,4,200,1,3,2} → {1,2,3,4} → 4. Order O(n) ho (sort karke mat karo!).
int longestConsecutive(const vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end()); // duplicates pehle hataya: starts ko define karke
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;               // x ke pichhe wala bhi hai → x start nahi hai
        int len = 1;
        while (s.count(x + len)) ++len;             // chain ko aage badhao
        best = max(best, len);                      // naya record?
    }
    return best;
}

// ==================== TASK 6 (HARD) ====================
// problem: "kya do arrays me COMMON elements hain?" — intersection ka size.
int intersectionSize(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());   // pehli array ke elements
    unordered_set<int> skip;                    // already gine hua elements
    int cnt = 0;
    for (int x : b) {
        if (s.count(x) && !skip.count(x)) {     // dono me hai aur pehle nahi gina?
            ++cnt;
            skip.insert(x);                     // dobara mat gino
        }
    }
    return cnt;
}

int main() {
    cout << "=== TASK 1: print distinct (order arbitrary!) ===" << endl;
    printDistinct({5, 3, 8, 3, 9, 1, 5});

    cout << "\n=== TASK 2: pair with sum ===" << endl;
    cout << "hasPairWithSum({1,4,6,8}, 10) ? "
         << (hasPairWithSum({1,4,6,8}, 10) ? "YES" : "NO") << endl;
    cout << "hasPairWithSum({1,4,6,8}, 99) ? "
         << (hasPairWithSum({1,4,6,8}, 99) ? "YES" : "NO") << endl;

    cout << "\n=== TASK 3: first repeating ===" << endl;
    cout << "firstRepeating({2,5,1,2,3,5}) = " << firstRepeating({2,5,1,2,3,5}) << endl;
    cout << "firstRepeating({1,2,3}) = " << firstRepeating({1,2,3}) << " (-1 = none)" << endl;

    cout << "\n=== TASK 4: union of two arrays ===" << endl;
    unionOfTwoArrays({1, 2, 3, 4, 5}, {3, 4, 5, 6, 7});

    cout << "\n=== TASK 5: longest consecutive sequence ===" << endl;
    cout << "longestConsecutive({100,4,200,1,3,2}) = "
         << longestConsecutive({100,4,200,1,3,2}) << endl;

    cout << "\n=== TASK 6: intersection size ===" << endl;
    cout << "intersectionSize({1,2,2,3},{2,2,3,4}) = "
         << intersectionSize({1,2,2,3},{2,2,3,4}) << " (2 aur 3, sirf ek baar gine)" << endl;

    return 0;
}

/* ------------------ EXPLANATION NOTES ------------------
TASK 1: unordered_set(arr.begin(), arr.end()) — har insert O(1)
        average; n elements → O(n). Order arbitrary (hash), sorted nahi!
        Sorted chahiye? Simpler: dekh regex → task 40 wala set use karo.
TASK 2: Per element count() + insert() = O(1) average → total O(n).
        Edge: agar "need == x" ho, to answer tabhi true jab wo copy
        pehle aa chuki ho (kyunki insert baad me hota hai).
TASK 3: O(n). count() O(1) average; pehla element jo seen me mile = answer.
        Agar koi repeat na ho → -1 (edge case handled).
TASK 4: Union = dono arrays isamein set — total O(a + b). Duplicates
        automatic remove. Kram ki koi guarantee nahi.
TASK 5: Classic O(n) trick — sirf un elements se chain shuru karo jinke
        x-1 NAHI hai. Warna mitne wale steps O(n) ke square ho jate.
        Har chain apne start se hi count hoti hai → total O(n).
TASK 6: O(a + b) do set ke saath. `skip` set yeh pakka karta hai ki
        duplicate element 2 baar count na ho (1,2,2,3 ∩ 2,2,3,4 = {2,3}).
*/