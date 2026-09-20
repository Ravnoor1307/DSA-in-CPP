# 05_Hashing_Advanced_Patterns

## Real-world analogy summary

Advanced hashing patterns running balance, sliding windows, and pair-sum memory par based hain. Prefix sum + hash arrays ke hidden subarrays detect karne ka powerful tool hai.

## Approach comparison table

| Problem | Pattern | Key trick | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Zero-sum subarray | prefix + set | same prefix repeated | n updates/lookups | O(n) avg | O(n) |
| Given-sum subarray | prefix + map | `prefix-target` seen | n lookups | O(n) avg | O(n) |
| Longest zero-sum | prefix first index | longest gap between same sums | n lookups | O(n) avg | O(n) |
| Largest 0/1 subarray | transform 0 to -1 | equal counts -> zero sum | n lookups | O(n) avg | O(n) |
| Distinct in window | sliding window + freq | add incoming/remove outgoing | k + 2(n-k) ops | O(n) avg | O(k) |
| Group by frequency | freq + sort pairs | sort d distinct keys | n + d log d | O(n+d log d) | O(d) |
| Four sum concept | pair sums hash | target - pairSum | n(n-1)/2 pairs | O(n²) avg concept | O(n²) |

## Key patterns

```text
Zero-sum:
if prefix repeats -> subarray sum between repeats is 0

Given sum:
need = prefix - target
if need seen -> subarray found

Longest zero-sum:
store first index of each prefix
length = currentIndex - firstIndex[prefix]

0/1 equal:
0 -> -1, 1 -> +1, then longest zero-sum

Window distinct:
freq[out]--, erase if 0, freq[in]++
```

## Common mistakes

1. Prefix sum 0 ko initially seen/index -1 par store na karna.
2. Longest subarray me first prefix index overwrite kar dena.
3. 0/1 problem me 0 ko -1 transform na karna.
4. Sliding window me outgoing frequency 0 hone par erase na karna.
5. Four sum pair indices overlap check skip karna.

## Interview questions

1. Same prefix sum repeated means zero-sum subarray kyun?
2. Subarray with given sum using prefix hash explain karo.
3. Longest zero-sum subarray me first index kyun store karte hain?
4. Largest 0/1 subarray me 0 ko -1 kyun karte hain?
5. Count distinct in every window ka sliding hash dry run do.
6. Four sum pair hashing concept explain karo.
