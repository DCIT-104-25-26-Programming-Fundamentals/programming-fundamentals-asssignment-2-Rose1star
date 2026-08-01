// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int n);
void checkFibonacci(long long number);

int main() {
    int terms;
    long long checkNum;

    cout << "=========================================\n";
    cout << "       FIBONACCI SEQUENCE GENERATOR\n";
    cout << "=========================================\n\n";

    cout << "--- PART A: Generate Sequence ---\n";
    cout << "How many terms? ";
    cin >> terms;

    
    if (terms <= 0) {
        cout << "Error: Number of terms must be a positive integer (greater than 0).\n";
    } else {
        printFibonacci(terms);
    }

    cout << "\n-----------------------------------------\n\n";

    
    cout << "--- PART B: Fibonacci Number Checker ---\n";
    cout << "Enter a number to check: ";
    cin >> checkNum;

    checkFibonacci(checkNum);

    return 0;
}


// Part A: Prints the first N terms iteratively
void printFibonacci(int n) {
    long long first = 0, second = 1, next;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << first;
        } else if (i == 2) {
            cout << " " << second;
        } else {
            next = first + second;
            cout << " " << next;
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// Part B: Checks iteratively if a given number is in the sequence
void checkFibonacci(long long number) {
    if (number < 0) {
        cout << number << " is NOT a Fibonacci number.\n";
        return;
    }

    long long first = 0, second = 1;

    // 0 and 1 are valid Fibonacci numbers right away
    if (number == first || number == second) {
        cout << number << " is a Fibonacci number.\n";
        return;
    }

    long long next = first + second;

    // Generate terms until we either reach or pass the requested number
    while (next < number) {
        first = second;
        second = next;
        next = first + second;
    }

    if (next == number) {
        cout << number << " is a Fibonacci number.\n";
    } else {
        cout << number << " is NOT a Fibonacci number.\n";
    }
}

