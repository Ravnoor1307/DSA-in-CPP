/*
REAL-WORLD SCENARIO:
Interviewer snippets dega aur O(?) puchhega. Operations count karke answer do.

TASKS easy -> hard:
1. Single loop complexity calculate karo.
2. Nested loop n*n calculate karo.
3. Triangular loop n(n+1)/2 derive karo.
4. Binary search log proof likho.
5. n log n loop identify karo.
6. Constants/lower terms simplify karo.
7. Space complexity arrays/maps/recursion stack count karo.

HINTS:
- O(2n) = O(n).
- n/2^k=1 -> k=log₂n.
- nested independent loops multiply.

STARTER CODE:
for (int i=0; i<n; i++) { }

SOLUTIONS below.
*/
#include <iostream>
using namespace std;

int main() {
    int n = 5, ops = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) ops++;
    }
    cout << "triangular ops=" << ops << " -> O(n^2)\n";
    return 0;
}

/*
OUTPUT:
triangular ops=15 -> O(n^2)
*/
