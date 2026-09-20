/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_Classic_Recursion_Problems task.cpp
│
│ REAL-WORLD SCENARIO:
│ Classic recursion practice me factorial, Fibonacci, digits, power, and array reverse solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Factorial using loop.
│ 2. Factorial using recursion with fact(4) stack diagram.
│ 3. Fibonacci using loop.
│ 4. Fibonacci using naive recursion and tree note.
│ 5. Fibonacci using memoization.
│ 6. Sum of digits recursive.
│ 7. Power a^n simple recursive.
│ 8. Reverse array using recursive two pointers.
│
│ HINTS:
│ - fact base: n<=1.
│ - fib base: n<=1.
│ - sumDigits: n%10 and n/10.
│ - reverse array: left>=right stop.
│
│ STARTER CODE:
│ int f(int n){ if(n==0)return 0; return f(n-1); }
│
│ SOLUTION: Neeche combined demo diya hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ fact(4): 4->3->2->1 then 1,2,6,24.
│ fib(5) tree repeats fib(3) and fib(2).
│ arr [1,2,3] reverse calls rev(0,2)->rev(1,1).
│
│ DRY RUN:
│ sumDigits(123)=3+2+1=6
│ power(2,3)=2*2*2=8
│ reverse [1,2,3,4] -> [4,3,2,1]
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Factorial loop/recursion n steps -> O(n).
│ - Naive fib branching tree -> O(2^n).
│ - Memo fib n states -> O(n).
│ - Digit recursion d calls -> O(d).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Loop variants O(1) extra.
│ - Recursive depth n or d uses O(n)/O(d) stack.
│ - Memo stores n+1 values -> O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long fact(int n){ return n<=1 ? 1 : n*fact(n-1); }
int sumDigits(int n){ return n==0 ? 0 : n%10 + sumDigits(n/10); }
void rev(vector<int>& a,int l,int r){ if(l>=r)return; swap(a[l],a[r]); rev(a,l+1,r-1); }

int main() {
    cout << "fact(4)=" << fact(4) << "\n";
    cout << "sumDigits(123)=" << sumDigits(123) << "\n";
    vector<int> a = {1,2,3,4};
    rev(a,0,(int)a.size()-1);
    cout << "reversed: "; for(int x:a) cout << x << " "; cout << "\n";
    return 0;
}

/*
OUTPUT:
fact(4)=24
sumDigits(123)=6
reversed: 4 3 2 1
*/

