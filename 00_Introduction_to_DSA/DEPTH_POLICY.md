# 00_Introduction_to_DSA — Depth Policy

> Ye folder **INTRODUCTION** hai — yahan sirf "ye cheez hai kya" batana hai.
> Deep implementation apne-apne dedicated folders me hogi.

## 🟡 LIGHT — sirf INTRO (Data Structures)

Inka kaam sirf **pehchaan karana** hai. Real-world analogy + 1 chhota example + "kab use hota hai" + "detail kahan milegi".
**NO** full implementation, NO multiple approaches, NO heavy dry run.

| Folder | Detail kahan milegi |
|---|---|
| 06_Arrays_1D | → `03_Array/` |
| 07_2D_Array | → `03_Array/` + `05_Matrices/` |
| 09_Drawbacks_of_Array | → `03_Array/` |
| 10_Linked_List | → `06_Linked_List/` |
| 11_Doubly_Linked_List | → `06_Linked_List/` |
| 12_Self_Referential_Structure | → `06_Linked_List/` |
| 13_Creating_Node_of_SLL | → `06_Linked_List/` |
| 14_Implementation_in_Cpp_malloc | → `06_Linked_List/` |
| 15_Stack_LIFO | → `07_Stack/` |
| 16_Queue_FIFO | → `08_Queue/` |
| 17_Trees | → `10_Binary_Tree/` |
| 18_Graphs | → `13_Graph/` |

**Files:** `01_xxx_intro.cpp` + `README.md` (bas 2 files)

**Exception:** `08_Row_Major_Column_Major_Order` — isme **address calculation formula** hai (maths),
isliye ye MEDIUM detail me hoga, formula derivation ke saath.

---

## 🟢 DETAILED — poora explain

### Part_01 ke concept folders
`01_Data`, `02_Data_Structure`, `03_Types_of_Data_Structure`,
`04_Primitive_Data_Structure`, `05_Non_Primitive_Data_Structure`,
`19_Various_Data_Structures`, `20_Operations_on_Data_Structures`,
`21_Static_vs_Dynamic_DS`, `22_Homogeneous_vs_Non_Homogeneous_DS`,
`23_Algorithm`, `24_Interview_Questions`

### Part_02 — POORA folder MAXIMUM detail ⭐
Ye course ka sabse important hissa hai. Har folder me:
- Real-world scenario
- Full mathematical derivation (`n/2^k = 1 → k = log₂n` type)
- Running code jo actually operations count kare
- Har approach ki complexity **step-by-step calculation** ke saath
- Graph/plot comparison table
- Dry run

---

## ⚠️ GOLDEN RULE (har file me, bina exception)

**REAL-WORLD SCENARIO PEHLE, PHIR TECHNICAL EXPLANATION.**

Bina real-life example ke koi bhi concept explain nahi hoga —
na theory file me, na approach file me, na README me.

Complexity bhi real-world se:
- O(1) → "ghar ka address pata hai, seedha pahunch gaye"
- O(n) → "puri gali me ek-ek ghar dekhna"
- O(log n) → "dictionary beech se kholna"
- O(n²) → "class ke har bachche ko har dusre bachche se milana"

---

## ⚠️ COMPLEXITY RULE

Khaali `O(n)` likhna **FORBIDDEN**. Hamesha calculation dikhani hai:

```
// TIME COMPLEXITY CALCULATION:
// - Outer loop: n baar chalega
// - Inner loop: har outer iteration me n baar
// - Total = n × n = n²
// → Time Complexity = O(n²)
```
