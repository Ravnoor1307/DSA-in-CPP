/*
═══════════════════════════════════════════════
 TASK SET — 2D ARRAY — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    Ek cinema hall ka seat plan 3x4 ka grid hai — har seat (row, col) se banti hai.
    Management ko poore grid ka total, har row ki selling, sabse jam-poor seat, aur
    transpose (row↔column) nikalna hai. Ye sab 2D array par basic operations hain.

 🧠 HOW TO SOLVE:
    Nested loop ka pattern sabse important hai — bhar wala loop ROW ka, andar wala
    COLUMN ka (row-major). Sum/max ke liye poora traverse karo. Transpose me
    mat[i][j] ↔ mat[j][i] swap. Multiplication me roz row[ik] × col[j] product-sum.

 TASKS (EASY → HARD):

 ── TASK 1 [EASY] ─────────────────────────────────────────────
    mat[3][3] = {1,2,3,4,5,6,7,8,9} hai. Isse grid ki shape me print karo
    (har row alag line par).
    💡 HINT: andar wali loop ke baad cout << "\n"; — har row ke baad naya line.
    ✏️ STARTER CODE:
      #include <iostream>
      using namespace std;
      int main() {
          int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
          // TODO: nested loop se grid print karo
          return 0;
      }

 ── TASK 2 [EASY] ─────────────────────────────────────────────
    3x3 matrix ki values user se input lo aur fir grid me print karo.
    💡 HINT: cin >> mat[i][j]; nested loop ke andar.
    ✏️ STARTER CODE:
      int main() {
          int mat[3][3];
          // TODO: cin se 9 values lo
          // TODO: grid print karo
          return 0;
      }

 ── TASK 3 [EASY-MEDIUM] ──────────────────────────────────────
    Matrix ke saare elements ka TOTAL nikaalo.
    💡 HINT: total += mat[i][j]; har cell ko jodte jao.
    ✏️ STARTER CODE:
      int main() {
          int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
          int total = 0;
          // TODO: sab cells ka sum
          return 0;
      }

 ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    HAR ROW ka sum alag print karo (row0, row1, row2 ka number).
    💡 HINT: inner loop ke baad rowSum reset karo ya naye loop se.
    ✏️ STARTER CODE:
      int main() {
          int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
          // TODO: har row ka sum, har row print karo
          return 0;
      }

 ── TASK 5 [MEDIUM] ───────────────────────────────────────────
    SABSE BADA element dhundo aur uska (row, column) print karo.
    💡 HINT: maxVal = mat[0][0]; record pair (maxR, maxC) bhi sath rakho.
    ✏️ STARTER CODE:
      int main() {
          int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
          int maxVal = mat[0][0], maxR = 0, maxC = 0;
          // TODO: max + uski position nikaalo
          return 0;
      }

 ── TASK 6 [MEDIUM-HARD] ──────────────────────────────────────
    TRANSPOSE — 3x3 matrix ka transpose nikaalo (row ↔ column swap karke).
    💡 HINT: sirf i < j waley cells swap karo; mat[i][j] ↔ mat[j][i].
    ✏️ STARTER CODE:
      int main() {
          int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
          // TODO: i<j wale swaps se transpose karo
          // TODO: print karke verify karo
          return 0;
      }

 ── TASK 7 [HARD] ─────────────────────────────────────────────
    MATRIX MULTIPLICATION — A (2x3) aur B (3x2) ko multiply karke 2x2 result
    banao. C[i][j] = sum of A[i][k] * B[k][j] for k=0,1,2.
    💡 HINT: teen loops — i (rows of A), j (cols of B), k (common dimension).
    ✏️ STARTER CODE:
      int main() {
          int A[2][3] = {{1,2,3},{4,5,6}};
          int B[3][2] = {{7,8},{9,10},{11,12}};
          int C[2][2] = {};
          // TODO: k-loop ke andar accumulate karo
          // TODO: C print karo
          return 0;
      }
═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}