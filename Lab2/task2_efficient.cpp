#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int **matrix;
    int rows;
    int cols;

    void allocateMemory() {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols] {};
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix &other) {
        if (this != &other) {
            deallocateMemory();

            rows = other.rows;
            cols = other.cols;
            allocateMemory();

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        deallocateMemory();
    }

    void inputMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "(" << i + 1 << ", " << j + 1 << "): ";
                cin >> matrix[i][j];
            }
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

    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Error: Matrices not suitable for addition.");
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;
    }

    Matrix operator*(int constant) const {
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.matrix[i][j] = matrix[i][j] * constant;
            }
        }
        return temp;
    }

    Matrix operator-(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Error: Matrices not suitable for subtraction.");
        }
        return *this + (other * -1);
    }

    Matrix operator*(const Matrix &other) const {
        if (cols != other.rows) {
            throw runtime_error("Error: Matrices not suitable for multiplication.");
        }
        Matrix temp(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                temp.matrix[i][j] = 0; // Initialize to zero
                for (int k = 0; k < cols; ++k) {
                    temp.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return temp;
    }

    Matrix operator~() const {
        Matrix temp(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.matrix[j][i] = matrix[i][j];
            }
        }
        return temp;
    }
};

int main() {
    try {
        int r1, c1, r2, c2;

        cout << "Enter rows and columns for matrix 1: ";
        cin >> r1 >> c1;

        Matrix mat1(r1, c1);
        cout << "Input matrix 1:" << endl;
        mat1.inputMatrix();

        cout << "Matrix 1:" << endl;
        mat1.display();

        cout << "Enter rows and columns for matrix 2: ";
        cin >> r2 >> c2;

        Matrix mat2(r2, c2);
        cout << "Input matrix 2:" << endl;
        mat2.inputMatrix();

        cout << "Matrix 2:" << endl;
        mat2.display();

        cout << "Mat1 + Mat2:" << endl;
        (mat1 + mat2).display();

        cout << "Mat1 - Mat2:" << endl;
        (mat1 - mat2).display();

        cout << "Mat1 x Mat2:" << endl;
        (mat1 * mat2).display();

        cout << "Mat1 Transposed:" << endl;
        (~mat1).display();

        cout << "3 * Mat1:" << endl;
        (mat1 * 3).display();

    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "An unknown error occurred." << endl;
    }

    return 0;
}
