/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_what_is_recursion_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Russian nesting dolls me har doll ke andar chhoti doll hoti hai, jab tak sabse chhoti doll na mil jaye. Recursion bhi problem ko chhote same problem me todta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Recursion = function jo khud ko call kare.
│ 2. Har recursive solution ke 2 parts mandatory hain.
│ 3. Base Case: rukna kahan hai.
│ 4. Recursive Case: same problem ka chhota version.
│ 5. Agar base case nahi hoga, calls infinite ho sakti hain.
│
│ ASCII VISUAL / CALL STACK STATE:
│ Russian dolls / recursive calls:
│ openDoll(3)
│    ↓ smaller same problem
│ openDoll(2)
│    ↓ smaller same problem
│ openDoll(1)
│    ↓ base case
│ smallest doll found -> return back
│
│ Function calling itself:
│ f(n) -> f(n-1) -> f(n-2) -> ... -> f(0)
│
│ DRY RUN:
│ openDoll(3): not base, call openDoll(2)
│ openDoll(2): not base, call openDoll(1)
│ openDoll(1): base case, stop
│ returns back to openDoll(2), then openDoll(3), then main
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Function called for levels 3,2,1: total 3 calls.
│ - General n levels => n calls.
│ - Each call does constant work besides recursive call.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - At deepest point, n function frames are active.
│ - Each frame stores its own level/n value.
│ -> Space Complexity = O(n) call stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void openDoll(int level) {
    cout << "Enter doll level " << level << "\n";
    if (level == 1) { // base case: sabse chhoti doll mil gayi
        cout << "Base case: smallest doll found\n";
        return;
    }
    openDoll(level - 1); // recursive case: smaller same problem
    cout << "Return from doll level " << level << "\n";
}

int main() {
    openDoll(3);
    return 0;
}

/*
OUTPUT:
Enter doll level 3
Enter doll level 2
Enter doll level 1
Base case: smallest doll found
Return from doll level 2
Return from doll level 3
*/

