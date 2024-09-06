#include <iostream>
using namespace std;

class Matrix
{
private:
    int **matrix;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new int[cols];
        }

        inputMatrix();
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void inputMatrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "(" << i + 1 << ", " << j + 1 << "): ";
                cin >> matrix[i][j];
            }
            cout << endl;
        }
    }

    bool binarySearch(int target)
    {
        int l = 0;
        int r = rows * cols - 1;

        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int midVal = matrix[mid / cols][mid % cols];

            if (target == midVal)
            {
                return true;
            }
            else if (target > midVal)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }

    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int rows;
    int cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    Matrix mat(rows, cols);

    cout << "Matrix:" << endl;
    mat.display();

    int target;
    cout << "Enter target: ";
    cin >> target;
    if (mat.binarySearch(target))
    {
        cout << "Element " << target << " found in the matrix." << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the matrix." << endl;
    }

    return 0;
}