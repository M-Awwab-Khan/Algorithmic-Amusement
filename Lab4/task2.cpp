#include <iostream>
using namespace std;

class Awwab_Lab4{
    public:
    void bubbleSort(int* arr, int size, bool analyze=false) {
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

        if (analyze) {
            cout << "Number of swaps: " << swaps << endl;
            cout << "Number of comparisions: " << comparisions << endl;
        }
    }

    void print(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "  ";
        }
    }

    int maximizeToys(int* arr, int size, int k) {
        bubbleSort(arr, size);
        int totalCost = 0;
        for (int i = 0; i < size; ++i) {
            if (totalCost + arr[i] <= k) {
                totalCost += arr[i];
            }
            else {return i;}
        }
        return size;
    }
};

int main() {

    int arr[7] = {1, 12, 5, 111, 200, 1000, 10};

    Awwab_Lab4 test;
    cout << "Maximum number of toys: " << test.maximizeToys(arr, 7, 50) << endl;


    return 0;
}
