# DATA (Data vs Information)

- **Data** is raw, unorganized facts (like a sensor value `45.0`) that carry no meaning by themselves.
- **Information** is data that has been processed and organized so it answers a question (like `average = 53.875` or `pass = 3`).
- The transformation pipeline is: **collect raw data → filter → aggregate/compute → present information**.
- Data quality rules everything: garbage data in → garbage information out, so validation is a mandatory step.
- In DSA, always separate "what raw facts I store" from "what information I need" — that decides your data structure choice.

**Real-world analogy:** A pile of loose exam answer-sheets is *data*. The teacher who marks them, totals the scores, and writes "PASS/FAIL" on each roll number is producing *information*. Same sheets, same numbers — but after processing they mean something.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concept of Data vs Information + a working demo (sensor raw data → filtered average/pass report). Compile & run to see the transformation. |
| `task.cpp` | 6 problems (EASY → HARD): print raw data, even/odd counts, max/min, pass/fail report, filter invalid sensor data, Celsius→Fahrenheit danger report. Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, common mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// Collect raw data
double raw[5] = {45.0, 78.5, -1.0, 92.0, 0.0};

// Filter + aggregate (data -> information)
double sum = 0; int valid = 0;
for (int i = 0; i < 5; i++) {
    if (raw[i] < 0) continue;   // invalid, skip
    sum += raw[i];
    valid++;
}
double average = (valid == 0) ? 0.0 : sum / valid;   // divide-by-zero guard

// Present information
cout << "average = " << average << "\n";
```

## Complexity comparison

| Operation | Steps performed | Complexity |
|-----------|-----------------|------------|
| Print raw data loop | n iterations of print, each constant work → n steps | O(n) |
| Process/filter loop | n iterations × (sign check + add + count) ≈ 5n steps | O(n) |
| Average computation | 1 division + 1 guard check → constant | O(1) |
| Total time | n + 5n + c ≈ 6n + c | O(n) |
| Total space | array of n + 5 scalar vars → n + 5 units | O(n) |

## ⚠️ Common mistakes

- Printing raw data and calling it "information" — without processing there is no information.
- Forgetting to filter invalid values (negative marks, `>`100 percentages) before computing averages.
- Integer division: `sum / n` where both are `int` truncates → always cast to `double` first.
- Divide-by-zero on an empty/all-invalid dataset — check `valid == 0` before dividing.
- Changing display precision and blaming "wrong data" — understand raw vs processed separately.

## Interview Q&A

- **Q: What is the difference between data and information?** A: Data is raw, meaningless facts; information is processed data that answers a question.
- **Q: Why does data quality matter?** A: Garbage-in-garbage-out — bad data produces misleading information.
- **Q: Can the same data give different information?** A: Yes, different processing (average vs maximum vs pass %) on the same batch yields different facts.
- **Q: Where does data live inside a computer?** A: In memory (RAM) during processing and on disk for permanent storage.
- **Q: What is the data hierarchy?** A: Bit → Byte → Field → Record → File → Database, from smallest unit to biggest collection.