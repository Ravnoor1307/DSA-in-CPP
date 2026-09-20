# Frequency Counting

Count how many times each distinct value appears — then answer "most frequent",
"least frequent" and "first non-repeating". Three approaches run from a naive
O(n²) double loop to an O(n) hash-table single pass; all three must agree on
the same counts, which is how you verify them against each other.

- **Real-world analogy:** A shop tally sheet. The slow clerk re-counts the whole
  receipt pile for each product; the fast clerk ticks one counter per product
  name while scanning once. The tally sheet is a hash map.
- Key gotcha to remember first: "first non-repeating" needs TWO passes — build
  counts, then re-scan the original array order (a map does not remember order).
- Max/min frequency needs only ONE extra table walk once counts exist.

## Files + purpose

| File            | Purpose                                            |
|-----------------|----------------------------------------------------|
| `01_theory.cpp` | Nested / visited / hashing approaches, complexity derivation, ASCII walkthrough, compile-ready demo |
| `task.cpp`      | 5 practise tasks EASY→HARD with hints, starter code and full solved code |
| `README.md`     | This summary + cheat sheet + interview Q&A          |

## Cheat sheet

```
// Build the frequency table — O(n) average, one pass
unordered_map<int,int> mp;
for (int x : a) mp[x]++;

// Max frequency — one table walk
int bestVal = a[0], bestCnt = 0;
for (auto& p : mp) if (p.second > bestCnt) { bestVal = p.first; bestCnt = p.second; }

// First non-repeating — re-scan ORIGINAL array, not the map
for (int x : a) if (mp[x] == 1) return x;
```

## Complexity table

| Approach       | Time       | Space | When to use                        |
|----------------|------------|-------|------------------------------------|
| Nested loop    | O(n²)      | O(1)  | teaching the definition only        |
| Visited array  | O(n²) worst| O(n)  | avoid duplicate reports, still slow |
| `std::map`     | O(n log n) | O(n)  | sorted output needed                |
| `unordered_map`| O(n) avg   | O(n)  | interviews & production        |

Derivations: nested → **n** outer × **n** inner = n·n. visited → one full scan
per distinct element, worst case n distinct → O(n²). unordered_map insert is
amortized O(1), so **n** inserts = O(n); collisions worst case O(n²).

## ⚠️ Common mistakes

- Using the **map's iteration order** for "first non-repeating" — wrong, maps
  don't store array order. Always re-scan the original array.
- Forgetting the empty-array edge case before touching `mp.begin()`.
- Using a fixed-size array `count[maxVal]` when values are large/negative —
  wastes memory; `unordered_map` allocates only for distinct keys.
- Declaring min-frequency with `bestCnt = 0` — every compare fails because no
  count is below 0; start from `INT_MAX`.

## Interview Q&A

**Q1. How would you solve frequency counting when the array is sorted?**  
Two-pointer sweep — equal neighbours collapse into a run, giving O(n) time with
O(1) space; no hash table needed.

**Q2. What if values are huge like 10⁹ or negative?**  
`unordered_map` — it hashes the value and stores only distinct keys, so memory
is O(d) regardless of the numeric range. Array-index counting would need 10⁹ slots.

**Q3. Why is XOR useful for "two elements appearing once"?**  
`a^a=0` and XOR is commutative, so XORing everything leaves `a^b`. Any set bit of
that result differs between the two numbers, letting you partition and recover both
in O(1) space.