/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_base_case_importance.cpp
│
│ REAL-WORLD SCENARIO:
│ Train ko station par rukne ka rule na mile to woh aage hi badhti rahegi. Recursion me base case stop station hai; bina base case stack overflow ho sakta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case recursion ko stop karta hai.
│ 2. Recursive case problem ko smaller banata hai.
│ 3. Agar n reduce nahi hua ya base case missing hai, infinite calls hoti hain.
│ 4. Infinite calls call stack bhar deti hain.
│ 5. Result: stack overflow / program crash.
│ 6. Crash demo code comment me rakho, run mat karo.
│
│ ASCII VISUAL / CALL STACK STATE:
│ Safe recursion:
│ countdown(3) -> countdown(2) -> countdown(1) -> countdown(0) STOP
│
│ No base case visual:
│ bad() -> bad() -> bad() -> bad() -> ... 💥 stack overflow
│
│ Stack keeps growing:
│ TOP [bad frame]
│     [bad frame]
│     [bad frame]
│     ... no POP because no return
│
│ DRY RUN:
│ countdown(3): print 3, call 2
│ countdown(2): print 2, call 1
│ countdown(1): print 1, call 0
│ countdown(0): base, print stop, return safely.
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Safe countdown calls n+1 times.
│ - Each call constant work.
│ -> Time Complexity = O(n).
│ - Bad recursion has no finite n; it does not terminate.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Safe countdown deepest stack n+1 frames -> O(n).
│ - Bad recursion keeps pushing until memory exhausted.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void countdownSafe(int n) {
    if (n == 0) { // base case zaruri hai
        cout << "STOP at base case\n";
        return;
    }
    cout << n << " ";
    countdownSafe(n - 1);
}

/*
DANGER DEMO - RUN MAT KARNA:
void noBaseCase() {
    noBaseCase(); // infinite recursion -> stack overflow
}
*/

int main() {
    countdownSafe(3);
    return 0;
}

/*
OUTPUT:
3 2 1 STOP at base case
*/

