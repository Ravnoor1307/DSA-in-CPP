# 07_Matrices

## Module goal

Matrix ko Excel sheet, classroom seating chart, image pixels, ya chess board ki tarah samjho. Screen par matrix **2D grid** dikhta hai, lekin C++ memory me mostly **row-major continuous 1D storage** ki tarah store hota hai. Is module me basics se lekar interview patterns tak complete matrix roadmap cover hai.

```text
2D Grid view:
      c0  c1  c2
r0    1   2   3
r1    4   5   6
r2    7   8   9

C++ row-major flat memory:
[1][2][3][4][5][6][7][8][9]
```

---

## Folder tree

```text
07_Matrices/
├── README.md
├── 01_Matrix_Basics/
│   ├── 01_matrix_memory_theory.cpp
│   ├── 02_matrix_declaration_initialization.cpp
│   ├── 03_matrix_accessing_elements.cpp
│   ├── 04_matrix_traversal_approach1_row_wise.cpp
│   ├── 05_matrix_traversal_approach2_column_wise.cpp
│   ├── 06_row_wise_vs_column_wise_sum.cpp
│   ├── 07_matrix_input_output.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Row_Column_Major/
│   ├── 01_row_major_order_theory.cpp
│   ├── 02_column_major_order_theory.cpp
│   ├── 03_address_calculation_row_major.cpp
│   ├── 04_address_calculation_column_major.cpp
│   ├── README.md
│   └── task.cpp
├── 03_Matrix_Operations/
│   ├── 01_matrix_addition.cpp
│   ├── 02_matrix_subtraction.cpp
│   ├── 03_matrix_multiplication_approach1_naive.cpp
│   ├── 04_matrix_multiplication_result_dims.cpp
│   ├── 05_matrix_transpose.cpp
│   ├── 06_matrix_power.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Special_Matrices/
│   ├── 01_identity_matrix.cpp
│   ├── 02_diagonal_matrix.cpp
│   ├── 03_symmetric_matrix.cpp
│   ├── 04_upper_lower_triangular.cpp
│   ├── 05_scalar_matrix_unit_matrix.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Matrix_Patterns_Traversals/
│   ├── 01_spiral_traversal.cpp
│   ├── 02_boundary_traversal.cpp
│   ├── 03_diagonal_traversal_primary.cpp
│   ├── 04_diagonal_traversal_secondary.cpp
│   ├── 05_zigzag_diagonal_traversal.cpp
│   ├── 06_wave_traversal.cpp
│   ├── README.md
│   └── task.cpp
├── 06_Matrix_Problems_Easy/
│   ├── 01_search_in_matrix_approach1_bruteforce.cpp
│   ├── 02_search_in_matrix_approach2_rowwise_bs.cpp
│   ├── 03_search_in_matrix_approach3_staircase.cpp
│   ├── 04_sum_of_diagonals.cpp
│   ├── 05_row_with_max_ones.cpp
│   ├── README.md
│   └── task.cpp
└── 07_Matrix_Problems_Medium/
    ├── 01_rotate_matrix_90_approach1_extra.cpp
    ├── 02_rotate_matrix_90_approach2_transpose_reverse.cpp
    ├── 03_set_matrix_zeros_approach1_bruteforce.cpp
    ├── 04_set_matrix_zeros_approach2_inplace.cpp
    ├── 05_matrix_multiplication_optimized_order.cpp
    ├── 06_boolean_matrix_row_column_set.cpp
    ├── README.md
    └── task.cpp
```

---

## Formulas sheet

### 1. Matrix access

Real-world seat map me row and column batate hi seat milti hai. Matrix me:

```text
A[i][j] = row i, column j
```

### 2. Row-major address formula

C++ classroom register rows ko continuous memory me row-by-row store karta hai.

```text
Address(A[i][j]) = base + (i * nCols + j) * sizeof(type)
```

Numerical example:

```text
A[3][4], base=1000, target=A[2][1], sizeof(int)=4
offset = i*nCols + j = 2*4 + 1 = 9
byteOffset = 9*4 = 36
address = 1000 + 36 = 1036
```

### 3. Column-major address formula

Column-wise storage building ke columns ko pehle complete karta hai.

```text
Address(A[i][j]) = base + (j * nRows + i) * sizeof(type)
```

Numerical example:

```text
A[3][4], base=1000, target=A[2][1], sizeof(int)=4
offset = j*nRows + i = 1*3 + 2 = 5
byteOffset = 5*4 = 20
address = 1000 + 20 = 1020
```

### 4. Basic operations

```text
Addition:       C[i][j] = A[i][j] + B[i][j]
Subtraction:    C[i][j] = A[i][j] - B[i][j]
Multiplication: C[i][j] = Σ A[i][k] * B[k][j]
Transpose:      T[j][i] = A[i][j]
```

### 5. Matrix multiplication dimensions

```text
A(m × n) × B(n × p) = C(m × p)
```

Inner dimensions must match:

```text
(m × n)(n × p)
     └── same ──┘
```

### 6. Special matrix conditions

```text
Identity:       A[i][j] = 1 if i==j else 0
Diagonal:       A[i][j] = 0 if i!=j
Symmetric:      A[i][j] = A[j][i]
Upper:          A[i][j] = 0 for i > j
Lower:          A[i][j] = 0 for i < j
Scalar:         A[i][i] = k for all i, off-diagonal 0
Unit matrix:    scalar matrix with k=1
```

### 7. Traversal patterns

```text
Primary diagonal:   i == j
Secondary diagonal: i + j == n - 1
Spiral traversal:   top, bottom, left, right boundaries
Zigzag diagonal:    diagonal id = row + col
Wave traversal:     even col top→bottom, odd col bottom→top
```

### 8. Medium tricks

```text
Rotate 90 clockwise extra:   R[j][n-1-i] = A[i][j]
Rotate 90 in-place:          transpose -> reverse every row
Set Matrix Zeroes O(1):      first row and first column as markers
Boolean matrix row/col set:  rowMark[i] || colMark[j]
Matrix chain cost:           dims[i] * dims[k+1] * dims[j+1]
```

---

## Row-major vs column-major master table

| Feature | Row-major | Column-major |
|---|---|---|
| Real-world analogy | Notebook row-by-row writing | Building column-by-column listing |
| Flat storage for `{{16,20},{30,50}}` | `[16,20,30,50]` | `[16,30,20,50]` |
| Formula | `base + (i*nCols + j)*sizeof` | `base + (j*nRows + i)*sizeof` |
| First completed unit | row | column |
| C++ behavior | default layout | not default for C++ arrays |
| Cache-friendly traversal in C++ | row-wise | usually no |

---

## Matrix operation comparison table

| Topic | Real-world analogy | Condition | Loop count / calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Direct access | find exact seat | valid i,j | fixed address arithmetic | O(1) | O(1) |
| Row-wise traversal | attendance row-by-row | any matrix | R*C visits | O(R*C) | O(1) direct print |
| Column-wise traversal | lift visits column flats | any matrix | C*R visits | O(R*C) | O(1) direct print |
| Addition | merge sales sheets | same dimensions | R*C additions | O(R*C) | O(R*C) |
| Subtraction | monthly difference table | same dimensions | R*C subtractions | O(R*C) | O(R*C) |
| Multiplication naive | quantity × price | A cols = B rows | m*p*n multiply-adds | O(m*n*p) | O(m*p) |
| Transpose | Excel rows become columns | any matrix | R*C assignments | O(R*C) | O(R*C) |
| Square transpose | mirror across diagonal | square matrix | n(n-1)/2 swaps | O(n²) | O(1) |
| Matrix power repeated | graph path count | square matrix | k multiplications * n³ | O(k*n³) | O(n²) |
| Spiral traversal | mall cleaner route | any matrix | every cell once | O(R*C) | O(R*C) output |
| Boundary traversal | fence walk | any matrix | 2R+2C-4 border cells | O(R+C) | O(R+C) output |
| Staircase search | sorted building search | rows and cols sorted | at most R+C moves | O(R+C) | O(1) |
| Row-wise binary search | sorted shelves | each row sorted | R*log₂C | O(R log C) | O(1) |
| Rotate 90 extra | photo rotate | square matrix | n² assignments | O(n²) | O(n²) |
| Rotate 90 in-place | memory-limited photo rotate | square matrix | transpose swaps + row reverse | O(n²) | O(1) |
| Set Matrix Zeroes brute | spreadsheet cleanup | any matrix | n² zeros * 2n clear | O(n³) square | O(n²) |
| Set Matrix Zeroes in-place | sticky-note markers | any matrix | constant scans of R*C | O(R*C) | O(1) |

---

## Section-wise roadmap

### 01_Matrix_Basics

Starts from classroom/Excel grid analogy. Covers:

- 2D grid and row-major memory layout.
- `int A[2][2] = {{16,20},{30,50}}` notes example.
- `A[i][j] = row i, column j` access.
- Row-wise and column-wise traversal.
- Cache performance note.
- Row-wise and column-wise sums.
- Input/output with nested loops.

### 02_Row_Column_Major

Exam-favorite address calculation section:

- Row-major flat storage `[16,20,30,50]`.
- Column-major flat storage `[16,30,20,50]`.
- Row-major address full numerical calculation.
- Column-major address full numerical calculation.

### 03_Matrix_Operations

Core operations:

- Matrix addition and subtraction.
- Naive matrix multiplication with 3 loops.
- Dimension rule `(m×n)(n×p)=m×p`.
- Transpose and square in-place transpose.
- Matrix power using repeated multiplication.

### 04_Special_Matrices

Pattern-based matrix types:

- Identity matrix and `I×A=A` property.
- Diagonal matrix with O(n) compact storage trick.
- Symmetric matrix mirror-pair check.
- Upper/lower triangular matrices.
- Scalar and unit matrix.

### 05_Matrix_Patterns_Traversals

Interview traversal patterns:

- Spiral traversal with 4 boundaries.
- Boundary traversal.
- Primary and secondary diagonals.
- Zigzag diagonal traversal.
- Wave traversal column-wise up-down.

### 06_Matrix_Problems_Easy

Easy interview problems:

- Matrix search brute force.
- Row-wise binary search.
- Staircase search from top-right.
- Sum of diagonals.
- Row with max ones.

### 07_Matrix_Problems_Medium

Medium interview problems:

- Rotate matrix 90 using extra matrix.
- Rotate matrix 90 using transpose + reverse.
- Set Matrix Zeroes brute force.
- Set Matrix Zeroes in-place with first row/column markers.
- Matrix multiplication optimized order as DP preview.
- Boolean matrix row/column set.

---

## Complexity proof notes

### Nested loop proof

Real-world Excel sheet me agar R rows and C columns hain, every cell visit karne ke liye:

```text
outer loop = R times
inner loop = C times for each row
total visits = R * C
Time = O(R*C)
```

For square matrix:

```text
R = C = n
total visits = n*n = n²
Time = O(n²)
```

### Binary search log proof

Sorted row search me every step half elements discard karta hai:

```text
C / 2^k = 1
C = 2^k
k = log₂C
```

One row takes `O(log C)`, R rows take:

```text
R * log₂C = O(R log C)
```

### Matrix multiplication proof

For `A(m*n)` and `B(n*p)`:

```text
result cells = m*p
work per cell = n multiplications/additions
total work = m*p*n
Time = O(m*n*p)
```

For square matrices:

```text
m=n=p
Time = O(n³)
```

### Staircase search proof

Top-right search me every step:

- left move: one column eliminated
- down move: one row eliminated

```text
max row moves = R
max column moves = C
total moves <= R + C
Time = O(R+C)
```

### Rotate 90 in-place proof

```text
Transpose swaps = n(n-1)/2
Reverse row swaps = n * (n/2)
Total swaps ≈ n²/2 + n²/2 = n²
Time = O(n²), Space = O(1)
```

### Set Matrix Zeroes in-place proof

```text
first row scan = C
first col scan = R
marker scan = (R-1)(C-1)
update scan = (R-1)(C-1)
final row/col update <= R+C
Total dominated by R*C
Time = O(R*C), Space = O(1)
```

---

## Common mistakes checklist

1. `A[i][j]` me row/column order confuse karna.
2. Row-major address formula me `nRows` use karna instead of `nCols`.
3. Column-major formula me `nCols` use karna instead of `nRows`.
4. Matrix multiplication condition wrong check karna; correct: A columns == B rows.
5. Result dimensions `(m×n)(n×p)=m×p` bhoolna.
6. Transpose me `T[j][i] = A[i][j]` instead of same indices use karna.
7. In-place transpose non-square matrix par apply karna.
8. Spiral traversal me boundaries update after each side na karna.
9. Boundary traversal me corners duplicate print karna.
10. Secondary diagonal formula `j=n-i` likhna; correct `j=n-1-i`.
11. Staircase search directions reverse karna.
12. Diagonal sum me odd n center double count karna.
13. Rotate clockwise me transpose ke baad columns reverse kar dena; clockwise ke liye rows reverse hoti hain.
14. Set Matrix Zeroes me original zeros and newly-created zeros mix karna.
15. First row/column marker flags ignore karna.
16. Boolean matrix problem me direct mutation se cascading 1s create karna.

---

## Interview question bank

1. Matrix memory layout explain karo.
2. C++ row-major order ka visual banao.
3. `A[2][1]` ka row-major address calculate karo.
4. Row-major and column-major order compare karo.
5. Row-wise traversal cache friendly kyun hota hai?
6. Matrix addition/subtraction kab possible hai?
7. Matrix multiplication ka dimension rule kya hai?
8. 2x2 matrix multiplication dry run karo.
9. Transpose kya hota hai?
10. Square matrix transpose in-place kaise karoge?
11. Identity matrix ki property `I×A=A` explain karo.
12. Diagonal matrix O(n) space me kaise store karoge?
13. Symmetric matrix ka optimized check kya hai?
14. Upper and lower triangular matrices me difference kya hai?
15. Spiral traversal boundaries explain karo.
16. Boundary traversal me corners duplicate kaise avoid karoge?
17. Primary and secondary diagonal conditions kya hain?
18. Zigzag diagonal traversal me `row+col` ka role kya hai?
19. Wave traversal ka dry run do.
20. Search in matrix brute force approach explain karo.
21. Row-wise binary search complexity prove karo.
22. Staircase search top-right se kaise kaam karta hai?
23. Diagonal sum me center double count kaise avoid karte hain?
24. Row with max ones O(R+C) approach explain karo.
25. Rotate matrix 90 extra-space approach explain karo.
26. Rotate matrix 90 transpose + reverse trick dry run karo.
27. Set Matrix Zeroes O(1) space approach explain karo.
28. Matrix multiplication order optimize kyun karna padta hai?
29. Boolean matrix row-column set me marker arrays kyun use karte hain?
30. Any matrix problem solve karte time first 3 checks kya karoge? dimensions, constraints, and mutation safety.

---

## How to study this module

1. `01_Matrix_Basics` se grid, indexing, and traversal solid karo.
2. `02_Row_Column_Major` ke address formulas manually 5 examples par solve karo.
3. `03_Matrix_Operations` me multiplication dry run khud copy me banao.
4. `04_Special_Matrices` me each condition ko if-statement form me yaad karo.
5. `05_Matrix_Patterns_Traversals` ke paths arrows ke saath draw karo.
6. `06_Matrix_Problems_Easy` me search approaches compare karo.
7. `07_Matrix_Problems_Medium` me in-place tricks repeat karo until memory ho jaye.
8. Har subfolder ka `task.cpp` pehle khud solve karo, phir lesson solution files se compare karo.
