# 14_Interview_Patterns

## Module goal

Interview problems random nahi hote. Mostly woh known patterns ke variations hote hain. Ye folder final interview revision sheet hai: question ke keywords dekhkar pattern identify karo, template yaad karo, complexity calculate karo, then code.

```text
Question -> signal identify -> pattern choose -> template apply -> dry run -> complexity
```

Real-world analogy: airport route board. Agar destination aur signal samajh aa gaya, correct gate mil jata hai.

---

## Folder tree

```text
14_Interview_Patterns/
├── README.md
├── 01_Patterns_Master_Index/
│   ├── 01_all_patterns_overview_theory.cpp
│   ├── 02_how_to_identify_pattern.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Two_Pointers_Consolidated/
│   ├── 01_pattern_recap_theory.cpp
│   ├── 02_container_with_most_water.cpp
│   ├── 03_three_sum_approach1_bruteforce.cpp
│   ├── 04_three_sum_approach2_sort_two_ptr.cpp
│   ├── 05_trapping_rainwater_two_ptr_recap.cpp
│   ├── 06_linked_list_cycle_fast_slow_recap.cpp
│   ├── README.md
│   └── task.cpp
├── 03_Sliding_Window_Consolidated/
│   ├── 01_pattern_recap_theory.cpp
│   ├── 02_longest_substring_k_distinct.cpp
│   ├── 03_min_window_substring_concept.cpp
│   ├── 04_fruits_into_baskets.cpp
│   ├── 05_max_consecutive_ones_iii.cpp
│   ├── 06_pattern_template_summary.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Prefix_Sum_Consolidated/
│   ├── 01_pattern_recap_theory.cpp
│   ├── 02_subarray_sum_equals_k_hashmap.cpp
│   ├── 03_product_of_array_except_self.cpp
│   ├── 04_range_sum_query_immutable.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Fast_Slow_Pointers/
│   ├── 01_floyd_cycle_recap_theory.cpp
│   ├── 02_find_duplicate_number.cpp
│   ├── 03_happy_number.cpp
│   ├── 04_middle_revisited_palindrome_combo.cpp
│   ├── README.md
│   └── task.cpp
├── 06_Merge_Intervals/
│   ├── 01_intervals_intro_theory.cpp
│   ├── 02_merge_intervals_approach1_bruteforce.cpp
│   ├── 03_merge_intervals_approach2_sort.cpp
│   ├── 04_insert_interval.cpp
│   ├── 05_non_overlapping_intervals_remove.cpp
│   ├── 06_meeting_rooms_check.cpp
│   ├── README.md
│   └── task.cpp
├── 07_Cyclic_Sort/
│   ├── 01_cyclic_sort_intuition_theory.cpp
│   ├── 02_cyclic_sort_implementation.cpp
│   ├── 03_missing_number_cyclic.cpp
│   ├── 04_find_all_duplicates_cyclic.cpp
│   ├── 05_find_disappeared_numbers.cpp
│   ├── 06_first_missing_positive.cpp
│   ├── README.md
│   └── task.cpp
├── 08_Top_K_Elements_Heap/
│   ├── 01_top_k_pattern_theory.cpp
│   ├── 02_k_closest_points_to_origin.cpp
│   ├── 03_top_k_frequent_words.cpp
│   ├── 04_kth_largest_stream_design.cpp
│   ├── README.md
│   └── task.cpp
├── 09_Backtracking_Pattern/
│   ├── 01_backtracking_intro_theory.cpp
│   ├── 02_generate_subsets_backtracking.cpp
│   ├── 03_generate_permutations_backtracking.cpp
│   ├── 04_combination_sum.cpp
│   ├── 05_word_search_grid.cpp
│   ├── 06_n_queens_concept.cpp
│   ├── 07_backtracking_vs_recursion_vs_dp.cpp
│   ├── README.md
│   └── task.cpp
├── 10_Greedy_Pattern/
│   ├── 01_greedy_intro_theory.cpp
│   ├── 02_activity_selection.cpp
│   ├── 03_min_platforms_needed.cpp
│   ├── 04_jump_game_approach1_bruteforce.cpp
│   ├── 05_jump_game_approach2_greedy.cpp
│   ├── 06_candy_distribution_concept.cpp
│   ├── README.md
│   └── task.cpp
├── 11_Dynamic_Programming_Intro/
│   ├── 01_what_is_dp_theory.cpp
│   ├── 02_fibonacci_memoization_approach.cpp
│   ├── 03_fibonacci_tabulation_approach.cpp
│   ├── 04_fibonacci_space_optimized.cpp
│   ├── 05_climbing_stairs_3_ways.cpp
│   ├── 06_house_robber.cpp
│   ├── 07_coin_change_min_coins.cpp
│   ├── 08_longest_common_subsequence_concept.cpp
│   ├── 09_0_1_knapsack_concept.cpp
│   ├── 10_dp_problem_solving_framework.cpp
│   ├── README.md
│   └── task.cpp
└── 12_Complexity_Interview_Questions/
    ├── 01_analyze_this_code_1.cpp
    ├── 02_analyze_this_code_2.cpp
    ├── 03_common_mistakes_in_complexity.cpp
    ├── README.md
    └── task.cpp
```

---

## Mega pattern recognition table

| # | Pattern | Kab use karna? | Key signal words | Pehle kahan seekha | Core template |
|---:|---|---|---|---|---|
| 1 | Two Pointers | pair search, reverse, palindrome, sorted data | sorted, pair, ends, palindrome | Arrays, Linked List | `l=0, r=n-1` |
| 2 | Sliding Window | contiguous subarray/substring | longest, shortest, at most K, window | Arrays, Strings | expand right, shrink left |
| 3 | Prefix Sum | range sum, exact subarray sum | range query, sum equals k | Arrays, Hashing | `prefix += nums[i]` |
| 4 | Fast-Slow | cycle/middle/duplicate sequence | cycle, middle, linked list | Linked List | `slow+=1, fast+=2` |
| 5 | Merge Intervals | timeline overlap | intervals, meetings, schedule | New pattern | sort by start/end |
| 6 | Cyclic Sort | 1..n missing/duplicate | missing number, duplicate, disappeared | New pattern | swap to correct index |
| 7 | Top K Heap | kth/top/closest/frequent | kth largest, top k, closest, frequent | Heaps | heap size k |
| 8 | Backtracking | all possibilities | all subsets, permutations, combinations | Recursion | choose-explore-undo |
| 9 | Greedy | local choice can be proven safe | maximum activities, minimum jumps | New pattern | sort/pick local best |
| 10 | DP | repeated states + optimal result | ways, min/max, overlapping | Recursion | memo/tabulation |

---

## Decision flowchart

```text
Question asks sorted pair / reverse / palindrome?
    -> Two Pointers

Question asks contiguous subarray or substring?
    -> Sliding Window if window condition monotonic
    -> Prefix Sum if exact sum / negative values / many range queries

Question asks cycle or middle in linked list / sequence?
    -> Fast-Slow Pointers

Question has meetings / intervals / timeline overlap?
    -> Merge Intervals

Question array contains numbers 1..n or 0..n and asks missing/duplicate?
    -> Cyclic Sort

Question asks kth / top-k / closest / frequent / stream rank?
    -> Heap / Priority Queue

Question asks all subsets/permutations/combinations/valid boards?
    -> Backtracking

Question asks local best scheduling/reachability and proof possible?
    -> Greedy

Question has repeated recursive states and asks count/min/max/best?
    -> Dynamic Programming
```

---

## Template sheet

### 1. Two Pointers

```cpp
int l = 0, r = n - 1;
while (l < r) {
    int value = calculate(l, r);
    if (condition_small) l++;
    else r--;
}
```

Complexity:

```text
left moves at most n times, right moves at most n times
Total <= 2n -> O(n)
Space O(1)
```

---

### 2. Sliding Window

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    add(nums[right]);
    while (window_invalid) {
        remove(nums[left]);
        left++;
    }
    update_answer(left, right);
}
```

Complexity:

```text
right moves n times
left moves at most n times
Total pointer moves <= 2n -> O(n)
```

---

### 3. Prefix Sum

```cpp
prefix[0] = 0;
for (int i = 0; i < n; i++) {
    prefix[i+1] = prefix[i] + nums[i];
}
rangeSum(l,r) = prefix[r+1] - prefix[l];
```

Prefix + HashMap:

```cpp
freq[0] = 1;
for (int x : nums) {
    sum += x;
    count += freq[sum-k];
    freq[sum]++;
}
```

---

### 4. Fast-Slow

```cpp
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
}
```

Proof:

```text
Inside cycle fast gains 1 step per iteration.
Cycle length C, so max C iterations me gap 0 -> meet.
```

---

### 5. Merge Intervals

```cpp
sort(intervals.begin(), intervals.end());
for (auto cur : intervals) {
    if (ans.empty() || cur[0] > ans.back()[1]) ans.push_back(cur);
    else ans.back()[1] = max(ans.back()[1], cur[1]);
}
```

---

### 6. Cyclic Sort

```cpp
int i = 0;
while (i < n) {
    int correct = nums[i] - 1;
    if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
    else i++;
}
```

Complexity:

```text
Each swap places at least one value on correct seat.
Swaps <= n, scan <= n -> O(n)
Space O(1)
```

---

### 7. Top K Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int x : nums) {
    minHeap.push(x);
    if (minHeap.size() > k) minHeap.pop();
}
return minHeap.top(); // kth largest
```

Complexity:

```text
n elements, heap size k
push/pop O(log k)
Total O(n log k)
Space O(k)
```

---

### 8. Backtracking

```cpp
void solve(state) {
    if (base) { store_answer(); return; }
    for (choice : choices) {
        choose(choice);
        solve(next_state);
        undo(choice);
    }
}
```

Mantra:

```text
CHOOSE -> EXPLORE -> UNDO
```

---

### 9. Greedy

```text
1. Sort by useful key.
2. Pick local best.
3. Prove choice is safe.
4. Scan and build answer.
```

Warning:

```text
Greedy without proof is dangerous.
Example coins [1,3,4], amount 6:
greedy 4+1+1 = 3 coins, optimal 3+3 = 2 coins.
```

---

### 10. Dynamic Programming

```cpp
int solve(state) {
    if (base) return base_answer;
    if (memo[state] != unknown) return memo[state];
    return memo[state] = best_of_transitions;
}
```

DP framework:

```text
1. Recursion state
2. Overlapping subproblems
3. Memoization
4. Tabulation
5. Space optimization
```

Complexity:

```text
Time = number of states * transition work per state
Space = number of states for memo/table
```

---

## Master complexity table

| Pattern | Typical time | Typical space | Calculation |
|---|---:|---:|---|
| Two Pointers | O(n) | O(1) | two pointers move <= 2n |
| Sliding Window | O(n) | O(k)/O(1) | left + right moves <= 2n |
| Prefix Sum | O(n), query O(1) | O(n) | build n additions |
| Fast-Slow | O(n) | O(1) | fast/slow traverse list/sequence |
| Merge Intervals | O(n log n) | O(n) | sort n log n + scan n |
| Cyclic Sort | O(n) | O(1) | each swap fixes one seat |
| Top K Heap | O(n log k) | O(k) | n operations on heap size k |
| Backtracking subsets | O(n*2^n) | O(n)+output | 2 choices for n items |
| Backtracking permutations | O(n*n!) | O(n)+output | n! arrangements, copy length n |
| Greedy sort-based | O(n log n) | O(1) | sort + scan |
| DP 1D | O(states*transition) | O(states) | state count times choices |
| DP 2D | O(n*m) | O(n*m) | table cells `(n+1)*(m+1)` |
| Binary search | O(log n) | O(1) | `n/2^k=1 -> k=log₂n` |

---

## Pattern-by-problem mapping

| Problem | Pattern | Key signal |
|---|---|---|
| Container With Most Water | Two Pointers | two bars, max area, ends |
| 3Sum | Sort + Two Pointers | triplets sum zero |
| Trapping Rainwater | Two Pointers | left/right boundary |
| Linked List Cycle | Fast-Slow | cycle detection |
| Longest Substring K Distinct | Sliding Window | longest contiguous substring |
| Minimum Window Substring | Sliding Window + HashMap | minimum covering substring |
| Fruits Into Baskets | Sliding Window at most K | at most 2 distinct |
| Max Consecutive Ones III | Sliding Window | flip at most k zeros |
| Subarray Sum Equals K | Prefix Sum + HashMap | exact sum count |
| Product Except Self | Prefix/Suffix | left and right products |
| Range Sum Query | Prefix Sum | many immutable range queries |
| Find Duplicate Number | Fast-Slow | array as linked list |
| Happy Number | Fast-Slow | cycle in generated sequence |
| Merge Intervals | Intervals | overlap timeline |
| Insert Interval | Intervals | add new interval and merge |
| Non-overlapping Intervals | Greedy + Intervals | remove overlaps |
| Meeting Rooms | Intervals | schedule conflict |
| Missing Number | Cyclic Sort | numbers 0..n |
| Find Duplicates | Cyclic Sort | numbers 1..n duplicates |
| First Missing Positive | Cyclic Sort | smallest positive missing |
| K Closest Points | Top-K Heap | closest k by distance |
| Top K Frequent Words | HashMap + Heap | frequency ranking |
| Kth Largest Stream | Heap Design | live kth largest |
| Subsets | Backtracking | all subsets |
| Permutations | Backtracking | all arrangements |
| Combination Sum | Backtracking | choices with reuse |
| Word Search | Backtracking + Grid | path with visited undo |
| N-Queens | Backtracking | safe board placements |
| Activity Selection | Greedy | max non-overlapping activities |
| Min Platforms | Greedy + Two Pointers | timeline overlap count |
| Jump Game | Greedy | farthest reachable |
| Candy Distribution | Greedy two-pass | neighbor constraints |
| Fibonacci | DP | repeated recursion calls |
| Climbing Stairs | DP | ways recurrence |
| House Robber | DP | choose loot/skip |
| Coin Change | DP | min coins states |
| LCS | 2D DP | two strings subsequence |
| 0/1 Knapsack | 2D DP | take/skip with capacity |

---

## Common mistakes checklist

1. Pattern identify kiye bina code start karna.
2. Sorted condition absent ho to opposite-end two pointers apply karna.
3. Sliding window non-contiguous problem par use karna.
4. Prefix hashmap me `freq[0]=1` bhoolna.
5. Fast-slow loop condition unsafe likhna.
6. Merge intervals me sort by start miss karna.
7. Cyclic sort duplicate guard miss karna.
8. Heap top-k me heap size k maintain na karna.
9. Backtracking me undo step bhoolna.
10. Greedy proof ke bina local choice assume karna.
11. DP me state define kiye bina table banana.
12. Complexity answer without calculation bolna.
13. Log proof skip karna: `n/2^k = 1 -> k = log₂n`.
14. Recursion stack space ignore karna.
15. Output size exponential hone par mention na karna.

---

## Interview rapid revision questions

1. Given a problem, first pattern signal kaise identify karoge?
2. Two pointers and sliding window difference kya hai?
3. Prefix sum exact subarray sum k me hashmap kyun chahiye?
4. Floyd cycle detection ka proof do.
5. Merge intervals sort by start kyun enough hai?
6. Cyclic sort ka signal kya hota hai?
7. kth largest ke liye min heap of size k kyun?
8. Backtracking mantra kya hai?
9. Greedy kab safe hota hai?
10. DP identify karne ke two signs kya hain?
11. Memoization vs tabulation difference kya hai?
12. DP complexity `states * transition` se kaise calculate karte hain?
13. O(n log n) sorting + O(n) scan total O(n log n) kyun?
14. O(2n) ko O(n) kyun simplify karte hain?
15. Binary search O(log n) derive karo.

---

## Final study plan

1. `01_Patterns_Master_Index` ko interview se pehle revise karo.
2. Har consolidated folder ke `README.md` se signal + template yaad karo.
3. Har `task.cpp` pehle khud solve karo.
4. Approach files me brute vs optimized comparison dekho.
5. Complexity section ke snippets daily drill karo.
6. Actual interview me: brute force bolo, pattern identify karo, optimize karo, dry run karo, complexity calculate karo.
