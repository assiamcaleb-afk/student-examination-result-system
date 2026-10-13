# Student Examination Result System (C++)

A beginner-friendly console application demonstrating how arrays can be used to manage student examination results.

## Features
- Stores student names, marks, averages, and grades in arrays.
- Accepts up to 100 students.
- Validates the number of students and marks (0–100).
- Calculates grades and displays a result table.
- Identifies the highest-scoring student.

## Why arrays?
The program uses parallel arrays (`names[]`, `scores[]`, `averages[]`, and `grades[]`). The same index refers to the same student across the arrays. For example, `names[0]` and `scores[0]` belong to the first student. This is more manageable than creating separate variables for each student.

## Grade scale
- A: 80–100
- B: 70–79
- C: 60–69
- D: 50–59
- F: below 50

This is a demonstration scale and can be adjusted to match a school's official grading policy.

## Requirements
A C++ compiler such as GCC / g++ or an IDE that supports C++.

## Compile and run
Open a terminal in this folder and run:

```bash
g++ main.cpp -o student_results
./student_results
```

On Windows using MinGW:

```bash
g++ main.cpp -o student_results.exe
.\student_results.exe
```

## Limitations
This educational version keeps data in memory while the program runs. It does not save results to a database or file, and it uses one examination mark per student.
