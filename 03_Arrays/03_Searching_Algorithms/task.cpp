/*
═══════════════════════════════════════════════
 TASK SET — SEARCHING ALGORITHMS
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A bookstore keeps its titles on a shelf. For a single unordered shelf you
 must walk the whole rack scanning each spine (linear). Once books are
 sorted alphabetically, you jump to the middle, compare, and discard half
 the rack at a time (binary). Below you will practise both — plus the
 advanced twists: duplicates, floor/ceil, rotated shelves, and precision.

🧠 HOW TO SOLVE:
 Read each task, decide IF the data is sorted. Sorted → binary search with
 the overflow-safe mid = low + (high - low)/2, loop `low <= high`. For
 first/last occurrence keep searching after a match. For BS-on-answer,
 write a monotonic predicate (e.g. mid² ≤ x) and binary search the value.
 Always state the FULL complexity derivation — never a bare O(?).

 6 tasks EASY → HARD. Each has TASK n + 💡 HINT + ✏️ STARTER CODE.
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ---------------------------------------------------------------
// TASK (a) — LINEAR SEARCH (EASY)
// Find the index of target x in an UNSORTED array. Return -1 if absent.
// Complexity: worst case n comparisons → O(n); space O(1).
// 💡 HINT: loop from 0 to n-1, compare arr[i] == x, return i on hit.
// ✏️ STARTER CODE:
//    int linearSearch(vector<int>& a, int x) { ... }
//---------------------------------------------------------------
int linearSearch(vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == x) return i;      // seedha index return karo
    }
    return -1;                        // nahi mila
}
// Derivation (linear): worst case target last element ya absent →
//   every element compared once → n comparisons → O(n).
// Space: sirf loop variable → O(1).


// ---------------------------------------------------------------
// TASK (b) — COUNT OCCURRENCES OF x (EASY→MEDIUM)
// Given a SORTED array, count how many times x appears.
// Hint: use first + last occurrence; count = last - first + 1.
// ✏️ STARTER CODE:
//    int count(vector<int>& a, int x) {
//        int f = firstOccurrence(a, x);   // banane hoga
//        if (f == -1) return 0;
//        return lastOccurrence(a, x) - f + 1;
//    }
//---------------------------------------------------------------
int firstOccurrence(vector<int>& a, int x) {
    int low = 0, high = (int)a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;     // overflow-safe mid
        if (a[mid] == x) {
            ans = mid;        // candidate mila, magar aur left bhi ho sakta hai
            high = mid - 1;   // left-half search continue
        } else if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
int lastOccurrence(vector<int>& a, int x) {
    int low = 0, high = (int)a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            ans = mid;        // candidate mila, magar aur right bhi ho sakta hai
            low = mid + 1;    // right-half search continue
        } else if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
int countOccurrences(vector<int>& a, int x) {
    int first = firstOccurrence(a, x);
    if (first == -1) return 0;                // element hi nahi hai
    return lastOccurrence(a, x) - first + 1;  // window ka size
}
// Derivation: har call binary search → O(log n); do calls → 2·O(log n),
//   constant factor ignore → O(log n). Space O(1) iterative.


// ---------------------------------------------------------------
// TASK (c) — FIRST OCCURRENCE / LEFTMOST (MEDIUM)
// Sorted array, may contain duplicates. Return index of FIRST x.
// 💡 HINT: standard BS, but on arr[mid]==x don't return — save ans and
//   move high = mid - 1 to keep hunting left.
// ✏️ STARTER CODE:
//    int firstOccurrence(vector<int>& a, int x) { ... }
//---------------------------------------------------------------
// Solution upar task (b) mein diya hua hai — yahan dobaara:
//   while(low<=high){ mid; if(a[mid]==x){ans=mid; high=mid-1;}
//                      else if(a[mid]<x) low=mid+1; else high=mid-1; }
// Derivation: window half hoti hai har step → n/2^k = 1 → k = log₂n → O(log n).


// ---------------------------------------------------------------
// TASK (d) — CEIL OF x IN SORTED ARRAY (MEDIUM)
// ceil(x) = smallest element ≥ x. Return its VALUE (or -1 if none).
// Example: a=[1,2,8,10,11], ceil(5)=8, ceil(12)=-1.
// 💡 HINT: search for element ≥ x; every time a[mid] >= x is a candidate,
//   save it and move left (high=mid-1) to find a SMALLER candidate.
// ✏️ STARTER CODE:
//    int ceilSorted(vector<int>& a, int x) {
//        int low=0, high=n-1, ans=-1;
//        while(low<=high){ mid; if(a[mid]>=x){ ans=a[mid]; high=mid-1;}
//                          else low=mid+1; } return ans; }
//---------------------------------------------------------------
int ceilSorted(vector<int>& a, int x) {
    int low = 0, high = (int)a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x) {
            ans = a[mid];    // ye cetify-able candidate hai
            high = mid - 1;  // aur chhota candidate left mein mil sakta hai
        } else {
            low = mid + 1;   // a[mid] < x → chhota element reject
        }
    }
    return ans;
}
// Derivation: har iteration half → n/2^k = 1 → k = log₂n → O(log n), O(1) space.


// ---------------------------------------------------------------
// TASK (e) — FLOOR OF x IN SORTED ARRAY (MEDIUM)
// floor(x) = largest element ≤ x. Return its VALUE (or -1 if none).
// Example: a=[1,2,8,10,11], floor(5)=2, floor(0)=-1.
// 💡 HINT: mirror of ceil — when a[mid] <= x it is a candidate; save it
//   and go RIGHT (low=mid+1) hunting for a larger-but-still-≤x value.
// ✏️ STARTER CODE:
//    int floorSorted(vector<int>& a, int x) {
//        int low=0, high=n-1, ans=-1;
//        while(low<=high){ mid; if(a[mid]<=x){ ans=a[mid]; low=mid+1;}
//                          else high=mid-1; } return ans; }
//---------------------------------------------------------------
int floorSorted(vector<int>& a, int x) {
    int low = 0, high = (int)a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {
            ans = a[mid];    // candidate, par bada wala right mein ho sakta hai
            low = mid + 1;
        } else {
            high = mid - 1;  // a[mid] > x → bahut bada reject
        }
    }
    return ans;
}
// Derivation: same as ceil → n/2^k = 1 → k = log₂n → O(log n), O(1) space.


// ---------------------------------------------------------------
// TASK (f) — SEARCH IN ROTATED SORTED ARRAY (HARD)
// a was sorted ascending, then rotated at some pivot. Search target.
// Example: [4,5,6,7,0,1,2], search 0 → index 4.
// 💡 HINT: one of the two halves is ALWAYS sorted. mid leke check karo:
//   if a[low]<=a[mid] → left half sorted → decide by comparing target
//   with a[low]/a[mid]; else right half sorted. classic two-case BS.
// ✏️ STARTER CODE:
//    int searchRotated(vector<int>& a, int x) {
//        int low=0, high=n-1;
//        while(low<=high) {
//            int mid=low+(high-low)/2;
//            if(a[mid]==x) return mid;
//            if(a[low]<=a[mid]) {            // left half sorted hai
//                if(x>=a[low] && x<a[mid]) high=mid-1;
//                else low=mid+1;
//            } else {                        // right half sorted hai
//                if(x>a[mid] && x<=a[high]) low=mid+1;
//                else high=mid-1;
//            }
//        }
//        return -1;
//    }
//---------------------------------------------------------------
int searchRotated(vector<int>& a, int x) {
    int low = 0, high = (int)a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) return mid;          // direct hit
        if (a[low] <= a[mid]) {               // LEFT half guaranteed sorted
            if (x >= a[low] && x < a[mid]) high = mid - 1;  // x iske andar
            else low = mid + 1;               // else right side chalo
        } else {                              // RIGHT half sorted
            if (x > a[mid] && x <= a[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}
// Derivation: jahan bhi pivot ho, har step mein half discard
// → n/2^k = 1 → k = log₂n → O(log n). Space O(1).


// ---------------------------------------------------------------
// TASK (g) — sqrt WITH PRECISION (HARD, BS ON ANSWER)
// Return sqrt(x) with given precision (e.g. 3 decimal digits).
// 💡 HINT: binary search floating numbers — low=0, high=x (or 1 if x<1).
//   while(high - low > 1e-6){ mid; if(mid*mid <= x) low=mid; else high=mid; }
//   print with fixed setprecision. Monotonic predicate: mid² ≤ x ? ✓
// ✏️ STARTER CODE:
//    double sqrtPrecision(double x) {
//        double low = 0, high = (x < 1) ? 1.0 : x;
//        while (high - low > 1e-6) {
//            double mid = low + (high - low) / 2.0;
//            if (mid * mid <= x) low = mid; else high = mid;
//        }
//        return low;
//    }
//---------------------------------------------------------------
double sqrtPrecision(double x) {
    if (x == 0) return 0;                     // edge case
    double low = 0, high = (x < 1) ? 1.0 : x; // x<1 ke liye high=1 chahiye
    while (high - low > 1e-6) {               // precision target
        double mid = low + (high - low) / 2.0;
        if (mid * mid <= x) low = mid;        // predicate true → upar jao
        else high = mid;                      // false → neeche
    }
    return low;                               // approx sqrt
}
// Derivation: range width x, each step half karte hain; stop when width
//   ≤ 1e-6. Steps = log₂(x / 1e-6), constant precision → O(log(x/ε)).
//   Sukhi array ki jagah ANSWER SPACE par BS — monotonic predicate ka magic.


// ---------------- MAIN : run every solution with a demo ----------------
int main() {
    cout << fixed << setprecision(6);

    vector<int> unsorted = {11, 4, 7, 2, 9};
    cout << "(a) linearSearch(unsorted, 9) = " << linearSearch(unsorted, 9) << "  (expect 4)\n";
    cout << "    linearSearch(unsorted, 99) = " << linearSearch(unsorted, 99) << "  (expect -1)\n";

    vector<int> dup = {1, 2, 2, 2, 3, 4, 4, 5};
    cout << "(b) countOccurrences(dup, 2) = " << countOccurrences(dup, 2) << "  (expect 3)\n";
    cout << "    countOccurrences(dup, 9) = " << countOccurrences(dup, 9) << "  (expect 0)\n";

    cout << "(c) firstOccurrence(dup, 2) = " << firstOccurrence(dup, 2) << "  (expect 1)\n";
    cout << "    lastOccurrence  (dup, 2) = " << lastOccurrence(dup, 2) << "  (expect 3)\n";

    vector<int> fc = {1, 2, 8, 10, 11};
    cout << "(d) ceilSorted(fc, 5)  = "  << ceilSorted(fc, 5)  << "  (expect 8)\n";
    cout << "    ceilSorted(fc, 12) = "  << ceilSorted(fc, 12) << "  (expect -1)\n";
    cout << "(e) floorSorted(fc, 5) = "  << floorSorted(fc, 5) << "  (expect 2)\n";
    cout << "    floorSorted(fc, 0) = "  << floorSorted(fc, 0) << "  (expect -1)\n";

    vector<int> rot = {4, 5, 6, 7, 0, 1, 2};
    cout << "(f) searchRotated(rot, 0) = " << searchRotated(rot, 0) << "  (expect 4)\n";
    cout << "    searchRotated(rot, 5) = " << searchRotated(rot, 5) << "  (expect 1)\n";
    cout << "    searchRotated(rot, 3) = " << searchRotated(rot, 3) << "  (expect -1)\n";

    cout << "(g) sqrtPrecision(2)  = " << sqrtPrecision(2.0)  << "  (expect ~1.414214)\n";
    cout << "    sqrtPrecision(10) = " << sqrtPrecision(10.0) << "  (expect ~3.162278)\n";

    return 0;
}