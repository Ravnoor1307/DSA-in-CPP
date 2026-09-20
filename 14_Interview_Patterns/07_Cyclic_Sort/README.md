# 07_Cyclic_Sort

## Real-world analogy summary

Roll numbers 1 to n ko correct seats par bithana hai. Number `x` ki seat index `x-1` hoti hai. Missing/duplicate problems me wrong seats answer reveal karte hain.

## Core template

```cpp
int i = 0;
while (i < n) {
    int correct = nums[i] - 1;
    if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
    else i++;
}
```

## Signal

```text
Array contains numbers from 1 to n or 0 to n
Find missing/duplicate/disappeared
Need O(n) time and O(1) extra space
```

## Pattern table

| Problem | Correct index | Time | Space |
|---|---|---:|---:|
| Cyclic sort 1..n | value-1 | O(n) | O(1) |
| Missing number 0..n | value | O(n) | O(1) |
| Find duplicates | value-1 + duplicate guard | O(n) | O(1) |
| Disappeared numbers | mismatch index+1 | O(n) | O(1) |
| First missing positive | only values 1..n | O(n) | O(1) |

## Common mistakes

1. Duplicate guard miss karna, infinite loop ho sakta hai.
2. 0..n and 1..n index rules mix karna.
3. First missing positive me negative/large values swap karna.
4. Output array ko extra space me count karna; usually excluding answer O(1) bola jata hai.

## Interview questions

1. Cyclic sort signal kya hai?
2. `correctIndex = nums[i]-1` kyun?
3. Find duplicates O(n)/O(1) kaise?
4. First missing positive cyclic sort se kaise solve hota hai?
