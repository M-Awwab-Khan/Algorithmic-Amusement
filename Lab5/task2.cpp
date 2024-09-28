#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Awwab_Lab5{
    public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;

        while (i < leftPart.size() && j < rightPart.size()) {
            if (leftPart[i] <= rightPart[j]) {
                arr[k++] = leftPart[i++];
            } else {
                arr[k++] = rightPart[j++];
            }
        }

        while (i < leftPart.size()) {
            arr[k++] = leftPart[i++];
        }

        while (j < rightPart.size()) {
            arr[k++] = rightPart[j++];
        }
    }

    void nonRecursiveMergeSort(vector<int>& arr) {
        int n = arr.size();
        for (int size = 1; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = min(left + size - 1, n - 1);
                int right = min(left + 2 * size - 1, n - 1);
                if (mid < right) {
                    merge(arr, left, mid, right);
                }
            }
        }
    }
};

int main() {
    Awwab_Lab5 lab;
    vector<int> arr = {34, 7, 23, 32, 5, 62};
    lab.nonRecursiveMergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
