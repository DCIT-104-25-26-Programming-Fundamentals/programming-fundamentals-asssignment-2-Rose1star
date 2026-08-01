// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// Maximum fixed dimension size
const int MAX_SIZE = 10;

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int rows, int cols, int output[MAX_SIZE][MAX_SIZE]);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2);

int main() {
    cout << "=========================================\n";
    cout << "            MATRIX OPERATIONS            \n";
    cout << "=========================================\n\n";

    // -------------------------------------------------------------------------
    // PART A — Transpose a Matrix
    // -------------------------------------------------------------------------
    cout << "--- PART A: Transpose a Matrix ---\n";
    int rA, cA;
    int matA[MAX_SIZE][MAX_SIZE];
    int transA[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    inputMatrix(matA, rA, cA, "Matrix");

    cout << "\nOriginal Matrix:\n";
    printMatrix(matA, rA, cA);

    transposeMatrix(matA, rA, cA, transA);

    cout << "\nTransposed Matrix:\n";
    printMatrix(transA, cA, rA); // Note: rows and cols are swapped for output

    cout << "\n-----------------------------------------\n\n";

    // -------------------------------------------------------------------------
    // PART B — Add Two Matrices
    // -------------------------------------------------------------------------
    cout << "--- PART B: Add Two Matrices ---\n";
    int rB, cB;
    int addA[MAX_SIZE][MAX_SIZE];
    int addB[MAX_SIZE][MAX_SIZE];
    int sumResult[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows for both matrices: ";
    cin >> rB;
    cout << "Enter number of columns for both matrices: ";
    cin >> cB;

    cout << "\n--- Matrix 1 ---\n";
    inputMatrix(addA, rB, cB, "Matrix 1");

    cout << "\n--- Matrix 2 ---\n";
    inputMatrix(addB, rB, cB, "Matrix 2");

    addMatrices(addA, addB, sumResult, rB, cB);

    cout << "\nMatrix Sum:\n";
    printMatrix(sumResult, rB, cB);

    cout << "\n-----------------------------------------\n\n";

    // -------------------------------------------------------------------------
    // PART C — Multiply Two Matrices
    // -------------------------------------------------------------------------
    cout << "--- PART C: Multiply Two Matrices ---\n";
    int rM1, cM1, rM2, cM2;
    int multA[MAX_SIZE][MAX_SIZE];
    int multB[MAX_SIZE][MAX_SIZE];
    int multResult[MAX_SIZE][MAX_SIZE];

    cout << "Enter rows for Matrix A: ";
    cin >> rM1;
    cout << "Enter columns for Matrix A: ";
    cin >> cM1;

    cout << "Enter rows for Matrix B: ";
    cin >> rM2;
    cout << "Enter columns for Matrix B: ";
    cin >> cM2;

    // Check multiplication condition: Columns in A must equal Rows in B
    if (cM1 != rM2) {
        cout << "\nError: Matrix multiplication not possible! "
             << "Columns of A (" << cM1 << ") must equal Rows of B (" << rM2 << ").\n";
    } else {
        cout << "\n--- Matrix A ---\n";
        inputMatrix(multA, rM1, cM1, "Matrix A");

        cout << "\n--- Matrix B ---\n";
        inputMatrix(multB, rM2, cM2, "Matrix B");

        multiplyMatrices(multA, multB, multResult, rM1, cM1, cM2);

        cout << "\nMatrix Product (A x B):\n";
        printMatrix(multResult, rM1, cM2);
    }

    return 0;
}

// -----------------------------------------------------------------------------
// HELPER FUNCTIONS
// -----------------------------------------------------------------------------

// Function to populate a matrix via user input
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix cleanly formatted with setw
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// REQUIRED ASSIGNMENT FUNCTIONS
// -----------------------------------------------------------------------------

// Part A: Transpose a matrix (swapping indices [i][j] to [j][i])
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int rows, int cols, int output[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            output[j][i] = input[i][j];
        }
    }
}

// Part B: Add two matrices element-wise
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Multiply two matrices (A: r1 x c1, B: c1 x c2, Result: r1 x c2)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0; // Initialize cell accumulator
            for (int k = 0; k < c1; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

