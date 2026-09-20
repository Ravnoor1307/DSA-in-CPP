/*
═══════════════════════════════════════════════
 TASK SET — ROW-MAJOR vs COLUMN-MAJOR ORDER
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    RAM ki memory ek lambi address-line hai. Jab 2D data (saraka 2D array ya exam
    ka question) flat memory me rakhna ho to compiler ek order follow karta hai —
    row-major (C/C++/Java) ya column-major (Fortran/MATLAB). Address nikalne ke
    liye formula lagana padta hai; interview aur exams me yahi poocha jata hai.

 🧠 HOW TO SOLVE:
    Formula pakka rakho:
        Row-major    (0-based): Addr = B + (i*C + j)*size
        Column-major (0-based): Addr = B + (j*R + i)*size
    1-based ho to i → (i-1) aur j → (j-1) rakho. Reverse me offset se i,j nikalna
    ho to division/mod use karo.

 TASKS (EASY → HARD):

 ── TASK 1 [EASY] ─────────────────────────────────────────────
    A[10][15] int array, base=1000. A[4][6] ka ROW-MAJOR address nikaalo.
    💡 HINT: offset = (4*15 + 6)*4 → add to 1000.
    ✏️ STARTER CODE:
      #include <iostream>
      using namespace std;
      int main() {
          long long base = 1000; int R = 10, C = 15;
          int i = 4, j = 6, size = 4;
          // TODO: row-major formula lagao
          // TODO: cout se address print karo
          return 0;
      }

 ── TASK 2 [EASY] ─────────────────────────────────────────────
    Same A[10][15] (base 1000), A[7][2] ka COLUMN-MAJOR address nikaalo.
    💡 HINT: offset = (2*10 + 7)*4.
    ✏️ STARTER CODE:
      int main() {
          long long base = 1000; int R = 10, C = 15;
          int i = 7, j = 2, size = 4;
          // TODO: column-major formula lagao
          return 0;
      }

 ── TASK 3 [MEDIUM] ───────────────────────────────────────────
    A[10][15] base=1000 me A[3][8] ke liye DONO order ka address nikaalo aur
    batao kaun sa pehle aata hai (chhota address) aur kya farak hai.
    💡 HINT: dono calculate karo, phir compare karke print karo.
    ✏️ STARTER CODE:
      int main() {
          long long base = 1000; int R = 10, C = 15;
          int i = 3, j = 8, size = 4;
          // TODO: rm aur cm dono nikaalo
          // TODO: chhota wala order print karo
          return 0;
      }

 ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    1-BASED indexing: A[1..10][1..15], base 1000, size 4. A[3][8] ka address
    row-major aur column-major dono nikaalo (i,j ko 1 kam karke lagao).
    💡 HINT: row: (3-1)*15 + (8-1);  col: (8-1)*10 + (3-1).
    ✏️ STARTER CODE:
      int main() {
          long long base = 1000; int R = 10, C = 15, size = 4;
          int i = 3, j = 8;
          // TODO: (i-1) aur (j-1) use karke dono formula
          return 0;
      }

 ── TASK 5 [MEDIUM-HARD] ──────────────────────────────────────
    REVERSE — row-major me offset mile hai: base=1000, size=4, C=15, address=1212.
    A[?][?] kaun sa element hai? (offset/jahat se i aur j nikaalo)
    💡 HINT: elementNo = (addr-base)/size;  i = elementNo / C;  j = elementNo % C.
    ✏️ STARTER CODE:
      int main() {
          long long base = 1000; int size = 4, C = 15;
          long long addr = 1212;
          // TODO: elementNo nikaalo, phir i = elementNo/C, j = elementNo%C
          return 0;
      }

 ── TASK 6 [HARD] ─────────────────────────────────────────────
    LAST ELEMENT — A[12][8] (R=12, C=8), base=2000, double size=8. Row-major
    aur column-major dono se A[11][7] (aakhri cell) ka address verify karo —
    dono ko aakhri cell par SAME address aana chahiye.
    💡 HINT: last offset = R*C - 1 = 95; base + 95*8. Dono formula se bhi parse.
    ✏️ STARTER CODE:
      int main() {
          long long base = 2000; int R = 12, C = 8, size = 8;
          int i = 11, j = 7;
          // TODO: rm, cm, aur base + (R*C-1)*size teeno print karo
          return 0;
      }

 ── TASK 7 [HARD] ─────────────────────────────────────────────
    ELEMENT SIZE — Row-major array me A[2][3] ka address 1048 hai aur A[2][4]
    ka 1052 hai. Har element kitne bytes ka hai, aur base B kya hai (C=10)?
    💡 HINT: size = addr(2,4) - addr(2,3) = 4. phir B = addr(2,3) - (2*10+3)*4.
    ✏️ STARTER CODE:
      int main() {
          long long a23 = 1048, a24 = 1052; int C = 10;
          // TODO: size = a24 - a23; phir B nikaalo
          return 0;
      }
═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}