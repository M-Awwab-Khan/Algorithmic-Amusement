#include <iostream>
using namespace std;

class Awwab_Lab4{
    public:
    void bubbleSort(int* arr, int size) {
        int swaps = 0;
        int comparisions = 0;

        for (int i = 0; i < size - 1; ++i) {
            bool sorted = true;
            for (int j = 0; j < size - i - 1; ++j) {
                comparisions++;
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swaps++;
                    sorted = false;
                }
            }
            if (sorted) break;
        }

        cout << "Number of swaps: " << swaps << endl;
        cout << "Number of comparisions: " << comparisions << endl;
    }

    void print(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "  ";
        }
    }
};

int main() {

    int arr[5] = {1, 5, 2, 3, 4};

    Awwab_Lab4 test;
    test.bubbleSort(arr, 5);
    test.print(arr, 5);

    return 0;
}
