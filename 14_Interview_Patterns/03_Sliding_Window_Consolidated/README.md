# 03_Sliding_Window_Consolidated

## Real-world analogy summary

Sliding window CCTV camera frame jaisa hai jo contiguous road segment cover karta hai. Fixed window me frame size fixed hai; variable window me condition ke according expand/shrink hota hai.

## Universal template

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    add(arr[right]);
    while (window_invalid) {
        remove(arr[left]);
        left++;
    }
    update_answer(left, right);
}
```

## Pattern table

| Problem | Condition | Template | Time | Space |
|---|---|---|---:|---:|
| Longest substring K distinct | distinct <= K | variable max | O(n) | O(K) |
| Minimum window substring | all needs satisfied | expand then shrink valid | O(n+m) | O(m) |
| Fruits into baskets | at most 2 types | atMost K | O(n) | O(1) |
| Max consecutive ones III | zeros <= K | atMost K | O(n) | O(1) |

## Complexity calculation

```text
right moves from 0 to n-1 = n moves
left moves from 0 to n-1 = at most n moves
Total = 2n moves
Time = O(n)
```

## Common mistakes

1. Non-contiguous problem par sliding window use karna.
2. Shrink condition ulta likhna.
3. Min window me valid hote hi shrink na karna.
4. Map frequency zero hone par erase na karna.
5. Exact K problems me atMost(K)-atMost(K-1) trick miss karna.

## Interview questions

1. Sliding window identify kaise karte ho?
2. Fixed vs variable window difference kya hai?
3. Longest substring K distinct dry run karo.
4. Minimum window substring needs map explain karo.
5. At most K template likho.
