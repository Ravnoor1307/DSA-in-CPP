/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_common_mistakes_in_complexity.cpp
│
│ REAL-WORLD SCENARIO:
│ Complexity interview me constants and lower terms ko simplify karna hota hai. Bill total me packaging constant ho sakti hai, but growth item count se decide hoti hai.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ Common mistakes:
│
│ 1. O(2n) likhna -> O(n)
│ 2. O(n + 100) -> O(n)
│ 3. O(n² + n) -> O(n²)
│ 4. Two separate loops n and m -> O(n+m), not always O(n)
│ 5. Nested independent loops n*m -> O(nm)
│ 6. Binary search O(log n) proof skip karna
│ 7. Recursive exponential calls ko O(n) bolna
│ 8. Space complexity me recursion stack ignore karna
│
│ Log proof required:
│ n/2^k = 1 -> n = 2^k -> k = log₂n

│
│ STEP-BY-STEP DRY RUN:
│ Example:
│ for i<n -> n
│ for j<n -> n
│ total = 2n -> O(n)
│
│ nested:
│ for i<n:
│   for j<n:
│ total = n*n -> O(n²)

│
│ COMPLEXITY CALCULATION:
│ Big-O keeps dominant growth term.
│ Constants removed because for large n they do not change growth class.
│ If input sizes differ, keep both variables: O(n+m), O(nm).
│ Space includes arrays, maps, queues, recursion stack.

│ APPROACH COMPARISON TABLE:
│ | Code pattern | Operation count | Big-O | Real-world analogy |
│ | single loop | n | O(n) | one queue pass |
│ | two separate loops | n+n=2n | O(n) | two queue passes |
│ | nested loops | n*n | O(n²) | every pair check |
│ | halve each step | log₂n | O(log n) | binary search |
│ | recursion branch 2 | 2^n | O(2^n) | choice tree |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    cout << "O(2n) simplifies to O(n)\n";
    cout << "O(n^2 + n) simplifies to O(n^2)\n";
    cout << "Different inputs keep variables: O(n + m), O(n*m)\n";
    cout << "Binary search proof: n/2^k = 1 -> k = log2(n)\n";
    return 0;
}

/*
OUTPUT:
O(2n) simplifies to O(n)
O(n^2 + n) simplifies to O(n^2)
Different inputs keep variables: O(n + m), O(n*m)
Binary search proof: n/2^k = 1 -> k = log2(n)
*/

