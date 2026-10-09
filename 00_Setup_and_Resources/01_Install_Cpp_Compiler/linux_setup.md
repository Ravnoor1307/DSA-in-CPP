# Install C++ Compiler on Linux

## Objective

Install GCC/G++ and prepare your Linux environment for C++17 DSA practice.

## Ubuntu or Debian

Update package information:

```bash
sudo apt update
```

Install the compiler and common development tools:

```bash
sudo apt install build-essential gdb
```

Verify the installation:

```bash
g++ --version
gdb --version
```

## Fedora

```bash
sudo dnf install gcc-c++ gdb
```

Verify:

```bash
g++ --version
```

## Arch Linux

```bash
sudo pacman -S --needed gcc gdb
```

Verify:

```bash
g++ --version
```

## Compile a C++17 Program

Navigate to the directory containing your source file:

```bash
cd path/to/your/project
```

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic compile_and_run.cpp -o compile_and_run
```

Run:

```bash
./compile_and_run
```

## Common Problems

### `g++: command not found`

Install the compiler using the command for your Linux distribution.

### Permission denied

Ensure you are running the executable from the correct directory. If necessary, inspect its permissions.

### Compilation errors

Read the first meaningful compiler error and check the reported filename and line number.

## Completion Checklist

* [ ] Compiler installed.
* [ ] Compiler version verified.
* [ ] C++17 program compiled.
* [ ] Executable ran successfully.
