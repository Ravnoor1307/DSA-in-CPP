
/*
 TASK 6 SOLUTION — bank account as a data structure
*/
#include <iostream>
#include <string>
using namespace std;
struct Account { string holder; double balance; };   // data + state ek sath
int main() {
    Account acc;
    cin >> acc.holder >> acc.balance;
    int t; cin >> t;
    int rejected = 0;
    for (int i = 0; i < t; i++) {
        double amt; cin >> amt;
        if (acc.balance + amt >= 0) {
            acc.balance += amt;      // paisa kafi hai → transaction apply
        } else {
            rejected++;              // balance negative ho jata → reject
        }
    }
    cout << acc.holder << " final balance: " << acc.balance << "\n";
    cout << "rejected transactions: " << rejected << "\n";
    return 0;
}
// Explanation: Account struct data (holder) aur state (balance) ek saath
// rakhta hai — isi ko data structure kehna hai. Har transaction O(1),
// t transactions total → O(t) time, O(1) extra space.