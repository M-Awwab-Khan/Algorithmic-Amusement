#include <iostream>
using namespace std;


class Matrix {
private:
    int **matrix;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void inputMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "(" << i + 1 << ", " << j + 1 << "): ";
                cin >> matrix[i][j];
            }
            cout << endl;
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overloading + operator for matrix addition
    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw "Error: Matrices not suitable for addition.";
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;
    }

    // Overloading * operator for scalar multiplication
    Matrix operator*(int constant) const {
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.matrix[i][j] = matrix[i][j] * constant;
            }
        }
        return temp;
    }

    // Overloading - operator for matrix subtraction
    Matrix operator-(const Matrix &other) const {
        return *this + (other * -1); // Use + operator to subtract
    }
};

int main(){
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for matrix 1: ";
    cin >> r1 >> c1;

    Matrix mat1(r1, c1);
    mat1.inputMatrix();

    cout << "Matrix:" << endl;
    mat1.display();

    cout << "Enter rows and columns for matrix 2: ";
    cin >> r2 >> c2;

    Matrix mat2(r2, c2);
    mat2.inputMatrix();

    cout << "Matrix:" << endl;
    mat2.display();

    cout << "Addition:" << endl;
    (mat1 + mat2).display();

    return 0;
}
