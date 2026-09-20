# 05_Fast_Slow_Pointers

## Real-world analogy summary

Circular race track par fast runner slow runner ko catch kar leta hai. Isi speed difference se linked list cycle, duplicate number, happy number cycles, and middle node problems solve hote hain.

## Floyd proof

```text
Inside cycle:
slow moves 1 step
fast moves 2 steps
fast gains 1 step per iteration
cycle length C
max C iterations me gap 0 -> meet
```

## Pattern table

| Problem | Model | Key trick | Time | Space |
|---|---|---|---:|---:|
| Linked list cycle | pointers | slow 1, fast 2 | O(n) | O(1) |
| Find duplicate number | nums[i] = next pointer | cycle entry | O(n) | O(1) |
| Happy number | digit-square sequence | cycle detection | O(m*d) | O(1) |
| Palindrome linked list | list middle | middle + reverse half | O(n) | O(1) |

## Common mistakes

1. `fast && fast->next` condition miss karna.
2. Duplicate number problem me array modify kar dena when O(1) no-modification asked.
3. Happy number me hash set use karna when O(1) space asked.
4. Palindrome linked list me second half reverse comparison off-by-one.

## Interview questions

1. Floyd cycle detection proof do.
2. Find duplicate number array-as-linked-list kaise hai?
3. Happy number fast-slow se kaise solve hota hai?
4. Palindrome linked list O(1) space me kaise check karte hain?
