// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

std::vector<Student> students;


double calculate_average(const std::vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void add_student() {
    Student new_student;

    std::cout << "Student name: ";
    std::cin.ignore(); 
    std::getline(std::cin, new_student.name);

    std::cout << "Student ID: ";
    std::cin >> new_student.id;

    int num_scores;
    std::cout << "How many scores? ";
    std::cin >> num_scores;

    for (int i = 1; i <= num_scores; ++i) {
        double score;
        std::cout << "Enter score " << i << ": ";
        std::cin >> score;
        new_student.scores.push_back(score);
    }

    students.push_back(new_student);
    std::cout << "Student \"" << new_student.name << "\" added successfully.\n";
}


void display_all_students() {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << std::left 
              << std::setw(15) << "Name"
              << std::setw(12) << "ID"
              << std::setw(15) << "Scores"
              << std::setw(8)  << "Average" << "\n";
    std::cout << "--------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& student : students) {
        std::string scores_str = "";
        for (size_t i = 0; i < student.scores.size(); ++i) {
            scores_str += std::to_string(static_cast<int>(student.scores[i]));
            if (i < student.scores.size() - 1) {
                scores_str += ", ";
            }
        }

        double avg = calculate_average(student.scores);

        std::cout << std::left 
                  << std::setw(15) << student.name
                  << std::setw(12) << student.id
                  << std::setw(15) << scores_str
                  << std::setw(8)  << avg << "\n";
    }

    std::cout << "--------------------------------------------------\n";
}


void calculate_student_average() {
    int target_id;
    std::cout << "Enter student ID: ";
    std::cin >> target_id;

    for (const auto& student : students) {
        if (student.id == target_id) {
            double avg = calculate_average(student.scores);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << student.name << "'s average score: " << avg << "\n";
            return;
        }
    }

    std::cout << "Error: Student ID " << target_id << " not found.\n";
}

int main() {
    int choice = 0;

    while (choice != 4) {
        std::cout << "\n================================\n";
        std::cout << "   STUDENT RECORD SYSTEM MENU   \n";
        std::cout << "================================\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Display all students\n";
        std::cout << "3. Calculate average score\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
    
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                calculate_student_average();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

