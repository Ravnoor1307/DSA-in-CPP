


<WritingBlock id="73107" variant="document"># Common C++ Setup and Compilation Errors

## 1. `g++ is not recognized`

Cause: The compiler is missing or is not configured in PATH.

Solution:

* Verify the compiler installation.

* Check the PATH configuration.

* Restart the terminal after modifying PATH.

* Run `g++ --version`.

On macOS, use `clang++ --version` if you are using Apple's default compiler.

## 2. `No such file or directory`

Cause: The source filename or working directory is incorrect.

Solution:

Bash

```
pwd
```

On Windows PowerShell:

PowerShell

```
Get-Location
```

List the files in the current directory and verify the source filename.

## 3. `undefined reference to main`

Possible causes:

* Your program has no valid `main()` function.

* You compiled the wrong source file.

* Your build command does not include the file containing `main()`.

Solution: Check the source file and compilation command.

## 4. `expected ';'`

Cause: A semicolon is missing or the syntax immediately before the reported line is incorrect.

Solution: Inspect the reported line and the preceding line.

## 5. `expected '}'`

Cause: A closing brace is missing, or the braces are incorrectly arranged.

Solution: Match every opening `DIL1`.

## 6. `cin` Does Not Read the Expected Input

Possible cause: Mixing `cin >> value` and `getline()` without handling the leftover newline.

Example:

C++

```
int age;
cin >> age;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, name);
```

This example requires:

C++

```
#include <limits>
#include <string>
```

Use `cin.ignore()` appropriately when switching from formatted input to line-based input.

## 7. Program Compiles but Produces Wrong Output

This is often a logic error rather than a setup error.

Check:

* Loop boundaries.

* Conditional statements.

* Integer division.

* Variable initialization.

* Array indexes.

* Input assumptions.

* Edge cases.

## 8. `vector` or `string` Is Not Recognized

Include the required header:

C++

```
#include <vector>
#include <string>
```

## 9. Program Crashes

Possible causes include invalid array access, null pointer access, infinite recursion, or other undefined behavior.

Use a debugger and test with a small input.

## 10. Executable Does Not Run

On Windows PowerShell, a local executable is typically run using:

PowerShell

```
.\program.exe
```

On Linux and macOS:

Bash

```
./program
```

## Recommended Compilation Command

GCC/G++:

Bash

```
g++ -std=c++17 -Wall -Wextra -pedantic program.cpp -o program
```

Clang:

Bash

```
clang++ -std=c++17 -Wall -Wextra -pedantic program.cpp -o program
```

## Debugging Rule

Read the first meaningful compiler error first. Later errors may be consequences of the first mistake.</WritingBlock>
