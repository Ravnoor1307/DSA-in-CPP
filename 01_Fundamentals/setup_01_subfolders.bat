@echo off
setlocal EnableDelayedExpansion
title 01_Fundamentals - Subfolder Setup

REM ==========================================================
REM  Ye script 01_Fundamentals ke andar 46 subfolders banata
REM  hai (3 parts me).
REM  Isko 01_Fundamentals folder ke ANDAR rakh kar chalao.
REM  Dobara chalane se kuch nahi bigadta (idempotent hai).
REM ==========================================================

cd /d "%~dp0"

echo.
echo  ==================================================
echo    01_Fundamentals - SUBFOLDERS
echo  ==================================================
echo    Location: %CD%
echo.

set /a CREATED=0
set /a SKIPPED=0

REM ---------- PART 1 : C++ Basics (DSA ki Foundation) ----------
set "P1=Part_01_Cpp_Basics"
echo   [PART 1] C++ Basics (DSA ki Foundation)
echo   --------------------------------

set "L1=01_Variables_and_Data_Types 02_Input_Output 03_Operators 04_Conditional_Statements 05_Loops 06_Patterns_using_Loops 07_Functions 08_Function_Overloading 09_Scope_and_Memory 10_Arrays_1D 11_2D_Arrays 12_Strings 13_string_Class 14_Pointers 15_Pointers_with_Arrays 16_References 17_Dynamic_Memory_Allocation 18_Structures 19_Recursion_Basics"

for %%F in (%L1%) do (
   if exist "%P1%\%%F" (
      set /a SKIPPED+=1
      echo      [skip] %%F
   ) else (
      mkdir "%P1%\%%F" 2>nul
      set /a CREATED+=1
      echo      [ ok ] %%F
   )
)
echo.
REM ---------- PART 2 : OOPs (Object Oriented Programming) ----------
set "P2=Part_02_OOPs"
echo   [PART 2] OOPs (Object Oriented Programming)
echo   --------------------------------

set "L2=20_Classes_and_Objects 21_Access_Modifiers 22_Constructors 23_Destructors 24_Encapsulation 25_Inheritance 26_Polymorphism 27_Abstraction 28_Static_Members_and_this_Pointer 29_Friend_Functions"

for %%F in (%L2%) do (
   if exist "%P2%\%%F" (
      set /a SKIPPED+=1
      echo      [skip] %%F
   ) else (
      mkdir "%P2%\%%F" 2>nul
      set /a CREATED+=1
      echo      [ ok ] %%F
   )
)
echo.
REM ---------- PART 3 : STL (Standard Template Library) ----------
set "P3=Part_03_STL"
echo   [PART 3] STL (Standard Template Library)
echo   --------------------------------

set "L3=30_STL_Introduction 31_Vector 32_2D_Vector 33_Pair 34_Iterators 35_List 36_Stack_STL 37_Queue_STL 38_Deque 39_Priority_Queue 40_Set 41_Unordered_Set 42_Map 43_Unordered_Map 44_STL_Algorithms 45_Custom_Comparator 46_Bit_Manipulation"

for %%F in (%L3%) do (
   if exist "%P3%\%%F" (
      set /a SKIPPED+=1
      echo      [skip] %%F
   ) else (
      mkdir "%P3%\%%F" 2>nul
      set /a CREATED+=1
      echo      [ ok ] %%F
   )
)
echo.
echo  ==================================================
echo    Created: !CREATED!   Skipped: !SKIPPED!
echo    Total  : 46 subfolders
echo  ==================================================
echo.
echo   Done!
echo.
start "" "%CD%"
pause
