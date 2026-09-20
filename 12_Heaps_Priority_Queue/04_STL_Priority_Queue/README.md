# 04_STL_Priority_Queue

## Real-world analogy summary

STL priority queue ready-made hospital triage desk hai. Aap `push`, `pop`, `top` use karte ho; internally heap property maintain hoti hai.

## Syntax sheet

```cpp
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;
```

Custom object:

```cpp
struct Compare {
    bool operator()(const T& a, const T& b) const {
        return a.priority < b.priority; // higher priority top
    }
};
priority_queue<T, vector<T>, Compare> pq;
```

## Comparison table

| Structure | Rule | Real-world analogy | push | pop | access |
|---|---|---|---:|---:|---:|
| stack | LIFO | plates | O(1) | O(1) | top O(1) |
| queue | FIFO | ticket line | O(1) | O(1) | front O(1) |
| priority_queue | priority first | emergency room | O(log n) | O(log n) | top O(1) |

## Common mistakes

1. Min heap syntax me `vector<int>` container miss karna.
2. Comparator logic ulta likhna.
3. `top()` ko remove samajhna — remove ke liye `pop()`.
4. priority_queue iterate directly nahi kar sakte; copy bana kar pop print karo.
5. Equal priority tie-breaker define na karna for objects.

## Interview questions

1. STL `priority_queue<int>` default kya hota hai?
2. Min heap priority queue ka syntax likho.
3. Custom comparator pair/object ke liye kaise likhte hain?
4. Queue vs stack vs priority queue difference explain karo.
5. `top`, `push`, `pop` complexities kya hain with calculation?
