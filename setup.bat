@echo off
setlocal EnableDelayedExpansion
title DSA Course - Main Folder Setup

REM ==========================================================
REM  DSA COURSE - MAIN FOLDER STRUCTURE GENERATOR
REM  Creates 17 main folders in the SAME folder as this file.
REM  Subfolders will be added later by a separate script.
REM ==========================================================

REM Kaam hamesha usi folder me ho jahan ye .bat file rakhi hai
cd /d "%~dp0"

echo.
echo  ============================================
echo     DSA COURSE - CREATING MAIN FOLDERS
echo  ============================================
echo   Location: %CD%
echo.

set /a CREATED=0
set /a SKIPPED=0

REM ---- 17 main folders (exact names, underscores) ----
set "FOLDERS=00_Introduction_to_DSA 01_Fundamentals 02_Maths_for_DSA 03_Array 04_String 05_Matrices 06_Linked_List 07_Stack 08_Queue 09_Deque 10_Binary_Tree 11_Binary_Search_Tree 12_Heap 13_Graph 14_Greedy 15_Dynamic_Programming 16_Number_Theory"

for %%F in (%FOLDERS%) do (
    if exist "%%F\" (
        echo   [SKIP]     %%F   ^(already exists^)
        set /a SKIPPED+=1
    ) else (
        mkdir "%%F" 2>nul
        if exist "%%F\" (
            echo   [CREATED]  %%F
            set /a CREATED+=1
        ) else (
            echo   [ERROR]    %%F   ^(could not create^)
        )
    )
)

echo.
echo  ============================================
echo     Created : !CREATED!
echo     Skipped : !SKIPPED!
echo     Total   : 17 main folders ready
echo  ============================================
echo.
echo  Done!
echo.

REM Folder ko Windows Explorer me open karo
start "" "%CD%"

REM Window turant band na ho isliye pause (chahe to ye line hata dena)
pause
endlocal
