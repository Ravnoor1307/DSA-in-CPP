/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_recursion_vs_iteration.cpp
│
│ REAL-WORLD SCENARIO:
│ 1 se n tak paise count karne ke do tareeke hain: cashier loop se one by one add kare, ya assistant smaller total manga kar current number add kare. Dono sum dete hain, space different hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Iteration loop repeated work same function frame me karta hai.
│ 2. Recursion har smaller problem ke liye new stack frame banata hai.
│ 3. Sum 1..n loop: ans += i.
│ 4. Sum 1..n recursive: sum(n)=n+sum(n-1).
│ 5. Time dono O(n), but recursion stack O(n) use karta hai.
│ 6. Recursion tree/backtracking/natural subproblem me helpful; simple loops for simple repetition.
│
│ ASCII VISUAL / CALL STACK STATE:
│ Loop sum 5:
│ ans=0 -> +1 -> +2 -> +3 -> +4 -> +5 = 15
│ Stack depth = 1
│
│ Recursive sum 5:
│ sum(5)->sum(4)->sum(3)->sum(2)->sum(1)->sum(0)
│ unwind: 1,3,6,10,15
│ Stack depth = 6
│
│ MASTER TABLE:
│ Loop      = simple repetition, O(1) extra space
│ Recursion = tree/nested/self-similar problems, O(n) stack for depth n
│
│ DRY RUN:
│ loopSum(5): loop runs i=1..5 total 5 iterations.
│ recursiveSum(5): calls 5,4,3,2,1,0 total 6 calls.
│ Both return 15.
│
│ FLOW OF EXECUTION:
│ main -> recursive function call -> base case -> unwind/return -> output
│
│ COMPLEXITY CALCULATION:
│ - Loop sum runs n iterations -> O(n).
│ - Recursive sum makes n+1 calls -> O(n).
│ - No log here because problem reduces by 1 each time, not half.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Loop uses ans and i -> O(1).
│ - Recursive sum has n+1 stack frames -> O(n).
│ APPROACH COMPARISON TABLE:
│ Loop = cashier adds in same notebook, O(n) time and O(1) space.
│ Recursion = assistant chain asks smaller totals, O(n) time and O(n) stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int loopSum(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += i;
    return ans;
}

int recursiveSum(int n) {
    if (n == 0) return 0;
    return n + recursiveSum(n - 1);
}

int main() {
    int n = 5;
    cout << "Loop sum = " << loopSum(n) << "\n";
    cout << "Recursive sum = " << recursiveSum(n) << "\n";
    cout << "Loop: O(n) time/O(1) space, Recursion: O(n) time/O(n) stack.\n";
    return 0;
}

/*
OUTPUT:
Loop sum = 15
Recursive sum = 15
Loop: O(n) time/O(1) space, Recursion: O(n) time/O(n) stack.
*/

