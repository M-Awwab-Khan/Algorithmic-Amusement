#include <iostream>
using namespace std;

bool searchMatrix(int **matrix, int m, int n, int target)
{
    int low = 0;
    int high = m * n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target)
        {
            return true;
        }
        else if (midValue < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
    int m = 3, n = 4;
    int **matrix = new int *[m];
    matrix[0] = new int[n]{1, 3, 5, 7};
    matrix[1] = new int[n]{10, 11, 16, 20};
    matrix[2] = new int[n]{23, 30, 34, 60};

    int target = 12;

    if (searchMatrix(matrix, m, n, target))
    {
        cout << "Target found!" << endl;
    }
    else
    {
        cout << "Target not found!" << endl;
    }

    for (int i = 0; i < m; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
