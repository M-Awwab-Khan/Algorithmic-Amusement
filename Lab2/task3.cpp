#include <iostream>
#include <stdexcept>
using namespace std;

class Vector{
    private:
        int dim;
        int *vec;
    public:
        Vector(int d): dim(d) {
            vec = new int[dim] {};
        }

        Vector(const Vector &other): dim(other.dim) {
            vec = new int[dim] {};
            for (int d = 0; d < dim; ++d) {
                vec[d] = other.vec[d];
            }
        }

        void inputVector() {
            for (int d = 0; d < dim; ++d) {
                cin >> vec[d];
            }
        }

        void display() const {
            cout << "Vector(";
            for (int d = 0; d < dim; ++d) {
                cout << vec[d] << ", ";
            }
            cout << ")" << endl;
        }

        int operator*(const Vector &other) const {
            if (dim != other.dim) {
                throw runtime_error("Error: Vectors must have same dimensions for dot product.");
            }

            int result = 0;
            for (int d = 0; d < dim; ++d) {
                result += vec[d] * other.vec[d];
            }
            return result;
        }

        Vector operator*(int constant) const {
            Vector temp(dim);
            for (int d = 0; d < dim; ++d) {
                temp.vec[d] = vec[d] * constant;
            }
            return temp;
        }

        Vector operator+(const Vector &other) const {
            if (dim != other.dim) {
                throw runtime_error("Error: Vectors must have same dimensions for addition.");
            }

            Vector temp(dim);
            for (int d = 0; d < dim; ++d) {
                temp.vec[d] = vec[d] + other.vec[d];
            }
            return temp;
        }
};


int main() {
    try {
        int dim1, dim2;

        cout << "Enter dimension for vector 1: ";
        cin >> dim1;

        Vector vec1(dim1);
        cout << "Input vector 1:" << endl;
        vec1.inputVector();

        cout << "Vector 1:" << endl;
        vec1.display();

        cout << "Enter dimension for vector 2: ";
        cin >> dim2;

        Vector vec2(dim2);
        cout << "Input vector 2:" << endl;
        vec2.inputVector();

        cout << "Vector 2:" << endl;
        vec2.display();

        cout << "XA + YB for X = 2 and Y = -5" << endl;
        ((vec1 * 2) + (vec2 * -5)).display();

        cout << "Dot product of Vector 1 and Vector 2: ";
        cout << (vec1 * vec2) << endl;

    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "An unknown error occurred." << endl;
    }

    return 0;
}
