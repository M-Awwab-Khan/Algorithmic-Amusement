#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Awwab_Lab5 {
    public:
    void nonRecursiveQuickSort(vector<int>& arr) {
        stack<int> stack;
        int left = 0;
        int right = arr.size() - 1;

        stack.push(left);
        stack.push(right);

        while (!stack.empty()) {
            right = stack.top(); stack.pop();
            left = stack.top(); stack.pop();

            if (left < right) {
                int pivot = arr[left];
                int i = left;
                int j = right;

                while (i < j) {
                    while (i < j && arr[j] >= pivot) {
                        j--;
                    }
                    while (i < j && arr[i] <= pivot) {
                        i++;
                    }
                    if (i < j) {
                        swap(arr[i], arr[j]);
                    }
                }
                swap(arr[left], arr[i]);

                stack.push(left);
                stack.push(i - 1);

                stack.push(i + 1);
                stack.push(right);
            }
        }
    }
};


int main() {
    Awwab_Lab5 lab;
    vector<int> arr = {34, 7, 23, 32, 5, 62};
    lab.nonRecursiveQuickSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

