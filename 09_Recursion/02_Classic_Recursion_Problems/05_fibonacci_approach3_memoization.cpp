/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_fibonacci_approach3_memoization.cpp
│
│ REAL-WORLD SCENARIO:
│ Shopkeeper repeated customer ka bill diary me likh leta hai. Fibonacci memoization bhi computed answers array me store karta hai, repeated calls crossed-out ho jaati hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. memo array initialize -1 se karo.
│ 2. fib(n) agar memo[n] already filled hai, direct return.
│ 3. Otherwise calculate fib(n-1)+fib(n-2), store memo[n].
│ 4. Same subproblem dobara solve nahi hota.
│ 5. Ye Dynamic Programming ka preview hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ Naive tree repeated:
│ fib(5)
│ ├─ fib(4)
│ │  ├─ fib(3)
│ │  └─ fib(2)
│ └─ fib(3)  X already stored, no full subtree
│
│ Memo table after compute:
│ index: 0 1 2 3 4 5
│ fib:   0 1 1 2 3 5
│
│ DRY RUN:
│ fib(5): compute fib(4), fib(3)
│ fib(4): compute fib(3), fib(2)
│ fib(3): compute fib(2), fib(1)
│ fib(2): compute fib(1), fib(0), store 1
│ store fib(3)=2, fib(4)=3, fib(5)=5
│ repeated requests return from memo.
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - There are only n+1 distinct states: 0..n.
│ - Each state computed once.
│ - Each computation does O(1) combine work after child answers.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - memo array stores n+1 values.
│ - recursion stack depth n.
│ -> Space Complexity = O(n).
│ APPROACH COMPARISON TABLE:
│ Loop = monthly register update, O(n) time/O(1) space.
│ Naive recursion = repeated family tree visits, O(2^n) time/O(n) stack.
│ Memoization = diary stores answers, O(n) time/O(n) space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo); // answer yaad rakho
    return memo[n];
}

int main() {
    int n = 6;
    vector<int> memo(n + 1, -1);
    cout << "fib(6) memoization = " << fibMemo(n, memo) << "\n";
    cout << "Memo table: ";
    for (int i = 0; i <= n; i++) cout << fibMemo(i, memo) << " ";
    cout << "\nComparison: loop O(n), naive recursion O(2^n), memoization O(n).\n";
    return 0;
}

/*
OUTPUT:
fib(6) memoization = 8
Memo table: 0 1 1 2 3 5 8
Comparison: loop O(n), naive recursion O(2^n), memoization O(n).
*/

