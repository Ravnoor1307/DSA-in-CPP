@echo off
setlocal EnableDelayedExpansion
title 00_Introduction_to_DSA - Subfolder Setup

REM ==========================================================
REM  Ye script 00_Introduction_to_DSA ke andar 43 subfolders
REM  banata hai (2 parts me).
REM  Isko 00_Introduction_to_DSA folder ke ANDAR rakh kar chalao.
REM ==========================================================

cd /d "%~dp0"

echo.
echo  ==================================================
echo    00_Introduction_to_DSA - SUBFOLDERS
echo  ==================================================
echo    Location: %CD%
echo.

set /a CREATED=0
set /a SKIPPED=0

REM ---------- PART 01 : Data Structures Basics (24) ----------
set "P1=Part_01_Data_Structures_Basics"
echo   [PART 1] Data Structures Basics
echo   --------------------------------

set "L1=01_Data 02_Data_Structure 03_Types_of_Data_Structure 04_Primitive_Data_Structure 05_Non_Primitive_Data_Structure 06_Arrays_1D 07_2D_Array 08_Row_Major_Column_Major_Order 09_Drawbacks_of_Array 10_Linked_List 11_Doubly_Linked_List 12_Self_Referential_Structure 13_Creating_Node_of_Singly_Linked_List 14_Implementation_in_Cpp_malloc 15_Stack_LIFO 16_Queue_FIFO 17_Trees 18_Graphs 19_Various_Data_Structures 20_Operations_on_Data_Structures 21_Static_vs_Dynamic_DS 22_Homogeneous_vs_Non_Homogeneous_DS 23_Algorithm 24_Interview_Questions"

for %%F in (%L1%) do (
    if exist "%P1%\%%F\" (
        set /a SKIPPED+=1
    ) else (
        mkdir "%P1%\%%F" 2>nul
        echo      [+] %%F
        set /a CREATED+=1
    )
)

echo.

REM ---------- PART 02 : Complexity Analysis (19) ----------
set "P2=Part_02_Complexity_Analysis"
echo   [PART 2] Complexity Analysis
echo   --------------------------------

set "L2=01_Analyzing_an_Algorithm 02_Complexity_of_an_Algorithm 03_Time_Complexity 04_Categorization_of_Time_Complexity 05_Best_Case_Running_Time 06_Average_Case_Running_Time 07_Worst_Case_Running_Time 08_Binary_Search_log2n_Proof 09_Plot_of_Functions 10_Algorithmic_Complexities 11_Time_Space_Trade_Off 12_Space_Complexity 13_Auxiliary_Space 14_Common_Time_Complexities 15_Asymptotic_Notations 16_Big_Oh_Upper_Bound 17_Big_Omega_Lower_Bound 18_Big_Theta_Tight_Bound 19_Amortized_Analysis"

for %%F in (%L2%) do (
    if exist "%P2%\%%F\" (
        set /a SKIPPED+=1
    ) else (
        mkdir "%P2%\%%F" 2>nul
        echo      [+] %%F
        set /a CREATED+=1
    )
)

echo.
echo  ==================================================
echo     Created : !CREATED!
echo     Skipped : !SKIPPED!   (pehle se maujood the)
echo     Total   : 43 subfolders
echo  ==================================================
echo.
echo  Done!
echo.

start "" "%CD%"
pause
endlocal
