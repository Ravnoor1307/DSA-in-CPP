

## 3. `01_Install_Cpp_Compiler/macos_setup.md`

Install C++ Compiler on macOS

# Install C++ Compiler on macOS

## Objective

Install Apple's command-line development tools and compile C++17 programs.

## Step 1: Install Command Line Tools

Open Terminal and run:

```
xcode-select --install
```

Follow the installation prompts.

If the tools are already installed, macOS may report that they are available.

## Step 2: Verify the Compiler

Run:

```
clang++ --version
```

Check that the development tools are configured:

```
xcode-select -p
```

macOS normally provides Clang rather than GCC. Clang supports C++17, so it is suitable for DSA practice.

## Step 3: Compile a Program

Navigate to the folder containing `compile_and_run.cpp`:

```
cd path/to/your/project
```

Compile:

```
clang++ -std=c++17 -Wall -Wextra -pedantic compile_and_run.cpp -o compile_and_run
```

Run:

```
./compile_and_run
```

## Optional: Install GCC

If you specifically need GCC, you can install it through Homebrew:

```
brew install gcc
```

Homebrew's GCC executable may have a version-specific name, such as `g++-15`. Use the actual executable name installed on your system.

## Troubleshooting

### Compiler not found

Install the command-line tools and verify the installation.

### Permission issues

Check that you are in the correct project directory and that the output executable can be run.

## Completion Checklist

* Command-line tools installed.

* Compiler version verified.

* C++17 compilation successful.

* Test program runs successfully.
