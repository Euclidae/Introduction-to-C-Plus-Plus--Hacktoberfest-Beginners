#include <bits/stdc++.h>
using namespace std;

// Constants for grade validation
const int MIN_GRADE = 0;
const int MAX_GRADE = 100;
const int ROUNDING_THRESHOLD = 38;
const int ROUNDING_DIFFERENCE = 3;

// Function to round the grade according to rules
int roundGrade(int grade) {
    if (grade < ROUNDING_THRESHOLD) {
        return grade;
    }
    
    int nextMultipleOf5 = ((grade + 4) / 5) * 5;
    if (nextMultipleOf5 - grade < ROUNDING_DIFFERENCE) {
        return nextMultipleOf5;
    }
    return grade;
}

// Function to validate input grade
bool isValidGrade(int grade) {
    return grade >= MIN_GRADE && grade <= MAX_GRADE;
}

int main() {
    try {
        int n;
        cout << "Enter the number of grades: ";
        cin >> n;
        
        // Validate number of grades
        if (cin.fail() || n <= 0) {
            throw runtime_error("Invalid number of grades. Please enter a positive integer.");
        }
        
        vector<int> grades;
        grades.reserve(n); // Pre-allocate memory for efficiency
        
        cout << "Enter " << n << " grades (0-100):" << endl;
        
        // Input grades with validation
        for (int i = 0; i < n; ++i) {
            int grade;
            cin >> grade;
            
            if (cin.fail()) {
                throw runtime_error("Invalid input. Please enter numeric grades only.");
            }
            
            if (!isValidGrade(grade)) {
                throw runtime_error("Grade must be between " + to_string(MIN_GRADE) + 
                                  " and " + to_string(MAX_GRADE) + ".");
            }
            
            grades.push_back(grade);
        }
        
        // Process grades
        for (int& grade : grades) {
            grade = roundGrade(grade);
        }
        
        // Output results
        cout << "\nRounded grades:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Student " << (i + 1) << ": " << grades[i];
            if (i < n - 1) {
                cout << endl;
            }
        }
        cout << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
