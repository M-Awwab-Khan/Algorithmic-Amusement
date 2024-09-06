#include <iostream>
#include <iomanip>
using namespace std;

const float creditHrs = 3.0;

void calculateGpa(float **grades, int nStudents, int subjects[])
{
    for (int i = 0; i < nStudents; ++i)
    {
        float total = 0.0;
        float totalCreditHrs = 0.0;

        for (int j = 0; j < subjects[i]; ++j)
        {
            total += (grades[i][j] * creditHrs);
            totalCreditHrs += creditHrs;
        }

        float gpa = total / totalCreditHrs;
        cout << "GPA of student " << i + 1 << ": " << fixed << setprecision(2) << gpa << endl;
    }
}

int main()
{
    int nStudents;
    cout << "Enter number of students: ";
    cin >> nStudents;

    int subjects[nStudents];

    float **grades = new float *[nStudents];

    for (int i = 0; i < nStudents; ++i)
    {
        cout << "Enter number of subjects for student " << i + 1 << ": ";
        cin >> subjects[i];

        grades[i] = new float[subjects[i]];

        for (int j = 0; j < subjects[i]; ++j)
        {
            cout << "Enter GPA for subject " << j + 1 << " for student " << i + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    calculateGpa(grades, nStudents, subjects);

    for (int i = 0; i < nStudents; ++i)
    {
        delete[] grades[i];
    }
    delete[] grades;

    return 0;
}
