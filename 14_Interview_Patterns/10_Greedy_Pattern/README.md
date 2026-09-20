# 10_Greedy_Pattern

## Real-world analogy summary

Greedy har step par best local choice leta hai, jaise activity selection me earliest ending meeting choose karna. But greedy har problem me work nahi karta — proof/counterexample zaruri hai.

## Greedy checklist

```text
1. Local choice define karo.
2. Sort key identify karo if needed.
3. Prove choice safe hai using exchange argument.
4. Counterexample try karo.
```

## Pattern table

| Problem | Greedy rule | Time | Space |
|---|---|---:|---:|
| Activity selection | sort by end, pick compatible | O(n log n) | O(1) |
| Min platforms | sorted arrivals/departures active count | O(n log n) | O(1) |
| Jump game brute | check previous reachable | O(n²) | O(n) |
| Jump game greedy | maintain farthest reach | O(n) | O(1) |
| Candy distribution | left pass + right pass | O(n) | O(n) |

## Common mistakes

1. Greedy use karna without proof.
2. Activity selection start time se sort karna instead of end time.
3. Min platforms me arrival <= departure condition problem-specific handle na karna.
4. Jump game me current index reachability check miss karna.
5. Candy me single pass se dono neighbor constraints satisfy karne ki koshish.

## Interview questions

1. Greedy kya hota hai?
2. Greedy kab work karta hai?
3. Activity selection proof explain karo.
4. Min platforms two pointer logic explain karo.
5. Jump game greedy farthest logic explain karo.
6. Candy distribution two-pass greedy explain karo.
