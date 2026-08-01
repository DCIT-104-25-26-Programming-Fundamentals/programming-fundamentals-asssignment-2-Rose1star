// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <cmath>

bool primeNumber(int N) {
    if (N < 2) {
        return false;
    }
    if (N == 2) {
        return true;
    }
    if (N % 2 == 0) {
        return false;
    }

    int limit = static_cast<int>(std::sqrt(N));
    for (int i = 3; i <= limit; i += 2) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int prime;
    std::cout << "Enter a number: ";
    std::cin >> prime;

    if (primeNumber(prime)) {
        std::cout << prime << " is a prime number." << std::endl;
    } else {
        std::cout << prime << " is NOT a prime number." << std::endl;
    }

    return 0;
}

