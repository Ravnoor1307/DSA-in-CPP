# Compilation and Execution

## Overview

This folder explains how C++ source code is transformed into an executable program and how to compile, run, and troubleshoot C++ programs.

## Files in This Folder

| File                  | Purpose                                                                   |
| --------------------- | ------------------------------------------------------------------------- |
| `notes.md`            | Learn the build pipeline, compiler, linker, execution, and common errors. |
| `compile_commands.md` | Keep common compilation and execution commands as a reference.            |
| `compile_demo.cpp`    | Practice compiling and running a complete C++ program.                    |
| `README.md`           | Track the purpose and learning progress for this topic.                   |

## Learning Objectives

After completing this topic, you should be able to:

* Explain the difference between source code and an executable.

* Describe preprocessing, compilation, assembly, and linking.

* Identify the roles of a compiler and linker.

* Compile a C++ program using `g++`.

* Run an executable from a terminal.

* Recognize compilation, linker, runtime, and logical errors.

* Use basic compiler warning flags.

## Recommended Learning Order

1. Read `notes.md` from beginning to end.

2. Review the commands in `compile_commands.md`.

3. Compile `compile_demo.cpp`.

4. Run the resulting executable.

5. Change the values in the source code and build it again.

6. Intentionally introduce a syntax error, observe the diagnostic, and fix it.

## Practice Checklist

* I understand the difference between compilation and execution.

* I can check whether `g++` is installed.

* I can compile a `.cpp` file from the terminal.

* I can run the generated executable.

* I understand what the `-o` flag does.

* I can explain what the linker does.

* I can distinguish compilation errors from runtime and logical errors.

* I can use `-Wall -Wextra -pedantic` to enable useful diagnostics.

## Completion Criteria

Consider this topic complete when you can independently write, compile, and run a small C++ program without relying on an IDE's automatic build button.
