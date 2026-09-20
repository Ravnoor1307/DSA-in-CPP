/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_heap_sort_vs_others_comparison.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorting algorithm choose karna vehicle choose karne jaisa hai: merge sort stable truck, quick sort fast bike, heap sort memory-tight guaranteed jeep.
│
│ VISUAL / DRY RUN:
│ MASTER TABLE:
│
│ Merge sort:
│ - Divide array, merge sorted halves.
│ - Guaranteed O(n log n), but extra O(n) memory.
│
│ Quick sort:
│ - Pivot partition.
│ - Average O(n log n), worst O(n^2) if bad pivots.
│
│ Heap sort:
│ - Build max heap, extract max repeatedly.
│ - Guaranteed O(n log n), in-place O(1) extra memory.
│
│ When heap sort best?
│ - Memory tight.
│ - Worst-case guarantee chahiye.
│ - Stability required nahi hai.

│
│ COMPLEXITY CALCULATION:
│ Heap sort calculation:
│ build heap O(n)
│ n extractions * log n heapify = O(n log n)
│ total = O(n log n)
│
│ Merge sort calculation:
│ levels = log n because n/2^k = 1 -> k=log₂n
│ each level merges n items -> n log n
│
│ Quick sort worst:
│ partitions sizes n-1, n-2, ...
│ total = n+(n-1)+...+1 = n(n+1)/2 -> O(n²)

│ APPROACH COMPARISON TABLE:
│ | Sort | Real-world analogy | Time | Space | Note |
│ | Merge | two sorted queues merge | O(n log n) | O(n) | stable |
│ | Quick | pivot-based queue split | avg O(n log n), worst O(n²) | O(log n) | fast |
│ | Heap | priority desk picks max | O(n log n) | O(1) | guaranteed |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(12) << "Algorithm" << setw(18) << "Time" << setw(15) << "Space" << "Best real-world use\n";
    cout << string(70, '-') << "\n";
    cout << left << setw(12) << "Merge" << setw(18) << "O(n log n)" << setw(15) << "O(n)" << "stable external style sorting\n";
    cout << left << setw(12) << "Quick" << setw(18) << "avg O(n log n)" << setw(15) << "O(log n)" << "fast in practice\n";
    cout << left << setw(12) << "Heap" << setw(18) << "O(n log n)" << setw(15) << "O(1)" << "memory tight + guaranteed\n";
    return 0;
}

/*
OUTPUT:
Algorithm   Time              Space          Best real-world use
----------------------------------------------------------------------
Merge       O(n log n)        O(n)           stable external style sorting
Quick       avg O(n log n)    O(log n)       fast in practice
Heap        O(n log n)        O(1)           memory tight + guaranteed
*/

