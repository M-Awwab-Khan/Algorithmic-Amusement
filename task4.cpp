#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index1 = binarySearch(arr, 0, n - 1, 9);
    int index2 = binarySearch(arr, 0, n - 1, 2);

    cout << "Index of 9: " << index1 << endl;
    cout << "Index of 2: " << index2 << endl;

    return 0;
}
