/*
═══════════════════════════════════════════════
 TASK SET — DATA (Data vs Information)
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A sports club stores tens of thousands of raw
 readings every day (player heart rate, distance, speed). The club needs
 meaningful reports — how many players crossed a fitness target, what is
 the average distance — built from those raw numbers.

🧠 HOW TO SOLVE: Keep the raw facts in an array (data), run one loop to
 filter/sum/count them, and print only the derived facts (information).
 Always guard edge cases: empty input, invalid values, divide-by-zero.

 Tasks 1-6 (difficulty increasing EASY → HARD):

 TASK 1: Print raw data as-is.
   Read n numbers from the user, store them, and print them exactly as
   stored. This proves the data is safely collected before processing.
   💡 HINT: ek array me store karo, phir ek simple for-loop se print karo.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n;
           cout << "kitni values daloge? ";
           cin >> n;
           int arr[100];          // fixed-size array
           cout << "values do: ";
           for (int i = 0; i < n; i++) {
               // TODO: arr[i] me input lo
           }
           cout << "stored data: ";
           for (int i = 0; i < n; i++) {
               // TODO: arr[i] ko print karo
           }
           return 0;
       }

 TASK 2: Count even and odd numbers (data → summary info).
   Read n integers and print how many are even and how many are odd.
   💡 HINT: modulo operator (%) use karo; even = number % 2 == 0.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n, x, even = 0, odd = 0;
           cout << "kitne numbers? "; cin >> n;
           for (int i = 0; i < n; i++) {
               cin >> x;
               // TODO: x even hai yaa odd — counter badhao
           }
           cout << "even: " << even << ", odd: " << odd << "\n";
           return 0;
       }

 TASK 3: Find maximum and minimum from raw values.
   Read n numbers and print the largest and smallest value.
   💡 HINT: pehle element ko max/min maan lo, phir baaki se compare karo.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n; cin >> n;
           int arr[100];
           for (int i = 0; i < n; i++) cin >> arr[i];
           int maxV = arr[0], minV = arr[0];   // suru me pehla element maan lo
           for (int i = 1; i < n; i++) {
               // TODO: compare karke maxV aur minV update karo
           }
           cout << "max = " << maxV << ", min = " << minV << "\n";
           return 0;
       }

 TASK 4: Marks → pass/fail report (processed information).
   Read marks of n students. Print pass count (>= 33), fail count, and
   the class average.
   💡 HINT: teen counters/accumulators rakho — pass, fail, sum.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n; cin >> n;
           int pass = 0, fail = 0, sum = 0;
           for (int i = 0; i < n; i++) {
               int mark; cin >> mark;
               // TODO: mark ke hisaab se pass/fail badhao, sum me jodo
           }
           // TODO: average print karo (double cast karke)
           return 0;
       }

 TASK 5: Filter invalid sensor data and report average of valid values.
   n temperatures are given; any negative value is a sensor error and
   must be ignored. Print the average of only the valid values, or
   "NO VALID DATA" if nothing is valid.
   💡 HINT: select-negative-things wala continue pattern; valid count 0
            hone par message print karo, divide by zero mat karo.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n; cin >> n;
           double sum = 0; int valid = 0;
           for (int i = 0; i < n; i++) {
               double t; cin >> t;
               if (t < 0) {
                   // TODO: sensor error skip karo
               }
               // TODO: otherwise sum me add + valid badhao
           }
           // TODO: valid==0 to "NO VALID DATA" warna average print karo
           return 0;
       }

 TASK 6: Celsius → Fahrenheit danger report (raw → informative alert).
   Read n temperatures in Celsius. Convert each to Fahrenheit
   (F = C * 9/5 + 32). Print converted values, and finally report how
   many readings are DANGEROUS (> 104°F, i.e. heat-stroke risk).
   💡 HINT: ek output array me Fahrenheit store karo, ek counter se
            dangerous readings gin lo. Ye raw data ko actionable
            information me badal raha hai.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n; cin >> n;
           double c[100];                 // raw celsius readings
           for (int i = 0; i < n; i++) cin >> c[i];
           int dangerous = 0;
           for (int i = 0; i < n; i++) {
               double f = c[i] * 9.0 / 5.0 + 32.0;   // conversion formula
               cout << c[i] << "C = " << f << "F\n";
               // TODO: f > 104 hone par dangerous counter badhao
           }
           // TODO: dangerous readings ki report print karo
           return 0;
       }

═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}