// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function prototypes
double calculateSum(const vector<double>& numbers);
double calculateAverage(const vector<double>& numbers);
double findMaximum(const vector<double>& numbers);
double findMinimum(const vector<double>& numbers);

int main() {
    int count;

    cout << "=========================================\n";
    cout << "       ARRAY STATISTICS CALCULATOR\n";
    cout << "=========================================\n\n";

    cout << "How many numbers? ";
    cin >> count;

    // Validate that N is a positive integer
    if (count <= 0) {
        cout << "Error: Number of elements must be a positive integer.\n";
        return 1;
    }

    vector<double> numbers(count);

    // Prompt and read each number
    for (int i = 0; i < count; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Compute statistics using dedicated functions
    double sum = calculateSum(numbers);
    double average = calculateAverage(numbers);
    double maximum = findMaximum(numbers);
    double minimum = findMinimum(numbers);

    // Display formatted results
    cout << "\nResults:\n";
    cout << fixed << setprecision(2);
    cout << "Sum:     " << sum << "\n";
    cout << "Average: " << average << "\n";
    cout << "Maximum: " << maximum << "\n";
    cout << "Minimum: " << minimum << "\n";

    return 0;
}

// -----------------------------------------------------------------------------
// FUNCTION DEFINITIONS (Custom loop logic without std library helpers)
// -----------------------------------------------------------------------------

// Calculates the sum of all elements in the vector
double calculateSum(const vector<double>& numbers) {
    double total = 0.0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        total += numbers[i];
    }
    return total;
}

// Calculates the average using calculateSum
double calculateAverage(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    return calculateSum(numbers) / numbers.size();
}

// Finds the maximum element in the vector using a loop
double findMaximum(const vector<double>& numbers) {
    double maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
    }
    return maxVal;
}

// Finds the minimum element in the vector using a loop
double findMinimum(const vector<double>& numbers) {
    double minVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }
    return minVal;
}