#include <iostream>
#include <vector>

using namespace std;

class Awwab_Lab4{
    public:

    int findMaxIndex(int* arr, int size) {
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] > arr[result]) result = i;
        }
        return result;
    }

    vector<int> pancakeSort(int* arr, int size) {
        vector<int> flips;
        for (int curr_size = size; curr_size > 1; --curr_size) {
            int maxIndex = findMaxIndex(arr, curr_size);

            if (maxIndex != curr_size - 1) {
                if (maxIndex != 0) {
                    reverse(arr, arr + maxIndex + 1);
                    flips.push_back(maxIndex + 1);
                }
                reverse(arr, arr + curr_size);
                flips.push_back(curr_size);
            }
        }
        return flips;
    }

    void print(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

};

int main() {

    Awwab_Lab4 lab;
    int arr[] = {3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    lab.print(arr, size);

    vector<int> flips = lab.pancakeSort(arr, size);

    cout << "Sorted array: ";
    lab.print(arr, size);

    cout << "Flips (k-values): ";
    for (int k : flips) {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}
