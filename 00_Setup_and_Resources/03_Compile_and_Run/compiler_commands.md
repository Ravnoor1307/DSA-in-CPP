# Compile and Run C++ Programs

## Check Compiler Installation

```bash
g++ --version
```

## Compile Using C++17

```bash
g++ -std=c++17 -Wall -Wextra -pedantic compile_and_run.cpp -o compile_and_run
```

## Run on Windows

```powershell
.\compile_and_run.exe
```

## Run on Linux or macOS

```bash
./compile_and_run
```

## Explanation

* `g++`: C++ compiler.
* `-std=c++17`: Enables the C++17 language standard.
* `-Wall -Wextra -pedantic`: Enables useful compiler warnings.
* `-o`: Specifies the output executable's name.

Run these commands from the directory containing `compile_and_run.cpp`.



