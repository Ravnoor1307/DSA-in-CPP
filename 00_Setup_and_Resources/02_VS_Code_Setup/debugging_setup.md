
<WritingBlock id="73106" variant="document"># Debugging C++ in VS Code

## Objective

Learn how to find logical errors using a debugger rather than relying only on print statements.

## Prerequisites

* A working C++ compiler.

* The Microsoft C/C++ extension.

* A configured debugger.

On Windows with MSYS2 UCRT64, install GDB in the UCRT64 terminal:

On Ubuntu or Debian:

Bash

```
sudo apt install gdb
```

On macOS, LLDB is commonly used with the Apple command-line tools.

## Step 1: Create a Debugging Program

Save this as `debug_example.cpp`:

C++

```
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    cout << "Sum = " << sum << '\n';
    return 0;
}
```

## Step 2: Compile with Debug Information

GCC/G++:

Bash

```
g++ -std=c++17 -g -O0 debug_example.cpp -o debug_example
```

Clang:

Bash

```
clang++ -std=c++17 -g -O0 debug_example.cpp -o debug_example
```

The `-g` flag adds debugging information. The `-O0` flag disables optimization to make beginner debugging easier.

## Step 3: Set a Breakpoint

1. Open `debug_example.cpp`.

2. Click beside a line number inside the loop.

3. A breakpoint marker should appear.

4. Open the Run and Debug panel.

5. Select an appropriate C++ debugger configuration for your installed compiler and debugger.

6. Start debugging.

VS Code may prompt you to create a `launch.json` configuration.

## Step 4: Learn the Debugger Controls

* Continue: Resume execution.

* Step Over: Execute the current line.

* Step Into: Enter a called function.

* Step Out: Finish the current function and return to its caller.

* Variables: Inspect current variable values.

* Watch: Track specific expressions.

* Call Stack: Inspect the active function calls.

## Step 5: Debug a Logic Error

Change this line:

C++

```
for (int i = 0; i < 5; i++)
```

to:

C++

```
for (int i = 0; i < 4; i++)
```

Run the program and inspect how the result changes. The loop now omits the final array element.

Restore the correct loop afterward.

## DSA Debugging Checklist

When your solution fails:

1. Reproduce the problem with a small input.

2. Set a breakpoint near the suspected error.

3. Inspect variable values.

4. Step through each iteration.

5. Check loop boundaries and conditions.

6. Test empty, smallest, largest, and duplicate-value cases.

## Completion Checklist

* Compiled with debugging information.

* Set a breakpoint.

* Inspected variable values.

* Stepped through a loop.

* Found and corrected a logic error.</WritingBlock>
