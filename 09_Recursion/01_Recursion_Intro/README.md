# 01_Recursion_Intro

## Real-world analogy summary

Recursion ko Russian nesting dolls ki tarah samjho. Har doll ke andar chhoti doll hoti hai, jab tak smallest doll na mil jaye. Function bhi same problem ka chhota version call karta hai.

## Definition

```text
Recursion = function jo khud ko call kare
```

## 2 mandatory parts

```text
1. Base Case       -> rukna kahan hai?
2. Recursive Case  -> chhota same problem kya hai?
```

## Call stack visual

```text
fact(3)
  ↓ push
fact(2)
  ↓ push
fact(1) base
  ↑ returns 1
fact(2) returns 2*1
  ↑
fact(3) returns 3*2 = 6
```

## Recursion vs iteration table

| Feature | Iteration | Recursion |
|---|---|---|
| Real-world analogy | cashier loop counter | Russian dolls / assistant chain |
| Control | loop condition | base case |
| Memory | same frame | new call stack frame per call |
| Sum 1..n time | n iterations -> O(n) | n+1 calls -> O(n) |
| Extra space | O(1) | O(n) stack for depth n |
| Best for | simple repetition | trees, backtracking, divide problems |

## Common mistakes

1. Base case bhoolna.
2. Recursive call me problem smaller na banana.
3. Print before call vs after call order confuse karna.
4. Recursion time O(n) bolkar stack space mention na karna.
5. Call stack frame me local variables ki separate copy ignore karna.

## Interview questions

1. Recursion kya hota hai?
2. Base case and recursive case explain karo.
3. Call stack fact(3) ke liye draw karo.
4. Print 1 to n and n to 1 me statement order ka role kya hai?
5. No base case se stack overflow kyun hota hai?
6. Recursion vs iteration compare karo.
