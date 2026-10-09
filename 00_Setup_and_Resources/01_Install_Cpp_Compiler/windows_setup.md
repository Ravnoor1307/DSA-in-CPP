

Install C++ Compiler on Windows

# Install C++ Compiler on Windows

## Objective

Install GCC/G++ on Windows and configure it to compile C++17 programs.

## Step 1: Install MSYS2

1. Open [https://www.msys2.org/](https://www.msys2.org/)

2. Download the installer.

3. Install MSYS2 using the default recommended location, preferably `C:\msys64`.

4. Open the **MSYS2 UCRT64** terminal from the Start menu.

## Step 2: Install GCC

Run this command inside the MSYS2 UCRT64 terminal:

```
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

Press Enter and confirm installation when prompted.

## Step 3: Configure PATH

Add this directory to your Windows user PATH:

```
C:\msys64\ucrt64\bin
```

How to add it:

1. Search for **Edit environment variables for your account**.

2. Select `Path`.

3. Click **Edit** and then **New**.

4. Add `C:\msys64\ucrt64\bin`.

5. Save the changes.

Do not replace your existing PATH entries.

## Step 4: Verify Installation

Close and reopen your terminal or VS Code terminal.

Run:

```
g++ --version
```

Then check the compiler path:

```
where.exe g++
```

The compiler should resolve to your MSYS2 UCRT64 installation.

## Step 5: Compile a Test Program

Navigate to the directory containing `compile_and_run.cpp` and run:

```
g++ -std=c++17 -Wall -Wextra -pedantic compile_and_run.cpp -o compile_and_run.exe
```

Execute the program:

```
.\compile_and_run.exe
```

## Troubleshooting

### `g++ is not recognized`

* Verify the PATH entry.

* Confirm that `g++.exe` exists inside `C:\msys64\ucrt64\bin`.

* Restart the terminal after changing PATH.

### Package installation fails

Open the MSYS2 UCRT64 terminal and update the system using the official MSYS2 instructions. Follow any instructions to close and reopen the terminal.

## Completion Checklist

* MSYS2 installed.

* GCC installed.

* PATH configured.

* `g++ --version` works.

* A C++17 program compiles and runs.

