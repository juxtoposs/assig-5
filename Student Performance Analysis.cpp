#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_STUDENTS = 10;
const int NUM_SUBJECTS = 4;

// Function to calculate average of a row (for each student)
double calculateStudentAverage(int grades[NUM_STUDENTS][NUM_SUBJECTS], int studentIndex) {
    double sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        sum += grades[studentIndex][i];
    }
    return sum / NUM_SUBJECTS;
}

// Function to calculate average for each subject (column)
double calculateSubjectAverage(int grades[NUM_STUDENTS][NUM_SUBJECTS], int subjectIndex) {
    double sum = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        sum += grades[i][subjectIndex];
    }
    return sum / NUM_STUDENTS;
}

// Function to find the highest and lowest grades in each subject
void findMinMax(int grades[NUM_STUDENTS][NUM_SUBJECTS], int subjectIndex, int &minGrade, int &maxGrade) {
    minGrade = 100;
    maxGrade = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (grades[i][subjectIndex] < minGrade) minGrade = grades[i][subjectIndex];
        if (grades[i][subjectIndex] > maxGrade) maxGrade = grades[i][subjectIndex];
    }
}

int main() {
    // Sample data for 10 students and their grades in 4 subjects (Math, Science, English, History)
    int grades[NUM_STUDENTS][NUM_SUBJECTS] = {
        {85, 90, 78, 88},
        {92, 88, 84, 75},
        {70, 80, 85, 90},
        {95, 70, 88, 78},
        {80, 85, 82, 86},
        {88, 92, 90, 80},
        {75, 80, 70, 85},
        {89, 95, 85, 91},
        {84, 77, 80, 88},
        {78, 85, 75, 82}
    };

    cout << "Student | Math | Science | English | History | Average" << endl;
    cout << "---------------------------------------------------------" << endl;

    // Calculate and display the average for each student
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        double studentAverage = calculateStudentAverage(grades, i);
        cout << setw(4) << i + 1 << "    | " << setw(4) << grades[i][0] << "  | " << setw(4) << grades[i][1]
             << "    | " << setw(4) << grades[i][2] << "     | " << setw(4) << grades[i][3]
             << "     | " << setw(5) << fixed << setprecision(2) << studentAverage << endl;
    }

    // Calculate and display the highest and lowest grades for each subject
    const char* subjects[] = {"Math", "Science", "English", "History"};
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        int minGrade, maxGrade;
        findMinMax(grades, i, minGrade, maxGrade);
        cout << "Highest " << subjects[i] << " Grade: " << maxGrade << endl;
        cout << "Lowest " << subjects[i] << " Grade: " << minGrade << endl;
    }

    // Calculate and display the average for each subject
    cout << "\nSubject Averages:" << endl;
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        double subjectAverage = calculateSubjectAverage(grades, i);
        cout << subjects[i] << " Average: " << fixed << setprecision(2) << subjectAverage << endl;
    }

    return 0;
}
