
# C++ Debugging Checklist

Use this checklist whenever a C++ program fails to compile, crashes, or produces an unexpected result.

## 1. Before Debugging

* Save the latest source code.

* Identify what the program should do.

* Reproduce the problem reliably.

* Record the input and actual output.

* Determine whether the issue happens during compilation, linking, or execution.

## 2. If Compilation Fails

* Read the first relevant error message.

* Check the reported file and line number.

* Inspect the lines immediately before and after the reported location.

* Check semicolons, braces, parentheses, and quotation marks.

* Check variable declarations and spelling.

* Check function declarations and return types.

* Fix one issue at a time.

* Recompile after each meaningful fix.

## 3. If Linking Fails

* Check whether every required function has a definition.

* Verify that all necessary source files are included in the build.

* Check that declarations and definitions match.

* Verify required libraries and linker options.

* Read the unresolved symbol or reference named in the diagnostic.

## 4. If the Program Runs but Gives the Wrong Result

* Verify the input values.

* Print intermediate variable values.

* Check operator precedence and parentheses.

* Check integer versus floating-point division.

* Check loop conditions and boundaries.

* Check array indices and variable initialization.

* Compare actual output with expected output.

* Test normal cases and edge cases.

## 5. If the Program Crashes or Behaves Unexpectedly

* Identify the smallest input that reproduces the problem.

* Check array and container bounds.

* Check pointer validity and object lifetimes.

* Check for invalid arithmetic operations.

* Use a debugger to inspect the call stack and variables.

* Consider using AddressSanitizer and UndefinedBehaviorSanitizer when supported.

* Avoid assuming that a crash's location is necessarily where the underlying bug began.

## 6. Before Marking the Bug as Fixed

* The program compiles successfully.

* Relevant compiler warnings have been reviewed.

* The original failing case now works.

* Other relevant test cases still work.

* Temporary diagnostic output has been removed if unnecessary.

* The code is readable and consistently formatted.

* The root cause and fix are understood.

## Debugging Record

Use this template when documenting a difficult bug.

**Problem:** What went wrong?

**Expected behavior:** What should have happened?

**Actual behavior:** What happened instead?

**Reproduction steps:** What input or steps trigger the problem?

**Root cause:** Why did the problem occur?

**Fix:** What change corrected it?

**Verification:** Which tests confirmed the fix?
