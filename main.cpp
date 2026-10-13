#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 100;

char calculateGrade(double average) {
    if (average >= 80) return 'A';
    if (average >= 70) return 'B';
    if (average >= 60) return 'C';
    if (average >= 50) return 'D';
    return 'F';
}

int main() {
    string names[MAX_STUDENTS];
    double scores[MAX_STUDENTS];
    double averages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];
    int numberOfStudents;

    cout << "====================================\n";
    cout << "   STUDENT EXAMINATION RESULT SYSTEM\n";
    cout << "====================================\n";

    cout << "How many students (1-" << MAX_STUDENTS << ")? ";
    while (!(cin >> numberOfStudents) ||
           numberOfStudents < 1 ||
           numberOfStudents > MAX_STUDENTS) {
        cout << "Enter a whole number from 1 to "
             << MAX_STUDENTS << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nStudent " << i + 1 << " name: ";
        getline(cin, names[i]);

        while (names[i].empty()) {
            cout << "Name cannot be empty. Enter the name again: ";
            getline(cin, names[i]);
        }

        cout << "Examination mark (0-100): ";
        while (!(cin >> scores[i]) ||
               scores[i] < 0 ||
               scores[i] > 100) {
            cout << "Enter a valid mark from 0 to 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        averages[i] = scores[i]; // One examination mark is the average.
        grades[i] = calculateGrade(averages[i]);
    }

    int topStudent = 0;
    for (int i = 1; i < numberOfStudents; i++) {
        if (scores[i] > scores[topStudent]) {
            topStudent = i;
        }
    }

    cout << "\n\n============== RESULTS ==============\n";
    cout << left << setw(25) << "Student"
         << right << setw(10) << "Mark"
         << setw(12) << "Average"
         << setw(8) << "Grade" << '\n';
    cout << string(55, '-') << '\n';

    for (int i = 0; i < numberOfStudents; i++) {
        cout << left << setw(25) << names[i]
             << right << setw(10) << fixed << setprecision(1) << scores[i]
             << setw(12) << averages[i]
             << setw(8) << grades[i] << '\n';
    }

    cout << "\nHighest-scoring student: " << names[topStudent]
         << " (" << fixed << setprecision(1)
         << scores[topStudent] << ")\n";

    cout << "\nGrade scale: A = 80-100, B = 70-79, "
         << "C = 60-69, D = 50-59, F = below 50.\n";
    cout << "Note: This demo uses one examination mark per student.\n";

    return 0;
}
