/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_Recursion_on_Numbers task.cpp
│
│ REAL-WORLD SCENARIO:
│ Number-recursion practice me account numbers, GCD, divisors, tail sum, and Josephus survivor solve karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Count digits recursively.
│ 2. Number palindrome by converting to string and recursive two pointers.
│ 3. gcd(48,18) using Euclidean recursion.
│ 4. Print all divisors of n recursively.
│ 5. Sum 1..n using tail recursion.
│ 6. Josephus problem n=5,k=2 solve karo.
│ 7. Zero-index vs one-index Josephus note comments me likho.
│
│ HINTS:
│ - Digits: n/10.
│ - GCD: gcd(b,a%b).
│ - Tail sum accumulator use karo.
│ - Josephus answer one-index = zero-index + 1.
│
│ STARTER CODE:
│ int f(int n){ if(n<10)return 1; return 1+f(n/10); }
│
│ SOLUTION: Neeche combined demo hai.
│
│ ASCII VISUAL / NUMBER STATE:
│ gcd(48,18):
│ 48%18=12 -> gcd(18,12)
│ 18%12=6 -> gcd(12,6)
│ 12%6=0 -> gcd(6,0)=6
│
│ Josephus n=5,k=2 survivor=3
│
│ DRY RUN:
│ countDigits(12345)=5
│ sumTail(5,0)=15
│ palindrome 12321 -> true
│
│ FLOW OF EXECUTION:
│ input number -> reduce to smaller number/range -> base case -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Digit recursion d calls -> O(d).
│ - GCD O(log min(a,b)) calls.
│ - Divisor print n checks -> O(n).
│ - Josephus n calls -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive stack depth depends on calls.
│ - Digit O(d), divisor/Josephus O(n), GCD O(log min).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcdRec(int a,int b){ return b==0 ? a : gcdRec(b,a%b); }
int countDigits(int n){ return n<10 ? 1 : 1+countDigits(n/10); }
int sumTail(int n,int acc){ return n==0 ? acc : sumTail(n-1,acc+n); }
int josephus(int n,int k){ return n==1 ? 0 : (josephus(n-1,k)+k)%n; }

int main() {
    cout << "digits(12345)=" << countDigits(12345) << "\n";
    cout << "gcd(48,18)=" << gcdRec(48,18) << "\n";
    cout << "sumTail(5)=" << sumTail(5,0) << "\n";
    cout << "Josephus n=5,k=2 survivor=" << josephus(5,2)+1 << "\n";
    return 0;
}

/*
OUTPUT:
digits(12345)=5
gcd(48,18)=6
sumTail(5)=15
Josephus n=5,k=2 survivor=3
*/

