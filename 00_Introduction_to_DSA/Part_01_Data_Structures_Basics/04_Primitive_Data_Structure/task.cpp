/*
═══════════════════════════════════════════════
 TASK SET — PRIMITIVE DATA STRUCTURE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A billing app must decide how to store money,
 temperatures and flags. Wrong choice = rounding errors in bills,
 overflow in counters, or memory wasted. These tasks sharpen your
 instinct for picking and handling primitive types safely.

🧠 HOW TO SOLVE: Know each type's size, range and precision. Use
 sizeof() to inspect memory, long/long double when numbers can grow,
 double for decimals, and always test edge cases (overflow, precision,
 char arithmetic).

 Tasks 1-6 (difficulty increasing EASY → HARD):

 TASK 1: Report the size of every primitive type.
   Print sizeof for short, int, long, long long, float, double, char,
   bool, with a label like "short = 2 bytes".
   💡 HINT: cout << sizeof(short) << " bytes" — sizeof compile-time size deta hai.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           cout << "short     = " << sizeof(short) << " bytes\n";
           // TODO: int, long, long long, float, double, char, bool
           //       ke size bhi aise hi print karo
           return 0;
       }

 TASK 2: Int vs double — integer division trap.
   Read two integers a and b, then print a/b in three ways:
   (1) integer division, (2) float cast, (3) double cast. Observe difference.
   💡 HINT: (double)a / b mein pehle cast hota hai, phir divide.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int a, b; cin >> a >> b;
           // TODO: teeno tarike से a/b print karo
           return 0;
       }

 TASK 3: Char type — vowel or consonant?
   Read a single lowercase character and say if it is a vowel
   (a, e, i, o, u) or a consonant. Handle the case when input is a digit.
   💡 HINT: char c; cin >> c; aur (c=='a' || c=='e' ...) se check karo;
            digit hai to '0'..'9' ka comparison karo.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           char c; cin >> c;
           // TODO: vowel / consonant / digit — teen cases handle karo
           return 0;
       }

 TASK 4: Overflow detection — choose long long.
   Two large numbers (up to 10^9) are multiplied. int can't hold the
   result (~10^18), but long long can. Print the product correctly using
   long long, and also show what int would have returned (cast the same
   product to int).
   💡 HINT: long long se multiply karo; int me cast karne par garbage/
            wrap hota hai jo bilkul galat output deta hai.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           long long a, b; cin >> a >> b;
           long long prod = a * b;        // long long me safe
           cout << "correct product = " << prod << "\n";
           int wrong = (int)prod;         // truncate → overflow misrepresent
           // TODO: wrong value print karke note karo ki int kitna chhota hai
           return 0;
       }

 TASK 5: Bool logic — leap year check.
   Read a year. Print "LEAP" if it is divisible by 400, or divisible by
   4 but not by 100; otherwise print "NOT LEAP". Use a bool variable to
   store the result.
   💡 HINT: bool leap = (y%400==0) || (y%4==0 && y%100!=0); phir if/else.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int y; cin >> y;
           // TODO: leap bool banao and print karo
           return 0;
       }

 TASK 6: Float precision trap — sum 0.1 ten times.
   Add 0.1 to itself 10 times using float, using double, and compare
   with 1.0. Print all three and the difference from 1.0. Show that
   neither float nor double reaches exactly 1.0.
   💡 HINT: loop me sum += 0.1f (float) aur sum += 0.1 (double) do alag
            sums; difference = sum - 1.0; setprecision(20) se print karo.
   ✏️ STARTER CODE:
       #include <iostream>
       #include <iomanip>
       using namespace std;
       int main() {
           float fs = 0.0f;
           double ds = 0.0;
           for (int i = 0; i < 10; i++) {
               // TODO: fs me 0.1f add karo, ds me 0.1 add karo
           }
           cout << setprecision(20);
           // TODO: fs, ds, aur dono ka (value - 1.0) difference print karo
           return 0;
       }

═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}