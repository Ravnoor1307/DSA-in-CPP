# 08 — Row-Major vs Column-Major Order

- RAM memory is one continuous address line; a 2D array must be flattened into it, and the flattening rule is the "order".
- **Row-major**: whole row 0 first, then row 1, ... → formula `Addr = B + (i*C + j)*size` (C = columns).
- **Column-major**: whole column 0 first, then column 1, ... → formula `Addr = B + (j*R + i)*size` (R = rows).
- C/C++/Java use row-major; Fortran/MATLAB/R use column-major — the same element can get a different address.
- For 1-based indexing (book/exam style) substitute `i → (i-1)` and `j → (j-1)`; access is still O(1).

## 🌍 Real-World Analogy

**Godown, almari aur shelves:**

- Row-major  = **almari-bar-almari**: pehli almari ki saari 15 shelves rakh do, phir agli almari ki, aise.
- Column-major = **shelf-bar-shelf**: har almari ki shelf-1 sabse pehle, phir sabki shelf-2...

```
Row-major  : almari_0(s1..s15) almari_1(s1..s15) almari_2(s1..s15) ...
Column-major: s1×15 almariyan, phir s2×15 almariyan, phir s3×15 ...
```

Manager ko (almari=row, shelf=col) batao to address formula se exact location milegi.

> *RAM bhi ek godown hai — order decide karta hai kaunsa item kahan rakha hai.*

## 📂 Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | Formula DERIVATION step-by-step, flat-memory ASCII visual, dry-run on A[10][15], edge cases, interactive address calculator, 1-based demo |
| `task.cpp` | 7 tasks EASY→HARD: row-major → column-major → compare both → 1-based → reverse(offset→i,j) → last-cell verify → find element size & base |

## 📌 Cheat Sheet / Formulas

```
0-based Row-major  : Addr(A[i][j]) = B + (i*C + j) * size
0-based Col-major  : Addr(A[i][j]) = B + (j*R + i) * size
1-based Row-major  : Addr(A[i][j]) = B + ((i-1)*C + (j-1)) * size
1-based Col-major  : Addr(A[i][j]) = B + ((j-1)*R + (i-1)) * size

Shorthand mnemonics:
  Row-major  -> "i*C" : i rows × columns (i pehle, phir j)
  Col-major  -> "j*R" : j columns × rows   (j pehle, phir i)

REVERSE (row-major): offset = (addr - B) / size
                     i = offset / C,  j = offset % C

Edge checks:
  First cell A[0][0]      : both formulas give B
  Last cell A[R-1][C-1]   : both formulas give B + (R*C - 1)*size
```

### Worked example (A[10][15], size=4, base=1000)

| Cell | Row-major | Column-major |
|---|---|---|
| A[3][8] | 1000 + (3·15+8)·4 = **1212** | 1000 + (8·10+3)·4 = **1332** |
| A[0][0] | 1000 | 1000 |
| A[9][14] | 1596 | 1596 |

## ⏱ Complexity at a glance

| Operation | Step Count | Complexity |
|---|---|---|
| Address by formula | 2 mult + 2 add, fixed | f = 3 → **O(1)** |
| No extra memory | only scalar variables | f = 1 → **O(1)** |
| Full 2D traversal | R×C visits | f = R·C → **O(R·C)** |

## ⚠️ Common Mistakes

1. **Formula mix** — row-major me `i*C+j`, column-major me `j*R+i`. Column-major me C ki jagah R lagana sabse common galti hai.
2. **1-based vs 0-based** — exam question me indexes 1 se shuru hain to `(i-1)`, `(j-1)` karna zaroori; nahi to answer 15/30 offset zyada aayega.
3. **size bhoolna** — formula ka aakhri multiplier `size` (har element k kitne byte). `size=4` (int) vs `size=8` (double/long long) me answer alag.
4. **`(i*C+j)` int overflow** — badi matrices me `long long` use karo; `int` me (i up to 1e5) * C bhi overflow ho sakta hai.
5. **Reverse me galti `%`/`/`** — `i = offset / C`, `j = offset % C` (column-major reverse me order ulta: `j = offset/R`, `i = offset%R`).
6. **Row-major VS column-major address ko "same" maanna** — wahi element dono order me different address par aa sakta hai; sirf pehla aur aakhri cell force-same hote hain.

## 🤝 Interview Q&A

**Q1. C++ me 2D array kaise store hota hai?**
Row-major me — `A[i][j]` ka address `B + (i*C + j)*size` par milta hai.

**Q2. Row-major aur column-major me kya farak?**
Row-major row ko saath rakhta hai (adjacent = horizontal); column-major column ko saath rakhta hai (adjacent = vertical). Isi se cache performance aur formulas badal jate hain.

**Q3. Full formula derive karke dikhao?**
Row-major: A[i][j] tak i poori rows × C elements chhodne hain + usi row me j elements → offset = (i*C + j) → × size. Column-major: j poori columns × R + i → (j*R + i) × size.

**Q4. 1-based indexing me formula?**
Row: `B + ((i-1)*C + (j-1))*size`; col: `B + ((j-1)*R + (i-1))*size`.

**Q5. Bina formula ke last element ka address?**
`B + (R*C - 1)*size` — dono order me same, kyunki total elements ka count order se free hota hai.

**Q6. Matrix multiplication me kaunsa order better?**
Row-major C/C++ me better cache behavior deta hai jab inner loop row ke andar bhejta hai — isliye loop-nesting ko order ke hisaab se banaya jata hai (ij-form preferred).

**Q7. Column-major languages kaun si?**
Fortran, MATLAB, R (aur page-column-major arrays kuch libraries me).