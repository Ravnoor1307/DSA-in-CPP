# 01_Hashing_Intro

## Real-world analogy summary

Hashing school bag index page ya cloak room token system jaisa hai. Key se direct bucket/index milta hai, isliye search average O(1) tak fast ho sakta hai.

## Core visual

```text
key -> [HASH FUNCTION] -> index -> bucket
23  ->      23 % 10    ->   3   -> bucket[3]
```

## Why hashing?

| Search method | Real-world analogy | Calculation | Time |
|---|---|---:|---:|
| Linear search | har pocket check | n comparisons | O(n) |
| Binary search | sorted book half discard | n/2^k=1 -> k=log₂n | O(log n) |
| Hashing average | token to cabin direct | hash + small bucket check | O(1) avg |

## Important formulas

```text
Simple hash = key % tableSize
Load factor alpha = n / tableSize
Average bucket length ≈ alpha
```

## Why average O(1)?

Hash function O(1) index deta hai. Agar keys evenly distribute hon aur load factor controlled ho, bucket/probe length constant rehti hai. But all keys collide kar gaye to one bucket me n keys ho sakte hain, so worst O(n).

## Common mistakes

1. Hashing ko guaranteed O(1) bolna; correct: average O(1), worst O(n).
2. Collision ignore karna.
3. Poor table size/hash function choose karna.
4. `key % tableSize` ka range 0 to tableSize-1 yaad na rakhna.

## Interview questions

1. Hashing ki need kya hai?
2. Hash function kya karta hai?
3. Hash table buckets ka visual banao.
4. Collision kya hota hai?
5. Average O(1) and worst O(n) ka reason kya hai?
