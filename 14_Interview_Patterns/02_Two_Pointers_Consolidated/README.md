# 02_Two_Pointers_Consolidated

## Real-world analogy summary

Two pointers do traffic guards jaise hain. Kabhi dono ends se move karte hain, kabhi same direction me fast/slow, kabhi linked list me speed difference se cycle pakadte hain.

## Variants

| Variant | Signal | Template | Example |
|---|---|---|---|
| Opposite ends | sorted array, pair, palindrome | `l=0,r=n-1` | container water, two sum |
| Same direction | remove duplicates/partition | `slow write, fast scan` | move zeroes |
| Fast-slow | cycle/middle | `slow+=1, fast+=2` | LL cycle |

## Complexity calculation

```text
Each pointer moves in one direction.
left moves at most n times, right moves at most n times.
Total moves <= 2n.
Time = O(n), Space = O(1).
```

## Approach comparison

| Problem | Brute force | Optimized pattern |
|---|---:|---:|
| Container with water | O(n²) all pairs | O(n) two pointers |
| 3Sum | O(n³) triplets | O(n²) sort + two pointers |
| Trapping rainwater | prefix/suffix O(n) space | two pointers O(1) space |
| LL cycle | hash set O(n) space | fast-slow O(1) space |

## Common mistakes

1. Container water me larger pointer move karna.
2. 3Sum me duplicates skip na karna.
3. Sorted requirement ignore karna for opposite-end sum.
4. Fast-slow loop condition `fast && fast->next` miss karna.
5. Two pointer movement proof explain na karna.

## Interview questions

1. Two pointer pattern identify kaise karte ho?
2. Container with most water me smaller pointer kyun move hota hai?
3. 3Sum O(n²) kaise hota hai?
4. Trapping rainwater two pointer logic explain karo.
5. Floyd cycle detection proof do.
