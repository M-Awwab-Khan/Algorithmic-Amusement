#include <iostream>
#include <algorithm>
using namespace std;

class MedianFinder
{
private:
    int *arr;
    int size;
    int capacity;

    void resizeArray()
    {
        capacity *= 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    MedianFinder()
    {
        size = 0;
        capacity = 5;
        arr = new int[capacity];
    }

    void addNumber(int value)
    {
        if (size == capacity)
        {
            resizeArray();
        }
        arr[size++] = value;
        sort(arr, arr + size);
    }

    double findMedian()
    {
        if (size % 2 != 0)
        {
            return arr[size / 2];
        }
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }

    ~MedianFinder()
    {
        delete[] arr;
    }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNumber(1);
    medianFinder.addNumber(2);
    cout << medianFinder.findMedian() << endl; // Output: 1.5
    medianFinder.addNumber(3);
    cout << medianFinder.findMedian() << endl; // Output: 2
    return 0;
}
