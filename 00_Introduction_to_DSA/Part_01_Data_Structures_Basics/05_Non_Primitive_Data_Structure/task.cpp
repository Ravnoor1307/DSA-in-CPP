/*
═══════════════════════════════════════════════
 TASK SET — NON-PRIMITIVE / DERIVED & USER-DEFINED DATA STRUCTURES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    School ka system har student ka POORA record (naam, roll number, 3 subjects ke
    marks) ek saath rakhna chahta hai. Aisi entity ko pakadne ke liye struct/class
    perfect hai, aur poore records rakhne ke liye array-of-structs ka use hota hai.

 🧠 HOW TO SOLVE:
    Pehle struct/class ka blueprint banao, phir objects banao, fields bharo, aur
    baad me normal array ki tarah loop chalao. Nested struct me ek struct andar se
    dusre struct ka field hota hai.

 TASKS (EASY → HARD):

 ── TASK 1 [EASY] ─────────────────────────────────────────────
    struct Student { string name; int rollNo; int marks[3]; } banao.
    Student "Aman" (roll 1, marks 88, 91, 79) ka object banao aur naam, roll
    aur teeno marks print karo.
    💡 HINT: s1.name = "Aman"; phir cout << s1.name << " " << s1.rollNo;
    ✏️ STARTER CODE:
      #include <iostream>
      #include <string>
      using namespace std;
      struct Student { string name; int rollNo; int marks[3]; };
      int main() {
          Student s1;
          // TODO: s1.name, s1.rollNo, s1.marks[0..2] bharo
          // TODO: teeno fields print karo
          return 0;
      }

 ── TASK 2 [EASY-MEDIUM] ──────────────────────────────────────
    3 students ka array of struct lo (sample data khud do), aur sabka
    naam + roll print karo loop se.
    💡 HINT: Student s[3] = {{"Aman",1,{88,91,79}}, ...}; phir for loop s[i].name.
    ✏️ STARTER CODE:
      int main() {
          Student s[3];
          // TODO: 3 students ki fields set karo
          // TODO: loop se sabka naam + roll print karo
          return 0;
      }

 ── TASK 3 [MEDIUM] ───────────────────────────────────────────
    n (yahan 3) students ka data lo. Har student ka 3 subjects ka AVERAGE
    print karo.
    💡 HINT: total = marks[0]+marks[1]+marks[2]; avg = total / 3.0;
    ✏️ STARTER CODE:
      int main() {
          Student s[3];   // TODO: data bharo
          for (int i = 0; i < 3; i++) {
              // TODO: total compute karo
              // TODO: avg print karo
          }
          return 0;
      }

 ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    Topper dhundho — jiska total (teeno subjects ka sum) SABSE ZYADA hai,
    uska naam aur total print karo.
    💡 HINT: bestTotal = -1; agar t > bestTotal to best = i.
    ✏️ STARTER CODE:
      int main() {
          Student s[3];   // TODO: data bharo
          int best = 0, bestTotal = -1;
          // TODO: loop se total nikaalo aur best update karo
          // TODO: s[best].name print karo
          return 0;
      }

 ── TASK 5 [MEDIUM-HARD] ──────────────────────────────────────
    Total >= 150 ko PASS maano. 3 students me se kitne PASS hue aur kitne
    FAIL, count karo.
    💡 HINT: if (total >= 150) passCount++; else failCount++;
    ✏️ STARTER CODE:
      int main() {
          Student s[3];   // TODO: data bharo
          int pass = 0, fail = 0;
          // TODO: har student ka total dekh kar pass/fail barhao
          return 0;
      }

 ── TASK 6 [HARD] ─────────────────────────────────────────────
    NESTED struct banao: struct Address { string city; int pinCode; }; aur
    struct Employee { string name; Address ad; }; Ek employee ka pura address
    print karo (city + pin).
    💡 HINT: Employee e; e.ad.city = "Indore"; (dot ke baad dot — nested access)
    ✏️ STARTER CODE:
      #include <iostream>
      #include <string>
      using namespace std;
      struct Address { string city; int pinCode; };
      struct Employee { string name; Address ad; };
      int main() {
          Employee e;
          // TODO: e.name, e.ad.city, e.ad.pinCode bharo
          // TODO: sab print karo
          return 0;
      }

 ── TASK 7 [HARD] ─────────────────────────────────────────────
    struct ke ANDAR hi ek member function banao: int total() jo teeno marks
    ka sum return kare. Phir 3 students me se topper ka naam aur total print karo.
    💡 HINT: int total() { return marks[0]+marks[1]+marks[2]; } — call s[i].total();
    ✏️ STARTER CODE:
      struct Student2 {
          string name; int rollNo; int marks[3];
          int total() { }   // TODO: teeno marks ka sum return karo
      };
      int main() {
          Student2 s[3];  // TODO: data bharo
          // TODO: s[i].total() compare karke topper dhundo
          return 0;
      }
═══════════════════════════════════════════════
*/

#include<iostream>
using namespace std;
int main(){
 
return 0;
}