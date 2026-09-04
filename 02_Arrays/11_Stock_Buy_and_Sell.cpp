/*
=======================================================================
 THEORY : Stock Buy and Sell
=======================================================================
 1. WHAT IT DOES
    - Given an array of stock prices where prices[i] is the price on
      day i, find the MAXIMUM PROFIT from buying and selling.
    - Two common variants:
      a) One transaction  -- buy once, sell once (most common in exams).
      b) Multiple transactions -- buy/sell as many times as you want.

 2. VARIANT 1: ONE TRANSACTION (buy once, sell once)

    GOAL: Find i < j such that prices[j] - prices[i] is maximised.
    Constraint: you must BUY before you SELL (i < j).

    APPROACH 1 -- Brute Force: try every (buy, sell) pair.
        for i = 0 to n-1:
            for j = i+1 to n-1:
                max_profit = max(max_profit, prices[j] - prices[i])
        Time O(n^2), Space O(1). TLE for n > 10^4.

    APPROACH 2 -- Single Pass (optimal):
        Track two variables as you walk through the array:
          min_price  = the cheapest price seen SO FAR (best day to buy).
          max_profit = best profit seen so far.

        For each day i:
          profit_if_sell_today = prices[i] - min_price
          max_profit = max(max_profit, profit_if_sell_today)
          min_price  = min(min_price, prices[i])

        Time O(n), Space O(1). Works because:
          - You can only sell AFTER buying, so min_price is always from
            an earlier day.
          - At each step you ask: "Is today a better day to sell than
            all previous best options?" and "Is today a better day to
            buy than all previous options?"

    EXAMPLE: prices = {7, 1, 5, 3, 6, 4}
        Day 0: price=7, min_price=7, max_profit=0
        Day 1: price=1, min_price=1, max_profit=0  (price < min_price, update min)
        Day 2: price=5, profit=5-1=4, max_profit=4, min_price=1
        Day 3: price=3, profit=3-1=2, max_profit=4, min_price=1
        Day 4: price=6, profit=6-1=5, max_profit=5, min_price=1
        Day 5: price=4, profit=4-1=3, max_profit=5, min_price=1
        Answer: 5 (buy at 1, sell at 6)

 3. VARIANT 2: MULTIPLE TRANSACTIONS

    GOAL: Maximise profit with unlimited buy/sell pairs.
    Constraint: cannot hold more than one share at a time
                (must sell before buying again).

    APPROACH -- Greedy (capture every upward trend):
        for i = 1 to n-1:
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]

        This works because any overall upward trend from valley to peak
        can be decomposed into consecutive day-to-day gains:
            valley=1 -> peak=6  can be split as:
            (2-1) + (3-2) + (4-3) + (5-4) + (6-5) = 5

        Time O(n), Space O(1).

 4. VARIANT 3: AT MOST K TRANSACTIONS (advanced, not in this file)
    Uses dynamic programming: dp[i][j] = max profit with at most i
    transactions up to day j. O(k*n) time.

 5. COMPLEXITY

    | Variant          | Brute Force | Optimal        |
    |------------------|-------------|----------------|
    | One transaction  | O(n^2)      | O(n), O(1)     |
    | Multiple trans.  | O(n^3)      | O(n), O(1)     |

 6. HOW TO CALCULATE THE COMPLEXITY (5-step method)
    Step A - Input size n = number of days (prices array length).
    Step B - Brute force (one transaction): outer i (n times), inner j
             (i+1..n-1). Count = n(n-1)/2 pairs -> O(n^2).
    Step C - Optimal (one transaction): SINGLE pass. Each element visited
             once with O(1) work (one comparison + one subtraction) -> O(n).
    Step D - Multiple transactions: also a SINGLE pass, O(1) work per day.
             Every upward consecutive step is captured -> O(n).
    Step E - Decision: at n = 10^5, brute = ~10^10 (TLE); optimal = 10^5
             (instant). The greedy single-pass approach is always best.

 7. EDGE CASES
    - Prices strictly decreasing: no profit possible -> return 0.
    - All prices the same: no profit -> return 0.
    - Only one day: cannot buy AND sell -> return 0.
    - Two days: profit = max(0, prices[1] - prices[0]).
    - Overflow: prices can be large; use long long for profit accumulator
      in competitive programming.

 8. WHEN TO USE
    - "Buy once, sell once" -> track min_price, update max_profit.
    - "Buy and sell as many times as you want" -> greedily sum every
      consecutive upward step.
    - "At most k transactions" -> DP O(k*n).
    - "Cooldown period" or "transaction fee" -> DP variants.

 9. COMMON EXAM / INTERVIEW VARIANTS
    - "What if you can make at most 2 transactions?"
    - "What if there is a cooldown of 1 day after selling?"
    - "What if there is a transaction fee?"
    All solvable with DP; the one-transaction version is the foundation.
=======================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------------------------------------------------
// Variant 1: One Transaction -- Brute Force O(n^2)
// ----------------------------------------------------------------
int maxProfitOneBrute(const vector<int>& prices)
{
    int n = prices.size();
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            maxProfit = max(maxProfit, prices[j] - prices[i]);
    return maxProfit;
}

// ----------------------------------------------------------------
// Variant 1: One Transaction -- Optimal O(n) O(1)
// ----------------------------------------------------------------
int maxProfitOne(const vector<int>& prices)
{
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < (int)prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice  = min(minPrice, prices[i]);
    }
    return maxProfit;
}

// ----------------------------------------------------------------
// Variant 2: Multiple Transactions -- Greedy O(n) O(1)
// ----------------------------------------------------------------
int maxProfitMultiple(const vector<int>& prices)
{
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); i++)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return profit;
}

// ----------------------------------------------------------------
int main()
{
    cout << "===== STOCK BUY AND SELL DEMO =====" << endl;

    // Test cases
    vector<vector<int>> tests = {
        {7, 1, 5, 3, 6, 4},
        {7, 6, 4, 3, 1},
        {1, 2, 3, 4, 5},
        {3, 3, 3, 3, 3},
        {10},
        {5, 10},
        {10, 5}
    };

    cout << "\n--- Variant 1: One Transaction (buy once, sell once) ---" << endl;
    for (int t = 0; t < (int)tests.size(); t++)
    {
        const auto& p = tests[t];
        cout << "Prices {";
        for (int i = 0; i < (int)p.size(); i++)
            cout << (i ? ", " : "") << p[i];
        cout << "}" << endl;

        int brute = maxProfitOneBrute(p);
        int optimal = maxProfitOne(p);
        cout << "  Brute  O(n^2): " << brute << endl;
        cout << "  Optimal O(n): " << optimal << endl;
        cout << "  Match: " << (brute == optimal ? "YES" : "NO") << endl;
    }

    cout << "\n--- Variant 2: Multiple Transactions (unlimited) ---" << endl;
    for (int t = 0; t < (int)tests.size(); t++)
    {
        const auto& p = tests[t];
        cout << "Prices {";
        for (int i = 0; i < (int)p.size(); i++)
            cout << (i ? ", " : "") << p[i];
        cout << "}" << endl;
        cout << "  Max profit (multiple): " << maxProfitMultiple(p) << endl;
    }

    // Step-by-step trace for {7, 1, 5, 3, 6, 4}
    cout << "\n--- Step-by-step trace: One Transaction {7,1,5,3,6,4} ---" << endl;
    vector<int> trace = {7, 1, 5, 3, 6, 4};
    int minP = trace[0], maxPr = 0;
    cout << "  Day 0: price=" << trace[0]
         << " min_price=" << minP
         << " max_profit=" << maxPr << endl;
    for (int i = 1; i < (int)trace.size(); i++)
    {
        int oldMin = minP;
        int oldMax = maxPr;
        maxPr = max(maxPr, trace[i] - minP);
        minP  = min(minP, trace[i]);
        cout << "  Day " << i << ": price=" << trace[i]
             << " profit_today=" << trace[i] - oldMin
             << " min_price=" << minP
             << " max_profit=" << maxPr << endl;
    }

    // Step-by-step trace for multiple transactions
    cout << "\n--- Step-by-step trace: Multiple {7,1,5,3,6,4} ---" << endl;
    int total = 0;
    for (int i = 1; i < (int)trace.size(); i++)
    {
        if (trace[i] > trace[i - 1])
        {
            cout << "  Day " << i-1 << "->" << i
                 << ": price " << trace[i-1] << "->" << trace[i]
                 << " profit +" << (trace[i] - trace[i-1]) << endl;
            total += trace[i] - trace[i - 1];
        }
        else
        {
            cout << "  Day " << i-1 << "->" << i
                 << ": price " << trace[i-1] << "->" << trace[i]
                 << " (no trade)" << endl;
        }
    }
    cout << "  Total profit = " << total << endl;

    return 0;
}
