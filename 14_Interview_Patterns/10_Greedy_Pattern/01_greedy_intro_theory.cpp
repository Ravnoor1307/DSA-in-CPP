/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_greedy_intro_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Change dene me har step par sabse bada possible coin choose karna greedy lagta hai. Greedy local best choose karta hai, but proof zaruri hai because har problem me work nahi karta.
│
│ ASCII VISUAL / DECISION STATE:
│ Greedy idea:
│ At each step pick best local option.
│ Hope/prove it leads to global optimum.
│
│ Coin example Indian-like canonical coins:
│ amount 93
│ choose 50, remaining43
│ choose 20, remaining23
│ choose 20, remaining3
│ choose 2, remaining1
│ choose 1, remaining0
│
│ Warning:
│ Coins [1,3,4], amount6.
│ greedy picks 4+1+1 = 3 coins
│ optimal 3+3 = 2 coins
│ So proof required.

│
│ STEP-BY-STEP DRY RUN:
│ Greedy checklist:
│ 1. Sort by right key.
│ 2. Local choice define karo.
│ 3. Exchange argument/proof intuition do.
│ 4. Counterexample try karo.

│
│ COMPLEXITY CALCULATION:
│ Greedy complexity depends on sorting and scan.
│ Many greedy problems:
│ sort n items O(n log n)
│ one scan O(n)
│ total O(n log n)
│ Space often O(1) extra.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    cout << "Greedy = local best choice with proof.\n";
    cout << "Works for activity selection by earliest end time.\n";
    cout << "Does not work blindly for every coin system.\n";
    return 0;
}

/*
OUTPUT:
Greedy = local best choice with proof.
Works for activity selection by earliest end time.
Does not work blindly for every coin system.
*/

