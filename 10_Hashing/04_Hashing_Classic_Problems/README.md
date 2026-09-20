# 04_Hashing_Classic_Problems

## Real-world analogy summary

Classic hashing problems O(n²) brute-force ko O(n) average me convert karte hain. Theme: jo cheez future me dhundhni hai, use map/set me yaad rakho.

## Approach comparison table

| Problem | Approach | Pattern | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Two Sum | brute force | all pairs | n(n-1)/2 pairs | O(n²) | O(1) |
| Two Sum | hashmap | complement lookup | n finds/inserts avg O(1) | O(n) avg | O(n) |
| Count distinct | sort | adjacent groups | sort n log n + scan n | O(n log n) | O(n) copy |
| Count distinct | set | unique gate | n inserts avg O(1) | O(n) avg | O(n) |
| Union/intersection | set | membership | n+m operations | O(n+m) avg | O(n+m) |
| Arrays equal | freq add/subtract | multiset equality | 2n+d checks | O(n) avg | O(n) |
| First repeating | freq + order scan | first index with count>1 | 2n | O(n) avg | O(n) |
| First non-repeating | freq + order scan | first count==1 | 2n | O(n) avg | O(n) |

## Key patterns

```text
Two Sum:
need = target - arr[i]
if need in map -> answer
else map[arr[i]] = i

Frequency equality:
freq[x]++ for A
freq[x]-- for B
all zero => equal

First unique/repeating:
PASS 1 frequency
PASS 2 original order scan
```

## Common mistakes

1. Two Sum me current element ko complement check se pehle insert kar dena duplicate issue create kar sakta hai.
2. Count distinct sort approach me sort cost ignore karna.
3. unordered_set output sorted assume karna.
4. First repeating me first repeated occurrence vs first repeating by original index confuse karna.
5. Arrays equal frequency me length mismatch check skip karna.

## Interview questions

1. Two Sum brute and hashmap compare karo.
2. [2,7,11,15], target 9 ka hashmap dry run karo.
3. Count distinct sort vs set explain karo.
4. Union and intersection using set solve karo.
5. Two arrays equal by frequency ka algorithm kya hai?
6. First repeating/non-repeating element ka two-pass frequency pattern explain karo.
