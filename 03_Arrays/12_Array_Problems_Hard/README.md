# Hard Array Classics

Four advanced problems that combine the earlier primitives: **max consecutive
ones with k flips** (sliding window), **longest consecutive sequence** (sort vs
hash-set), **next permutation** (pivot + reverse), and **rotate matrix 90°**
(transpose + reverse rows). Knowing the *derivation*, not just the code, is what
separates a strong answer here.

- **Real-world analogy:** repairing at most k failed servers to get the longest
  uptime run; ranking jersey numbers into consecutive streaks; a dictionary
  stepping to the next word; rotating camera frames by 90°.
- These build on everything before: windows, sets, in-place swaps and matrix
  transforms.

## Files + purpose

| File            | Purpose |
|-----------------|---------|
| `01_theory.cpp` | Theory, ASCII walkthroughs, complexity derivations (sort vs hash, transpose+reverse vs four-way cycle), demo running all four |
| `task.cpp`      | 5 practise tasks EASY→HARD (maxOnesK, longestConsecutiveHash, nextPermutation, rotate, spiral) |
| `README.md`     | This summary + cheat sheet + interview Q&A |

## Cheat sheet

```cpp
// max consecutive ones, at most k flips — O(n)
for (int r = 0; r < n; ++r) {
  if (a[r]==0) zeros++;
  while (zeros > k) { if (a[l]==0) zeros--; l++; }
  best = max(best, r-l+1);
}

// longest consecutive sequence — only run-starts stretch
for (int x : s) { if (s.count(x-1)) continue;
  int len=1; while (s.count(x+len)) len++; best = max(best, len); }

// next permutation
while (i>=0 && a[i]>=a[i+1]) i--;          // pivot
while (a[j] <= a[i]) j--;                  // rightmost greater
swap(a[i], a[j]); reverse(a.begin()+i+1, a.end());

// rotate clockwise = transpose + reverse rows
for (i) for (j=i+1) swap(m[i][j], m[j][i]);
for (row) reverse(row);
```

## Complexity table

| Problem                 | Approach    | Time       | Space |
|-------------------------|-------------|------------|-------|
| Max ones (k flips)      | sliding win | O(n)       | O(1)  |
| Longest consecutive     | sort+sweep  | O(n log n) | O(1)  |
| Longest consecutive     | hash-set    | O(n) avg   | O(n)  |
| Next permutation        | pivot+swap  | O(n)       | O(1)  |
| Rotate 90°              | transpose+reverse | O(n²) | O(1)  |

Derivations: sliding window moves l and r at most n times each → O(n). Sort
costs O(n log n); each set element is stretched at most once across all runs →
O(n) amortized. Next permutation: pivot scan ≤ n-1, second scan ≤ n, reverse ≤
n/2 → O(n). Rotate: transpose has n(n-1)/2 swaps + row reverses n²/2 → O(n²).

## ⚠️ Common mistakes

- maxOnesK: forgetting the `while` (not `if`) — one `if` lets multiple zeros
  break the invariant; also counting zeros already outside the window.
- longestConsecutiveHash: not using the `x-1 in set` skip, causing O(n²) stretch
  from every element.
- nextPermutation: using `>=`/`<=` wrongly in the pivot scan, or scanning from
  the left for pivot; trying to handle the "last permutation" by bubbling instead
  of full reverse.
- rotate: reversing columns instead of rows; forgetting the transpose's `j = i+1`
  bound (transposing twice cancels out).
- spiral: printing a row/col twice when the matrix degenerates to one row/column
  — the `top<=bottom` / `left<=right` guards exist exactly for that.

## Interview Q&A

**Q1. Why does the maxOnesK window only shrink until valid?** Every element is
visited twice total (once as r, once as l), and the invariant "≤k zeros" is
restored the moment enough left elements leave — over-shrinking can only reduce
the answer.

**Q2. Why is the hash approach O(n) for longest consecutive?** Amortization: only
run-starts do stretching, and every element is extended exactly once across all
runs, so total stretch work is n rather than n per element.

**Q3. Why reverse the decreasing tail in next permutation?** The tail is already
the maximum arrangement of those values; reversing produces the minimum
arrangement — exactly what the next lexicographic step needs.

**Q4. Transpose + reverse — why does that equal rotation?** Cell (i,j) → (j,i)
under transpose, then the row reverse maps column position — composing the two
maps (i,j) to (j, n-1-i), which is precisely clockwise 90°.