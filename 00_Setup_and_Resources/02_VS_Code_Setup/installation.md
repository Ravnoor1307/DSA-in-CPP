
Install Visual Studio Code

# Install Visual Studio Code

## Objective

Set up Visual Studio Code as the main editor for C++ and DSA practice.

## Step 1: Download VS Code

Visit:

[https://code.visualstudio.com/](https://code.visualstudio.com/)

Download the version for your operating system and complete the installation.

## Step 2: Open Your DSA Project

Open VS Code.

Select:

`File → Open Folder`

Choose your `DSA-Placement-Preparation` directory.

Keep all your DSA topics organized inside this project.

## Step 3: Open the Integrated Terminal

Select:

`Terminal → New Terminal`

Verify your compiler:

Windows:

```
g++ --version
```

Linux:

```
g++ --version
```

macOS:

```
clang++ --version
```

If the command is not recognized, finish the relevant compiler setup guide first.

## Step 4: Create a Test File

Create a file named `test.cpp` and add:

```
#include <iostream>

int main() {
    std::cout << "Hello, DSA!" << '\n';
    return 0;
}
```

Compile it using the terminal and run the executable.

## Step 5: Learn Basic Navigation

Practice these actions:

* Open and close files.

* Create folders and files.

* Search across your project.

* Open the terminal.

* Read compiler errors.

* Format code.

* Use keyboard shortcuts.

Useful shortcuts on Windows/Linux:

| Action          | Shortcut           |
| --------------- | ------------------ |
| Save file       | `Ctrl + S`         |
| Search files    | `Ctrl + P`         |
| Find in file    | `Ctrl + F`         |
| Find in project | `Ctrl + Shift + F` |
| Open terminal   | `Ctrl +` `         |
| Command Palette | `Ctrl + Shift + P` |

On macOS, use `Cmd` for most equivalent shortcuts.

## Completion Checklist

* VS Code installed.

* Project folder opened.

* Terminal working.

* Test file created.

* Test program compiled and executed.
