/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_how_call_stack_works.cpp
│
│ REAL-WORLD SCENARIO:
│ Office me files stack hoti hain: newest file top par, complete hone ke baad top file remove hoti hai. Recursive calls bhi call stack me PUSH/POP hoti hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Har function call ka stack frame banta hai.
│ 2. Frame me local variables ki apni copy hoti hai, jaise n ki value.
│ 3. fact(3) calls fact(2), then fact(1).
│ 4. Base case se return start hota hai.
│ 5. Unwinding me values upar multiply hoti hain.
│ 6. Last called frame pehle complete hota hai: stack LIFO.
│
│ ASCII VISUAL / CALL STACK STATE:
│ fact(3) call stack PUSH:
│
│ TOP  [fact(1), n=1]  ← base
│      [fact(2), n=2]
│ BOT  [fact(3), n=3]
│
│ Unwind/POP:
│ fact(1) returns 1
│ fact(2) returns 2 * 1 = 2
│ fact(3) returns 3 * 2 = 6
│
│ DRY RUN:
│ fact(3): push frame n=3, needs 3*fact(2)
│ fact(2): push frame n=2, needs 2*fact(1)
│ fact(1): base returns 1
│ back to fact(2): returns 2
│ back to fact(3): returns 6
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Calls: fact(3), fact(2), fact(1): 3 calls.
│ - For general n, calls = n.
│ - Each call constant multiplication/condition.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Deepest stack has n frames.
│ - Each frame has its own n copy.
│ -> Space Complexity = O(n) call stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int factTrace(int n) {
    cout << "PUSH frame: fact(" << n << ")\n";
    if (n == 1) {
        cout << "Base case fact(1)=1, POP frame\n";
        return 1;
    }
    int smaller = factTrace(n - 1);
    int ans = n * smaller;
    cout << "UNWIND fact(" << n << ") = " << n << " * " << smaller << " = " << ans << "\n";
    return ans;
}

int main() {
    cout << "Final answer = " << factTrace(3) << "\n";
    return 0;
}

/*
OUTPUT:
Final answer = PUSH frame: fact(3)
PUSH frame: fact(2)
PUSH frame: fact(1)
Base case fact(1)=1, POP frame
UNWIND fact(2) = 2 * 1 = 2
UNWIND fact(3) = 3 * 2 = 6
6
*/

