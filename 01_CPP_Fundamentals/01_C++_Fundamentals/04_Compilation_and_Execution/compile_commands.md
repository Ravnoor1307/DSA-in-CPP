
# C++ Compilation Commands Cheat Sheet

This file contains common commands for compiling and running C++ programs using `g++`.

## 1. Check Whether the Compiler Is Installed

```
g++ --version
```

If the command is recognized, it displays version information. If it is not recognized, install a C++ compiler toolchain or configure its executable path.

## 2. Compile a Single C++ File

```
g++ hello.cpp -o hello
```

This compiles `hello.cpp` and requests an output executable named `hello`.

## 3. Compile with Warnings

```
g++ -std=c++17 -Wall -Wextra -pedantic hello.cpp -o hello
```

This is a good default for beginner exercises.

## 4. Run the Executable

### Windows PowerShell

```
.\hello.exe
```

### Linux or macOS

```
./hello
```

Use the command appropriate to the environment where you compiled the program.

## 5. Compile and Run a Different File

For a file named `compile_demo.cpp`:

```
g++ -std=c++17 -Wall -Wextra -pedantic compile_demo.cpp -o compile_demo
```

Run it on Windows PowerShell:

```
.\compile_demo.exe
```

Run it on Linux or macOS:

```
./compile_demo
```

## 6. Compile Multiple Source Files

Suppose a project contains:

```
project/
├── main.cpp
└── helpers.cpp
```

Compile both source files together:

```
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp helpers.cpp -o project
```

The source files must contain compatible code, and any declarations and definitions must match.

## 7. Compile Without Linking

To compile one source file into an object file:

```
g++ -std=c++17 -Wall -Wextra -pedantic -c hello.cpp -o hello.o
```

The `-c` option stops before linking.

On Windows toolchains, an object file often uses the `.obj` extension instead of `.o`.

## 8. Build and Run in One Shell Command

On Linux or macOS:

```
g++ -std=c++17 -Wall -Wextra -pedantic hello.cpp -o hello && ./hello
```

On Windows PowerShell:

```
g++ -std=c++17 -Wall -Wextra -pedantic hello.cpp -o hello.exe
if ($LASTEXITCODE -eq 0) { .\hello.exe }
```

These examples run the program only if compilation succeeds.

## 9. Common Problems

| Problem                                           | What to check                                                              |
| ------------------------------------------------- | -------------------------------------------------------------------------- |
| `g++` is not recognized                           | Is a compiler installed, and is its directory on `PATH`?                   |
| Source file not found                             | Are you in the directory containing the `.cpp` file?                       |
| Syntax error                                      | Check the compiler's file name, line number, and diagnostic.               |
| Undefined reference or unresolved external symbol | Check missing definitions, object files, libraries, and linker settings.   |
| Executable not found                              | Did compilation succeed, and did you use the correct output name?          |
| Permission denied                                 | Check file permissions and whether the platform allows executing the file. |
| Program gives the wrong answer                    | Check the algorithm, input, types, and calculations.                       |

## 10. Recommended Beginner Workflow

1. Write the source code in a `.cpp` file.

2. Save the file.

3. Open a terminal in the correct directory.

4. Compile using `g++ -std=c++17 -Wall -Wextra -pedantic`.

5. Read and resolve compiler errors.

6. Review warnings.

7. Run the executable.

8. Compare the output with the expected result.

9. Test additional inputs when applicable.

**Remember:** If compilation fails, fix the build errors before attempting to run the new executable. An older executable might still exist, so make sure you are running the version you intended to build.

