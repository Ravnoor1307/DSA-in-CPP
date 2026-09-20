/*
═══════════════════════════════════════════════
 DATA (Data vs Information)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Your school records every student's height, weight and test marks on
 paper. By themselves these numbers mean almost nothing — they are just
 raw facts lying in a register. But when a teacher arranges them,
 computes each student's percentage and decides who passed, those same
 numbers suddenly become useful. This transformation — turning lifeless
 numbers into meaningful facts — is exactly the difference between DATA
 and INFORMATION. Every software application you will write does this
 same job: collect raw facts, process them, and present useful results.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: DATA is raw, unorganized facts such as numbers, text or
   symbols that carry no meaning by themselves. INFORMATION is data that
   has been processed, organized and given meaning — it answers a question
   like "how many passed?" or "what is the average?".
 - key points / properties:
   • Data alone is meaningless; meaning comes only after processing.
   • The same data can produce different information when processed
     differently (one batch can yield average, maximum, or pass %).
   • Information = Data + Processing (meaning).
   • The quality of information depends on the accuracy of the data
     (garbage in → garbage out).
   • A computer stores data in memory/disk and produces information by
     running algorithms.
 - types of data:
   • Raw data  : collected directly from the source, no processing done.
   • Processed data : after sorting, filtering, aggregation or analysis.
   Data hierarchy (smallest unit → biggest collection):
       Bit → Byte → Field → Record → File → Database
 - when to use:
   Use this mindset in every DSA problem: first ask WHAT raw facts you
   have, then ask WHAT information you want, then choose the processing
   steps. This clarity decides which data structure to pick.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Store the collected raw readings in an array.
         WHY: An array keeps the raw facts together so one loop can
         process all of them uniformly. No separate storage needed.
 Step 2: Detect invalid readings (negative values) and skip them.
         WHY: Garbage data destroys information. Filtering protects the
         average and the counts — this is data-cleaning, a real step in
         every data pipeline.
 Step 3: Accumulate sum, count valid readings and count passing ones.
         WHY: Aggregation converts many raw numbers into a few meaningful
         summary facts — the essence of turning data into information.
 Step 4: Divide sum by valid count to get the average.
         WHY: An average is a single informative number that summarizes
         the entire batch. Guard against divide-by-zero when all readings
         are invalid (edge case).
 Step 5: Print the derived facts (valid count, pass count, average,
         accuracy flag).
         WHY: Printing is the presentation layer — the user now sees
         information, not raw numbers.

 VISUAL WALKTHROUGH: (data → information pipeline)

   RAW DATA (no meaning yet)
    ┌────────┐ ┌────────┐ ┌────────┐ ┌────────┐ ┌────────┐
    │ 45.0   │ │ 78.5   │ │ -1.0   │ │ 92.0   │ │  0.0   │
    └────────┘ └────────┘ └────────┘ └────────┘ └────────┘
              │
     (1) FILTER  →  -1.0 rejected (sensor error)
     (2) AGGREGATE → sum, counts
     (3) COMPUTE   → average, pass %, accuracy flag
              │
              ▼
    INFORMATION (meaningful facts)
    ┌───────────────────────────────────────────────┐
    │ total valid = 4  |  pass = 3  |  avg = 53.875 │
    └───────────────────────────────────────────────┘

 DRY RUN: (full trace of the demo program below)
   Input : rawData[5] = {45.0, 78.5, -1.0, 92.0, 0.0}, n = 5
   ints  : sum=0, validCount=0, passCount=0

   STEP A — print raw data loop:
     i=0 → prints "reading[0] = 45 degrees"
     i=1 → prints "reading[1] = 78.5 degrees"
     i=2 → prints "reading[2] = -1 degrees"
     i=3 → prints "reading[3] = 92 degrees"
     i=4 → prints "reading[4] = 0 degrees"

   STEP B — processing loop:
     i=0 → 45.0 not negative → sum=45.0, validCount=1, 45>=33 → passCount=1
     i=1 → 78.5 not negative → sum=123.5, validCount=2, 78.5>=33 → passCount=2
     i=2 → -1.0 is negative  → print "skipping -1 (invalid)" and continue
     i=3 → 92.0 not negative → sum=215.5, validCount=3, 92>=33   → passCount=3
     i=4 → 0.0 not negative → sum=215.5, validCount=4, 0>=33 is FALSE
           (0.0 is a valid reading, just not a passing one)

   STEP C — average = 215.5 / 4 = 53.875 (validCount==0 guard not hit)

   STEP D — prints:  Total valid readings : 4
                      Passing (>= 33.0)   : 3
                      Average of valid data : 53.875
                      Accuracy check        : GOOD   (75% >= 50%)

 TIME COMPLEXITY CALCULATION:
   - Print loop visits all n readings            → n steps
   - Process loop visits all n readings          → n steps; inside each
     iteration: 1 sign check + 1 sum addition +
     1 valid-count increment + 1 threshold check
     + at most 1 pass-count increment            → about 5n steps
   - Average and final prints                    → constant c steps
   - Total ≈ n + 5n + c = 6n + c
 → Time Complexity = O(n)     (single pass over the data, no nesting)

 SPACE COMPLEXITY CALCULATION:
   - Array rawData stores n doubles              → n units of memory
   - Variables sum, validCount, passCount, average, i → 5 constant units
   - No extra array or structure is allocated while processing
   - Total = n + 5
 → Space Complexity = O(n)

 APPROACH COMPARISON: (Data vs Information)
 ┌──────────────────┬────────────────────────────┬─────────────────────────────┐
 │ Aspect           │ DATA                       │ INFORMATION                 │
 ├──────────────────┼────────────────────────────┼─────────────────────────────┤
 │ What it is       │ Raw, unorganized facts     │ Processed, meaningful facts │
 │ Example          │ 45.0, 78.5, -1.0, 92.0     │ pass=3, average=53.875      │
 │ Meaning          │ None by itself             │ Answers a question          │
 │ Source           │ Sensors, forms, registers  │ Produced by algorithms      │
 │ Storage cost     │ Same bytes in memory       │ Same bytes, new insight     │
 │ Computer's job   │ Collect + store            │ Organize + compute + show   │
 └──────────────────┴────────────────────────────┴─────────────────────────────┘
*/

#include <iostream>
using namespace std;

int main()
{
  // raw data: sensor se aaye 5 raw readings (sirf numbers, abhi koi meaning nahi)
  double rawData[5] = {45.0, 78.5, -1.0, 92.0, 0.0};
  int n = 5;

  cout << "=== RAW DATA (sirf numbers, koi meaning nahi) ===\n";
  for (int i = 0; i < n; i++)
  {
    cout << "reading[" << i << "] = " << rawData[i] << " degrees\n";
  }

  // processing: raw data ko information me convert kar rahe hain
  double sum = 0.0;
  int validCount = 0;
  int passCount = 0;
  const double PASS_MARK = 33.0;

  for (int i = 0; i < n; i++)
  {
    if (rawData[i] < 0.0)
    {
      // negative reading = sensor error, ise skip kar do (data cleaning)
      cout << "skipping " << rawData[i] << " (invalid: negative hai)\n";
      continue;
    }
    sum += rawData[i]; // valid reading ko total me add karo
    validCount++;      // valid readings ki count badhao
    if (rawData[i] >= PASS_MARK)
    {
      passCount++; // passing readings ki count badhao
    }
  }

  // edge case: validCount 0 hai to divide by zero ka risk — guard lagao
  double average = (validCount == 0) ? 0.0 : sum / validCount;

  cout << "\n=== PROCESSED INFORMATION (ab data ka matlab hai) ===\n";
  cout << "Total valid readings   : " << validCount << "\n";
  cout << "Passing (>= 33.0)      : " << passCount << "\n";
  cout << "Average of valid data  : " << average << "\n";

  // accuracy flag — ek summary boolean information
  bool good = (validCount > 0) && (passCount * 100 / validCount >= 50);
  cout << "Accuracy check         : " << (good ? "GOOD" : "POOR") << "\n";

  return 0;
}