/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_analyze_this_code_1.cpp
│
│ REAL-WORLD SCENARIO:
│ Interview me interviewer code snippet dikhakar O(?) puchta hai. Ye billing counter jaisa hai: operations count karo, constants drop karo, dominant term lo.
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ SNIPPET DRILLS:
│
│ 1. for i=0..n-1 print -> n operations -> O(n)
│
│ 2. for i=0..n-1
│      for j=0..n-1
│    -> n*n = n² -> O(n²)
│
│ 3. for i=1; i<n; i*=2
│    sequence 1,2,4,8...
│    n/2^k = 1 -> n=2^k -> k=log₂n -> O(log n)
│
│ 4. two separate loops n and n
│    n+n=2n -> O(n)
│
│ 5. nested j=i..n
│    n+(n-1)+...+1=n(n+1)/2 -> O(n²)

│
│ STEP-BY-STEP DRY RUN:
│ Count operations:
│ If n=5 triangular loop counts:
│ i=0 -> 5
│ i=1 -> 4
│ i=2 -> 3
│ i=3 -> 2
│ i=4 -> 1
│ total15 = 5*6/2.

│
│ COMPLEXITY CALCULATION:
│ Complexity analysis uses growth rate.
│ Constants dropped: 2n -> O(n).
│ Lower terms dropped: n²+n -> O(n²).
│ Log proof: n/2^k = 1 -> k=log₂n.

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
    int n = 5;
    int countLinear = 0, countSquare = 0, countLog = 0, countTri = 0;
    for (int i = 0; i < n; i++) countLinear++;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) countSquare++;
    for (int i = 1; i < n; i *= 2) countLog++;
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) countTri++;
    cout << "linear ops=" << countLinear << " -> O(n)\n";
    cout << "square ops=" << countSquare << " -> O(n^2)\n";
    cout << "log ops=" << countLog << " -> O(log n)\n";
    cout << "triangular ops=" << countTri << " -> O(n^2)\n";
    return 0;
}

/*
OUTPUT:
linear ops=5 -> O(n)
square ops=25 -> O(n^2)
log ops=3 -> O(log n)
triangular ops=15 -> O(n^2)
*/

