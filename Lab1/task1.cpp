#include <iostream>
using namespace std;

int *convertMatrixTo1DColumnMajor(int **matrix, int rows, int cols)
{
    int size = rows * cols;
    int *result = new int[size];
    int index = 0;

    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            result[index++] = matrix[i][j];
        }
    }
    return result;
}

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i)
    {
        cout << "Enter values for row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int *flattenedArray = convertMatrixTo1DColumnMajor(matrix, rows, cols);

    cout << "Flattened array (Column Major Order): ";
    for (int i = 0; i < rows * cols; ++i)
    {
        cout << flattenedArray[i] << " ";
    }
    cout << endl;

    delete[] flattenedArray;
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
