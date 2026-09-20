/*
═══════════════════════════════════════════════
 TASK SET — ARRAYS (1D) — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
    Ek class me 5 students ke marks ek list me zamaye hue hain. Koi total poochta
    hai, koi topper, koi delete karna chahta hai. Ye saare kaam continuous list
    (array) par 5 basis operations hain: traverse, sum, max, search, insert, delete.

 🧠 HOW TO SOLVE:
    Har task me ek array + uski filled-length `n` rakho. Traverse ke liye for loop
    (i=0..n-1). Shifting kaam me loop ki direction matter karti hai — insert RIGHT
    shift karta hai (peeche se), delete LEFT shift karta hai (aage se).

 TASKS (EASY → HARD):

 ── TASK 1 [EASY] ─────────────────────────────────────────────
    arr[6] = {4, 8, 15, 16, 23, 42} ko loop se saath de kar print karo.
    💡 HINT: for (int i = 0; i < n; i++) cout << arr[i] << " ";
    ✏️ STARTER CODE:
      #include <iostream>
      using namespace std;
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6;
          // TODO: sab elements print karo
          return 0;
      }

 ── TASK 2 [EASY] ─────────────────────────────────────────────
    arr[6] = {4, 8, 15, 16, 23, 42} ka SUM nikalo aur print karo.
    💡 HINT: sum += arr[i]; har element ko jodte jao.
    ✏️ STARTER CODE:
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6, sum = 0;
          // TODO: sum nikaalo, phir cout << sum
          return 0;
      }

 ── TASK 3 [EASY-MEDIUM] ──────────────────────────────────────
    SABSE BADA element dhundo, saath uska INDEX bhi print karo.
    💡 HINT: maxVal = arr[0]; agar arr[i] > maxVal to maxVal = arr[i], maxIdx = i.
    ✏️ STARTER CODE:
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6, maxVal = arr[0], maxIdx = 0;
          // TODO: loop se max + index nikaalo
          return 0;
      }

 ── TASK 4 [MEDIUM] ───────────────────────────────────────────
    Array ko REVERSE karo (in-place, bina second array ke) — arr = {42,23,16,15,8,4}.
    💡 HINT: swap(arr[i], arr[n-1-i]) — sirf aadhe tak loop chalao.
    ✏️ STARTER CODE:
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6;
          // TODO: swap se reverse karo
          // TODO: print karke verify karo
          return 0;
      }

 ── TASK 5 [MEDIUM] ───────────────────────────────────────────
    LINEAR SEARCH — value x (maan lo 23) array me hai? Agar hai to uska index,
    nahi to -1 print karo.
    💡 HINT: for loop me if (arr[i] == x) { pos = i; break; }
    ✏️ STARTER CODE:
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6, x = 23, pos = -1;
          // TODO: x dhundo, pos set karo
          // TODO: pos print karo
          return 0;
      }

 ── TASK 6 [MEDIUM-HARD] ──────────────────────────────────────
    INSERT — array me position 2 par value 99 daalo (baaki right shift)
    kapacity 10, filled 6. Result {4,8,99,15,16,23,42}.
    💡 HINT: for (i = n; i > p; i--) arr[i] = arr[i-1]; phir arr[p] = val; n++;
    ✏️ STARTER CODE:
      int main() {
          int arr[10] = {4, 8, 15, 16, 23, 42};
          int n = 6, p = 2, val = 99;
          // TODO: right shift karo, val daalo, n badhao
          // TODO: print karo
          return 0;
      }

 ── TASK 7 [HARD] ─────────────────────────────────────────────
    DELETE — position 1 (value 8) array se hatao, baaki LEFT shift karo.
    Result {4,15,16,23,42}, n = 5.
    💡 HINT: for (i = p; i < n-1; i++) arr[i] = arr[i+1]; n--;
    ✏️ STARTER CODE:
      int main() {
          int arr[] = {4, 8, 15, 16, 23, 42};
          int n = 6, p = 1;
          // TODO: left shift karo, n ghatao
          // TODO: print karo
          return 0;
      }
═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}