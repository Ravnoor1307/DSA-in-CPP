/*
═══════════════════════════════════════════════
 TASK SET — DATA STRUCTURE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A coaching institute keeps student records.
 Teachers frequently search a name, add new admissions, delete failed
 students and update marks. Doing all this on messy loose data is slow
 and error-prone — they need a proper data structure (structured storage
 + operations) to keep records organized and fast to use.

🧠 HOW TO SOLVE: Choose the right structure (here: array of structs),
 write one helper operation at a time (print, search, update, delete),
 and always test edge cases — empty array, duplicate names, missing key.

 Tasks 1-6 (difficulty increasing EASY → HARD):

 TASK 1: Store and print student records using parallel arrays.
   Read names of n students and their marks into two separate arrays.
   Print them as "name -> marks".
   💡 HINT: do arrays — string name[100] aur int marks[100]; dono me
            index i ka matlab same student hai.
   ✏️ STARTER CODE:
       #include <iostream>
       #include <string>
       using namespace std;
       int main() {
           int n; cin >> n;
           string name[100];
           int marks[100];
           for (int i = 0; i < n; i++) {
               // TODO: name[i] aur marks[i] dono input karo
           }
           for (int i = 0; i < n; i++) {
               // TODO: "name[i] -> marks[i]" print karo
           }
           return 0;
       }

 TASK 2: Define a struct and store records as an array of structs.
   Make struct Student { string name; int marks; }. Read n students and
   print them. (Same output as Task 1, but now with a real data structure.)
   💡 HINT: struct banane ke baad Student students[100]; aur dot (.)
            operator se fields access karo.
   ✏️ STARTER CODE:
       #include <iostream>
       #include <string>
       using namespace std;
       struct Student { string name; int marks; };   // data structure define
       int main() {
           int n; cin >> n;
           Student students[100];
           for (int i = 0; i < n; i++) {
               // TODO: students[i].name aur students[i].marks input karo
           }
           for (int i = 0; i < n; i++) {
               // TODO: print karo
           }
           return 0;
       }

 TASK 3: Search for a student by name (linear search).
   Given n records and a name to find, print the marks of that student,
   or "NOT FOUND" if absent. Return the FIRST match if duplicates exist.
   💡 HINT: for-loop me name.compare karo; milte hi break karke marks
            print karo. Na milne par flag se NOT FOUND bolo.
   ✏️ STARTER CODE:
       #include <iostream>
       #include <string>
       using namespace std;
       struct Student { string name; int marks; };
       int main() {
           int n; cin >> n;
           Student s[100];
           for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;
           string key; cin >> key;
           int found = -1;
           // TODO: linear search karke found set karo
           if (found == -1) cout << "NOT FOUND\n";
           // TODO: warna marks print karo
           return 0;
       }

 TASK 4: Update marks (add bonus) and find the highest scorer.
   Add +5 bonus marks to every student, then print the name of the
   student who now has the highest marks.
   💡 HINT: pehle loop me s[i].marks += 5; dusra loop max find kare.
   ✏️ STARTER CODE:
       int main() {
           int n; cin >> n;
           Student s[100];
           for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;
           // TODO: sabko +5 bonus do (update operation)
           // TODO: max marks wala student find karke naam print karo
           return 0;
       }

 TASK 5: Delete a record (shift elements left).
   Given n records and a position p (0-based), remove record at position
   p by shifting all later records one step left, and reduce the count.
   Print the final list.
   💡 HINT: for i = p to n-2: s[i] = s[i+1]; phir n--; isse wo element
            "delete" ho jata hai (array me physical deletion nahi hoti).
   ✏️ STARTER CODE:
       int main() {
           int n, p; cin >> n;
           Student s[100];
           for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].marks;
           cin >> p;                     // delete karne ki position
           // TODO: p se aage ke elements ko left shift karo
           // TODO: n ki value ek kam karo aur final list print karo
           return 0;
       }

 TASK 6: Bank account as a data structure — deposit, withdraw, summary.
   Make struct Account { string holder; double balance; }. Start with a
   balance, then process a list of transactions as +amount (deposit) or
   -amount (withdraw). Print the final balance and how many transactions
   were rejected due to insufficient funds.
   💡 HINT: balance ke hisaab se check karo — if (bal + amount >= 0) to
            apply karo warna rejected++ (balance negative na hone do).
   ✏️ STARTER CODE:
       struct Account { string holder; double balance; };
       int main() {
           Account acc;
           cin >> acc.holder >> acc.balance;
           int t; cin >> t;              // kitne transactions
           int rejected = 0;
           for (int i = 0; i < t; i++) {
               double amt; cin >> amt;   // +deposit / -withdraw
               // TODO: balance kam na ho to apply karo, warna rejected++
           }
           cout << acc.holder << " final balance: " << acc.balance << "\n";
           // TODO: rejected count bhi print karo
           return 0;
       }

═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}