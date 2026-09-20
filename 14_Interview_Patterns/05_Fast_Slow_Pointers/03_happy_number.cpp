/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_happy_number.cpp
│
│ REAL-WORLD SCENARIO:
│ Number digit-square process ya to 1 par khatam hota hai ya cycle me phas jata hai. Hash set ke bajay fast-slow cycle detection se O(1) space me happy number check hota hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ Happy number example 19:
│ 19 -> 1²+9² = 82
│ 82 -> 8²+2² = 68
│ 68 -> 6²+8² = 100
│ 100 -> 1
│ happy!
│
│ Unhappy numbers eventually cycle not including 1.
│ Fast-slow:
│ slow = next(n)
│ fast = next(next(n))
│ If fast becomes 1 -> happy.
│ If slow==fast and not 1 -> cycle -> unhappy.

│
│ STEP-BY-STEP DRY RUN:
│ n=19:
│ slow=82, fast=68
│ slow=68, fast=1
│ fast reached 1 -> happy.

│
│ COMPLEXITY CALCULATION:
│ For int numbers, digit-square sequence quickly falls into bounded range.
│ General sequence length m until 1/cycle: slow/fast do O(m) next calls.
│ nextNumber processes digits: digits d, cost O(d).
│ Time = O(m*d), for int effectively O(1) bounded.
│ Space = O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int nextNumber(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = nextNumber(slow);
        fast = nextNumber(nextNumber(fast));
        cout << "slow=" << slow << " fast=" << fast << "\n";
    } while (slow != fast && fast != 1);
    return fast == 1;
}

int main() {
    cout << "19 happy? " << (isHappy(19) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
slow=82 fast=68
slow=68 fast=1
19 happy? YES
*/

