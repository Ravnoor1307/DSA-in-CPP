/*
 * ══════════════════════════════════════════════════
 *  TASKS — 01_Matrix_Basics
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <vector>
using namespace std;

const int R = 3, C = 4;

/* TASK 1 — flat index of (i,j) (EASY)
   row-major offset = i*C + j. */
int task1_flatIndex(int i, int j) {
    return i * C + j;                 // (2,3) → 11
}

/* TASK 2 — max element (EASY)
   Single pass over all cells. */
int task2_max(int m[R][C]) {
    int mx = m[0][0];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

/* TASK 3 — row with largest sum (MEDIUM)
   Return the row index. */
int task3_bestRow(int m[R][C]) {
    int best = 0, bestSum = -1000000;
    for (int i = 0; i < R; i++) {
        int s = 0;
        for (int j = 0; j < C; j++) s += m[i][j];
        if (s > bestSum) { bestSum = s; best = i; }
    }
    return best;
}

/* TASK 4 — count negatives (MEDIUM) */
int task4_countNeg(int m[R][C]) {
    int c = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (m[i][j] < 0) c++;
    return c;
}

/* TASK 5 — transpose (HARD)
   Return transpose as vector<vector<int>> (C×R). */
vector<vector<int>> task5_transpose(int m[R][C]) {
    vector<vector<int>> t(C, vector<int>(R, 0));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            t[j][i] = m[i][j];
    return t;
}

int main() {
    int m[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};

    cout << "---- TASK 1 ----" << endl;
    cout << "flat index of (2,3) = " << task1_flatIndex(2, 3) << endl;   // 11

    cout << "---- TASK 2 ----" << endl;
    cout << "max = " << task2_max(m) << endl;                          // 12

    cout << "---- TASK 3 ----" << endl;
    cout << "best row = " << task3_bestRow(m) << endl;                 // 2

    cout << "---- TASK 4 ----" << endl;
    int n[R][C] = {{-1, 2, -3, 4}, {5, -6, 7, -8}, {0, 1, 2, 3}};
    cout << "negatives = " << task4_countNeg(n) << endl;               // 4

    cout << "---- TASK 5 ----" << endl;
    auto t = task5_transpose(m);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) cout << t[i][j] << " ";
        cout << endl;
    }
    return 0;
}