#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Course {
    string name;
    double grade;
    int creditHours;
};

double calculator(const vector<Course>& courses) {
    double totalGrade = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGrade += course.grade * course.creditHours;
        totalCredits += course.creditHours;
    }

    if (totalCredits == 0){
        return 0.0;
    }

    return totalGrade / totalCredits;
}

int main() {
    int numOfCourses;
    cout << "Enter the number of courses: ";
    cin >> numOfCourses;

    vector<Course> semesterCourses;

    for (int i = 0; i < numOfCourses; ++i) {
        Course a;
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin.ignore(); // To flush the newline from previous input
        getline(cin, a.name);

        cout << "Enter grade for " << a.name << " (on 10 scale): ";
        cin >> a.grade;

        cout << "Enter credit hours for " << a.name << ": ";
        cin >> a.creditHours;

        semesterCourses.push_back(a);
    }

    // Calculate SGPA
    double semesterGPA = calculator(semesterCourses);

    // CGPA and Credit Hours before this Semester.
    double previousCGPA;
    int previousCredits;
    cout << "\nEnter your previous CGPA (Type '0' if it's 1st Semester): ";
    cin >> previousCGPA;
    cout << "Enter total completed credit hours before this semester (Type '0' if it's 1st Semester): ";
    cin >> previousCredits;
    
    // Total grade points including previous semesters
    double totalGradePoints = previousCGPA * previousCredits;
    int totalCredits = previousCredits;

    for (const auto& course : semesterCourses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCredits += course.creditHours;
    }

    double finalCGPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n--------- Course Summary ---------\n";
    cout << fixed << setprecision(2);
    for (const auto& course : semesterCourses) {
        cout << "Course: " << course.name
             << " | Grade: " << course.grade
             << " | Credit Hours: " << course.creditHours << '\n';
    }

    cout << "\nSemester GPA: " << semesterGPA;
    cout << "\nFinal CGPA: " << finalCGPA << "\n";

    return 0;
}
